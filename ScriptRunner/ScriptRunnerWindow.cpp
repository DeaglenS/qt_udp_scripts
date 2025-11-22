#include "ScriptRunnerWindow.h"

#include "CanvasWidget.h"
#include "ScriptCanvas.h"
#include "CanvasState.h"
#include "IScriptTransport.h"
#include "UdpScriptTransport.h"
#include "ProfileManager.h"

#include <QPlainTextEdit>
#include <QScriptEngine>
#include <QScriptValue>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QAction>
#include <QComboBox>
#include <QSignalBlocker>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcRunnerUi, "script.ui.runner")
#include <QStatusBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QSplitter>
#include <QHostAddress>
#include <QScriptValue>
#include <QColor>
#include <QScriptContext>

ScriptRunnerWindow::ScriptRunnerWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_scriptView(nullptr)
    , m_logView(nullptr)
    , m_editorHostEdit(nullptr)
    , m_editorPortSpin(nullptr)
    , m_localPortSpin(nullptr)
    , m_udpStatusLabel(nullptr)
    , m_profileCombo(nullptr)
    , m_requestButton(nullptr)
    , m_executeButton(nullptr)
    , m_canvas(nullptr)
    , m_canvasState(new CanvasState(this))
    , m_transport(new UdpScriptTransport(this))
    , m_profileManager(new ProfileManager(this))
    , m_canvasApi(new ScriptCanvas(m_canvasState, this))
{
    createUi();

    // Transport emits high level events so the window stays thin.
    connect(m_transport, &IScriptTransport::scriptReceived,
            this, &ScriptRunnerWindow::handleScriptReceived);
    connect(m_transport, &IScriptTransport::statusMessage,
            this, &ScriptRunnerWindow::handleClientStatusMessage);

    QScriptValue canvasObject = m_engine.newQObject(m_canvasApi);
    m_engine.globalObject().setProperty("canvas", canvasObject);

    // Provide a tiny Qt namespace for scripts so they can reuse color helpers.
    QScriptValue qtObject = m_engine.newObject();
    QScriptValue rgbaFunction = m_engine.newFunction([](QScriptContext *context, QScriptEngine *engine) -> QScriptValue {
        Q_UNUSED(engine);
        if (context->argumentCount() >= 3) {
            const qreal r = context->argument(0).toNumber();
            const qreal g = context->argument(1).toNumber();
            const qreal b = context->argument(2).toNumber();
            const qreal a = context->argumentCount() >= 4 ? context->argument(3).toNumber() : 1.0;
            QColor color;
            color.setRgbF(qBound(0.0, r, 1.0), qBound(0.0, g, 1.0), qBound(0.0, b, 1.0), qBound(0.0, a, 1.0));
            return engine->toScriptValue(color);
        }
        return engine->undefinedValue();
    });
    qtObject.setProperty("rgba", rgbaFunction);

    QScriptValue colorFunction = m_engine.newFunction([](QScriptContext *context, QScriptEngine *engine) -> QScriptValue {
        if (context->argumentCount() >= 1) {
            const QString colorStr = context->argument(0).toString();
            QColor color(colorStr);
            if (color.isValid()) {
                return engine->toScriptValue(color);
            }
        }
        return engine->undefinedValue();
    });
    qtObject.setProperty("color", colorFunction);
    m_engine.globalObject().setProperty("Qt", qtObject);

    connect(m_canvasApi, &ScriptCanvas::message,
            this, &ScriptRunnerWindow::handleScriptPrint);
}

void ScriptRunnerWindow::createUi()
{
    auto *central = new QWidget(this);
    auto *vLayout = new QVBoxLayout(central);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);

    auto *splitter = new QSplitter(Qt::Horizontal, central);

    m_canvas = new CanvasWidget(splitter);
    m_canvas->setCanvasState(m_canvasState);

    auto *rightWidget = new QWidget(splitter);
    auto *rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->setContentsMargins(4, 4, 4, 4);

    rightLayout->addWidget(new QLabel(tr("Received script:"), rightWidget));
    m_scriptView = new QPlainTextEdit(rightWidget);
    m_scriptView->setReadOnly(true);
    rightLayout->addWidget(m_scriptView, 1);

    rightLayout->addWidget(new QLabel(tr("Execution log:"), rightWidget));
    m_logView = new QPlainTextEdit(rightWidget);
    m_logView->setReadOnly(true);
    rightLayout->addWidget(m_logView, 1);

    splitter->addWidget(m_canvas);
    splitter->addWidget(rightWidget);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);

    vLayout->addWidget(splitter, 1);

    auto *bottom = new QWidget(central);
    auto *bottomLayout = new QHBoxLayout(bottom);
    bottomLayout->setContentsMargins(4, 4, 4, 4);

    bottomLayout->addWidget(new QLabel(tr("Editor host:"), bottom));
    m_editorHostEdit = new QLineEdit(bottom);
    m_editorHostEdit->setText(QStringLiteral("127.0.0.1"));
    bottomLayout->addWidget(m_editorHostEdit);

    bottomLayout->addWidget(new QLabel(tr("Editor port:"), bottom));
    m_editorPortSpin = new QSpinBox(bottom);
    m_editorPortSpin->setRange(1, 65535);
    m_editorPortSpin->setValue(45454);
    bottomLayout->addWidget(m_editorPortSpin);

    bottomLayout->addSpacing(12);
    bottomLayout->addWidget(new QLabel(tr("Profile:"), bottom));
    m_profileCombo = new QComboBox(bottom);
    bottomLayout->addWidget(m_profileCombo);

    bottomLayout->addSpacing(12);
    bottomLayout->addWidget(new QLabel(tr("Local UDP port:"), bottom));
    m_localPortSpin = new QSpinBox(bottom);
    m_localPortSpin->setRange(1, 65535);
    m_localPortSpin->setValue(45455);
    bottomLayout->addWidget(m_localPortSpin);

    m_requestButton = new QPushButton(tr("Request script"), bottom);
    bottomLayout->addWidget(m_requestButton);

    m_executeButton = new QPushButton(tr("Execute script"), bottom);
    bottomLayout->addWidget(m_executeButton);

    m_udpStatusLabel = new QLabel(tr("UDP: not bound"), bottom);
    bottomLayout->addWidget(m_udpStatusLabel);

    vLayout->addWidget(bottom);

    setCentralWidget(central);

    auto *tb = addToolBar(tr("Actions"));
    QAction *clearCanvasAct = tb->addAction(tr("Clear canvas"));
    connect(clearCanvasAct, &QAction::triggered, [this]() {
        m_canvasApi->clear();
        logMessage(tr("Canvas cleared"));
    });

    QAction *undoCanvasAct = m_canvasState->undoStack()->createUndoAction(this, tr("Undo Canvas"));
    QAction *redoCanvasAct = m_canvasState->undoStack()->createRedoAction(this, tr("Redo Canvas"));
    tb->addAction(undoCanvasAct);
    tb->addAction(redoCanvasAct);
    addAction(undoCanvasAct);
    addAction(redoCanvasAct);

    connect(m_requestButton, &QPushButton::clicked,
            this, &ScriptRunnerWindow::requestScript);

    connect(m_executeButton, &QPushButton::clicked,
            this, &ScriptRunnerWindow::executeCurrentScript);

    connect(m_localPortSpin, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &ScriptRunnerWindow::rebindUdp);
    connect(m_profileCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ScriptRunnerWindow::onProfileChanged);

    statusBar()->showMessage(tr("Ready"));
    setWindowTitle(tr("Script Runner"));

    loadProfiles();
}

void ScriptRunnerWindow::requestScript()
{
    const QString hostStr = m_editorHostEdit->text().trimmed();
    const quint16 editorPort = static_cast<quint16>(m_editorPortSpin->value());

    if (hostStr.isEmpty()) {
        logMessage(tr("Editor host is empty."));
        qCWarning(lcRunnerUi) << "Editor host is empty";
        return;
    }

    QHostAddress editorAddress(hostStr);
    if (editorAddress.isNull()) {
        logMessage(tr("Invalid host: %1").arg(hostStr));
        qCWarning(lcRunnerUi) << "Invalid editor host" << hostStr;
        return;
    }

    // Fire-and-forget request. Editor replies with the full script content.
    TransportEndpoint endpoint { editorAddress, editorPort };
    qCInfo(lcRunnerUi) << "Requesting script from" << editorAddress << editorPort;
    m_transport->requestScript(endpoint);
}

void ScriptRunnerWindow::executeCurrentScript()
{
    const QString code = m_scriptView->toPlainText();
    if (code.trimmed().isEmpty()) {
        logMessage(tr("No script loaded."));
        return;
    }
    // Manual execution path so QA can tweak scripts before running them.
    executeScript(code);
}

void ScriptRunnerWindow::rebindUdp()
{
    const quint16 port = static_cast<quint16>(m_localPortSpin->value());
    // Runner listens for scripts on whichever port the active profile specifies.
    m_transport->bind(port);
}

void ScriptRunnerWindow::handleScriptReceived(const QByteArray &scriptCode, const TransportEndpoint &sender)
{
    qCInfo(lcRunnerUi) << "Script payload received from" << sender.address << sender.port << "bytes" << scriptCode.size();
    const QString code = QString::fromUtf8(scriptCode);
    m_scriptView->setPlainText(code);
    // Runner auto-executes so a single click in the editor refreshes the canvas.
    executeScript(code);
}

void ScriptRunnerWindow::handleClientStatusMessage(const QString &message)
{
    m_udpStatusLabel->setText(message);
    logMessage(message);
}

void ScriptRunnerWindow::executeScript(const QString &code)
{
    m_logView->clear();
    m_canvasApi->clear();

    // Each evaluation gets its own virtual file name for better stack traces.
    QScriptValue result = m_engine.evaluate(code, QStringLiteral("udp-script.qs"));
    Q_UNUSED(result);

    if (m_engine.hasUncaughtException()) {
        const int line = m_engine.uncaughtExceptionLineNumber();
        const QString msg = m_engine.uncaughtException().toString();
        logMessage(tr("Script error at line %1: %2").arg(line).arg(msg));
        qCWarning(lcRunnerUi) << "Script error at line" << line << ":" << msg;
    } else {
        logMessage(tr("Script executed successfully."));
        qCInfo(lcRunnerUi) << "Script executed successfully";
    }

}

void ScriptRunnerWindow::logMessage(const QString &msg)
{
    qCInfo(lcRunnerUi) << msg;
    m_logView->appendPlainText(msg);
    statusBar()->showMessage(msg, 3000);
}

void ScriptRunnerWindow::loadProfiles()
{
    m_profiles = m_profileManager->profiles();
    m_profileCombo->clear();
    for (const NetworkProfile &profile : m_profiles) {
        m_profileCombo->addItem(profile.name);
    }

    if (!m_profiles.isEmpty()) {
        m_profileCombo->setCurrentIndex(0);
        applyProfile(m_profiles.first());
        qCInfo(lcRunnerUi) << "Loaded" << m_profiles.size() << "profiles";
    } else {
        rebindUdp();
    }
}

void ScriptRunnerWindow::applyProfile(const NetworkProfile &profile)
{
    {
        QSignalBlocker blocker(m_editorHostEdit);
        m_editorHostEdit->setText(profile.editorHost);
    }
    {
        QSignalBlocker blocker(m_editorPortSpin);
        m_editorPortSpin->setValue(profile.editorPort);
    }
    {
        QSignalBlocker blocker(m_localPortSpin);
        m_localPortSpin->setValue(profile.runnerPort);
    }

    // Profiles drive both the remote editor endpoint and our local bind port.
    rebindUdp();
}

void ScriptRunnerWindow::onProfileChanged(int index)
{
    if (index < 0 || index >= m_profiles.size())
        return;

    applyProfile(m_profiles.at(index));
}

void ScriptRunnerWindow::handleScriptPrint(const QString &message)
{
    // Mirror console.log behavior to help authors debug scripts.
    logMessage(tr("Script print: %1").arg(message));
}

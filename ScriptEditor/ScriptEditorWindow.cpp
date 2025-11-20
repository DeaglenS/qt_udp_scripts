#include "ScriptEditorWindow.h"

#include "ScriptDocument.h"
#include "ScriptEditorController.h"
#include "IScriptTransport.h"
#include "UdpScriptTransport.h"
#include "ProfileManager.h"

#include <QPlainTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QToolBar>
#include <QComboBox>
#include <QSignalBlocker>
#include <QFileDialog>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QHostAddress>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <QAction>
#include <QKeySequence>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcEditorUi, "script.ui.editor")

ScriptEditorWindow::ScriptEditorWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_editor(nullptr)
    , m_currentFileEdit(nullptr)
    , m_localPortSpin(nullptr)
    , m_udpStatusLabel(nullptr)
    , m_transport(new UdpScriptTransport(this))
    , m_document(new ScriptDocument(this))
    , m_editorController(nullptr)
    , m_targetAddressEdit(nullptr)
    , m_targetPortSpin(nullptr)
    , m_profileCombo(nullptr)
    , m_profileManager(new ProfileManager(this))
{
    createUi();

    // Keep transport + UI loosely coupled using signals so we can swap transports.
    connect(m_transport, &IScriptTransport::scriptRequested,
            this, &ScriptEditorWindow::handleScriptRequest);
    connect(m_transport, &IScriptTransport::statusMessage,
            this, &ScriptEditorWindow::handleServerStatusMessage);

    connect(m_document, &ScriptDocument::filePathChanged, [this](const QString &path) {
        m_currentFileEdit->setText(QDir::toNativeSeparators(path));
        m_currentFilePath = path;
        updateWindowTitle();
    });

    m_editorController = new ScriptEditorController(m_document, m_editor, this);

    loadProfiles();
}

void ScriptEditorWindow::createUi()
{
    auto *central = new QWidget(this);
    auto *vLayout = new QVBoxLayout(central);
    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);

    m_editor = new QPlainTextEdit(central);
    m_editor->setPlainText("\n");
    vLayout->addWidget(m_editor, 1);

    auto *bottom = new QWidget(central);
    auto *bottomLayout = new QHBoxLayout(bottom);
    bottomLayout->setContentsMargins(4, 4, 4, 4);

    bottomLayout->addWidget(new QLabel(tr("Current file:"), bottom));
    m_currentFileEdit = new QLineEdit(bottom);
    m_currentFileEdit->setReadOnly(true);
    bottomLayout->addWidget(m_currentFileEdit, 1);

    bottomLayout->addSpacing(16);
    bottomLayout->addWidget(new QLabel(tr("Listen UDP port:"), bottom));
    m_localPortSpin = new QSpinBox(bottom);
    m_localPortSpin->setRange(1, 65535);
    m_localPortSpin->setValue(45454);
    bottomLayout->addWidget(m_localPortSpin);

    auto *bindButton = new QPushButton(tr("Bind"), bottom);
    bottomLayout->addWidget(bindButton);

    m_udpStatusLabel = new QLabel(tr("UDP: not bound"), bottom);
    bottomLayout->addWidget(m_udpStatusLabel);

    bottomLayout->addSpacing(16);
    bottomLayout->addWidget(new QLabel(tr("Target IP:"), bottom));
    m_targetAddressEdit = new QLineEdit(bottom);
    m_targetAddressEdit->setText(QStringLiteral("127.0.0.1"));
    bottomLayout->addWidget(m_targetAddressEdit);

    bottomLayout->addWidget(new QLabel(tr("Target port:"), bottom));
    m_targetPortSpin = new QSpinBox(bottom);
    m_targetPortSpin->setRange(1, 65535);
    m_targetPortSpin->setValue(45455);
    bottomLayout->addWidget(m_targetPortSpin);

    bottomLayout->addSpacing(12);
    bottomLayout->addWidget(new QLabel(tr("Profile:"), bottom));
    m_profileCombo = new QComboBox(bottom);
    bottomLayout->addWidget(m_profileCombo);

    auto *sendButton = new QPushButton(tr("Send Script"), bottom);
    bottomLayout->addWidget(sendButton);

    vLayout->addWidget(bottom);

    setCentralWidget(central);

    auto *tb = addToolBar(tr("File"));
    QAction *openAct    = tb->addAction(tr("Open..."));
    QAction *saveAct    = tb->addAction(tr("Save"));
    QAction *saveAsAct  = tb->addAction(tr("Save As..."));
    QAction *exampleAct = tb->addAction(tr("Insert Example"));

    QAction *undoAct = m_document->undoStack()->createUndoAction(this, tr("Undo"));
    undoAct->setShortcut(QKeySequence::Undo);
    tb->addAction(undoAct);
    addAction(undoAct);

    QAction *redoAct = m_document->undoStack()->createRedoAction(this, tr("Redo"));
    redoAct->setShortcut(QKeySequence::Redo);
    tb->addAction(redoAct);
    addAction(redoAct);

    connect(openAct, &QAction::triggered, this, &ScriptEditorWindow::openScriptFromFile);
    connect(saveAct, &QAction::triggered, this, &ScriptEditorWindow::saveScriptToFile);
    connect(saveAsAct, &QAction::triggered, this, &ScriptEditorWindow::saveScriptAs);
    connect(exampleAct, &QAction::triggered, this, &ScriptEditorWindow::insertExampleScript);

    connect(bindButton, &QPushButton::clicked, this, &ScriptEditorWindow::bindUdpPort);
    connect(m_localPortSpin, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &ScriptEditorWindow::bindUdpPort);

    connect(sendButton, &QPushButton::clicked, this, &ScriptEditorWindow::sendScriptToRunner);
    connect(m_profileCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ScriptEditorWindow::onProfileChanged);

    statusBar()->showMessage(tr("Ready"));
    updateWindowTitle();
}

void ScriptEditorWindow::openScriptFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open QtScript file"), QString(),
        tr("QtScript Files (*.qs *.js);;All Files (*.*)"));

    if (fileName.isEmpty())
        return;

    loadFromFile(fileName);
}

void ScriptEditorWindow::saveScriptToFile()
{
    if (m_currentFilePath.isEmpty()) {
        saveScriptAs();
        return;
    }

    if (!saveToFile(m_currentFilePath)) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Failed to save file:\n%1").arg(m_currentFilePath));
    }
}

void ScriptEditorWindow::saveScriptAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save QtScript file"),
        m_currentFilePath.isEmpty() ? QStringLiteral("script.qs") : m_currentFilePath,
        tr("QtScript Files (*.qs *.js);;All Files (*.*)"));

    if (fileName.isEmpty())
        return;

    if (saveToFile(fileName)) {
        m_document->setFilePath(fileName);
        m_document->clearDirty();
    } else {
        QMessageBox::warning(this, tr("Error"),
                             tr("Failed to save file:\n%1").arg(fileName));
    }
}

void ScriptEditorWindow::insertExampleScript()
{
    m_document->setText(exampleScriptText());
}

void ScriptEditorWindow::loadFromFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"),
                             tr("Failed to open file:\n%1").arg(filePath));
        return;
    }

    QTextStream in(&file);
#if QT_VERSION_MAJOR == 5
    in.setCodec("UTF-8");
#endif
    const QString text = in.readAll();
    m_document->loadText(text);
    m_document->setFilePath(filePath);
    statusBar()->showMessage(tr("Loaded %1").arg(QFileInfo(filePath).fileName()), 2000);
    updateWindowTitle();
}

bool ScriptEditorWindow::saveToFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
#if QT_VERSION_MAJOR == 5
    out.setCodec("UTF-8");
#endif
    out << m_document->text();
    statusBar()->showMessage(tr("Saved %1").arg(QFileInfo(filePath).fileName()), 2000);
    return true;
}

void ScriptEditorWindow::updateWindowTitle()
{
    QString title = tr("Script Editor");
    if (!m_currentFilePath.isEmpty()) {
        title += QStringLiteral(" - ") + QFileInfo(m_currentFilePath).fileName();
    }
    setWindowTitle(title);
}

void ScriptEditorWindow::bindUdpPort()
{
    const quint16 port = static_cast<quint16>(m_localPortSpin->value());
    // Binding is idempotent; transport will close/rebind if needed.
    m_transport->bind(port);
    qCInfo(lcEditorUi) << "Binding editor transport on port" << port;
}

void ScriptEditorWindow::sendScriptToRunner()
{
    const QHostAddress targetAddress(m_targetAddressEdit->text());
    const quint16 targetPort = static_cast<quint16>(m_targetPortSpin->value());
    const QByteArray scriptData = m_document->text().toUtf8();

    if (targetAddress.isNull()) {
        QMessageBox::warning(this, tr("Error"), tr("Invalid target IP address."));
        qCWarning(lcEditorUi) << "Invalid runner IP address" << m_targetAddressEdit->text();
        return;
    }

    // Transport layer handles retries/logging; we only need to provide bytes.
    TransportEndpoint endpoint { targetAddress, targetPort };
    qCInfo(lcEditorUi) << "Sending script payload to" << targetAddress << targetPort;
    m_transport->sendScript(scriptData, endpoint);
}

void ScriptEditorWindow::handleScriptRequest(const TransportEndpoint &sender)
{
    qCInfo(lcEditorUi) << "Script requested by" << sender.address << sender.port;
    // Always respond with the current buffer; runner decides what to do with it.
    m_transport->sendScript(m_document->text().toUtf8(), sender);
}

void ScriptEditorWindow::handleServerStatusMessage(const QString &message)
{
    qCInfo(lcEditorUi) << message;
    m_udpStatusLabel->setText(message);
    statusBar()->showMessage(message, 3000);
}

void ScriptEditorWindow::onProfileChanged(int index)
{
    if (index < 0 || index >= m_profiles.size())
        return;
    applyProfile(m_profiles.at(index));
}

void ScriptEditorWindow::loadProfiles()
{
    m_profiles = m_profileManager->profiles();
    if (!m_profileCombo)
        return;

    m_profileCombo->clear();
    for (const NetworkProfile &profile : m_profiles) {
        m_profileCombo->addItem(profile.name);
    }

    if (!m_profiles.isEmpty()) {
        // Applying index zero will also call bindUdpPort via applyProfile.
        m_profileCombo->setCurrentIndex(0);
        applyProfile(m_profiles.first());
        qCInfo(lcEditorUi) << "Loaded" << m_profiles.size() << "profiles";
    } else {
        bindUdpPort();
    }
}

void ScriptEditorWindow::applyProfile(const NetworkProfile &profile)
{
    {
        QSignalBlocker blocker(m_localPortSpin);
        m_localPortSpin->setValue(profile.editorPort);
    }
    {
        QSignalBlocker blocker(m_targetAddressEdit);
        m_targetAddressEdit->setText(profile.runnerHost);
    }
    {
        QSignalBlocker blocker(m_targetPortSpin);
        m_targetPortSpin->setValue(profile.runnerPort);
    }

    // Profiles carry both listen and send endpoints, so rebind after updates.
    bindUdpPort();
    qCInfo(lcEditorUi) << "Applied profile" << profile.name;
}

QString ScriptEditorWindow::exampleScriptText()
{
    return QString::fromUtf8(
        "\n"
        "canvas.clear();\n"
        "\n"
        "canvas.filledCircle(100, 100, 40, 'blue');\n"
        "\n"
        "canvas.circle(220, 100, 40, '#40E0D0', 3);\n"
        "\n"
        "canvas.triangle(80, 200, 180, 200, 130, 260,\n"
        "                'yellow', 'black', 2);\n"
        "\n"
        "canvas.rect(220, 180, 120, 60,\n"
        "            'red', 'black', 2);\n"
        "\n"
        "canvas.line(30, 300, 150, 300, 'red', 2);\n"
        "canvas.line(30, 320, 150, 320, 'green', 2);\n"
        "canvas.line(30, 340, 150, 340, 'blue', 2);\n"
        "canvas.line(30, 360, 150, 360, 'magenta', 2);\n"
    );
}
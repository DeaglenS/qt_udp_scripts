#ifndef SCRIPTRUNNERWINDOW_H
#define SCRIPTRUNNERWINDOW_H

#include <QMainWindow>
#include <QScriptEngine>
#include <QVector>

class QPlainTextEdit;
class QLineEdit;
class QSpinBox;
class QLabel;
class QPushButton;
class QComboBox;

class CanvasWidget;
class ScriptCanvas;
class CanvasState;
class IScriptTransport;
struct TransportEndpoint;
class ProfileManager;

#include "../network/ProfileManager.h"

// Handles UDP requests plus script execution and canvas presentation.
class ScriptRunnerWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ScriptRunnerWindow(QWidget *parent = nullptr);

private slots:
    void requestScript();
    void executeCurrentScript();
    void rebindUdp();
    void handleScriptPrint(const QString &message);
    void handleScriptReceived(const QByteArray &scriptCode, const TransportEndpoint &sender);
    void handleClientStatusMessage(const QString &message);
    void onProfileChanged(int index);

private:
    void createUi();
    void executeScript(const QString &code);
    void logMessage(const QString &msg);
    void loadProfiles();
    void applyProfile(const NetworkProfile &profile);

private:
    QPlainTextEdit *m_scriptView;
    QPlainTextEdit *m_logView;

    QLineEdit      *m_editorHostEdit;
    QSpinBox       *m_editorPortSpin;
    QSpinBox       *m_localPortSpin;
    QLabel         *m_udpStatusLabel;
    QComboBox      *m_profileCombo;
    QPushButton    *m_requestButton;
    QPushButton    *m_executeButton;

    CanvasWidget    *m_canvas;
    CanvasState     *m_canvasState;

    IScriptTransport *m_transport;
    ProfileManager   *m_profileManager;
    QVector<NetworkProfile> m_profiles;
    ScriptCanvas    *m_canvasApi;
    QScriptEngine    m_engine;
};

#endif

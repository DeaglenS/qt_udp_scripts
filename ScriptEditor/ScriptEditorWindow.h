#ifndef SCRIPTEDITORWINDOW_H
#define SCRIPTEDITORWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QHostAddress>
#include <QVector>

class QPlainTextEdit;
class QLineEdit;
class QSpinBox;
class QLabel;
class QPushButton;
class QComboBox;

class ScriptDocument;
class ScriptEditorController;
class IScriptTransport;
struct TransportEndpoint;
class ProfileManager;

#include "../network/ProfileManager.h"

// Hosts the script editing workflow plus transport wiring for SEND/GET events.
class ScriptEditorWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ScriptEditorWindow(QWidget *parent = nullptr);

private slots:
    void openScriptFromFile();
    void saveScriptToFile();
    void saveScriptAs();
    void insertExampleScript();

    void bindUdpPort();
    void sendScriptToRunner();
    void handleScriptRequest(const TransportEndpoint &sender);
    void handleServerStatusMessage(const QString &message);
    void onProfileChanged(int index);

private:
    void createUi();
    void loadFromFile(const QString &filePath);
    bool saveToFile(const QString &filePath);
    void updateWindowTitle();
    void loadProfiles();
    void applyProfile(const NetworkProfile &profile);

    static QString exampleScriptText();

private:
    QPlainTextEdit *m_editor;
    QLineEdit      *m_currentFileEdit;
    QSpinBox       *m_localPortSpin;
    QLabel         *m_udpStatusLabel;
    QLineEdit      *m_targetAddressEdit;
    QSpinBox       *m_targetPortSpin;
    QComboBox      *m_profileCombo;

    IScriptTransport     *m_transport;
    ScriptDocument       *m_document;
    ScriptEditorController *m_editorController;
    ProfileManager       *m_profileManager;
    QVector<NetworkProfile> m_profiles;
    QString               m_currentFilePath;
};

#endif 
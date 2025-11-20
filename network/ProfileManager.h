#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>
#include <QString>
#include <QVector>

// Mirrors the JSON schema so read/write are straightforward.
struct NetworkProfile
{
    QString name;
    QString editorHost;
    quint16 editorPort = 0;
    QString runnerHost;
    quint16 runnerPort = 0;

    bool isValid() const
    {
        return !name.isEmpty() && editorPort != 0 && runnerPort != 0;
    }
};

// Loads predefined network locations from JSON so QA can quickly switch
// between localhost and remote machines.
class ProfileManager : public QObject
{
    Q_OBJECT
public:
    explicit ProfileManager(QObject *parent = nullptr);

    QVector<NetworkProfile> profiles() const;
    NetworkProfile profileByName(const QString &name) const;

private:
    void loadProfiles();
    QStringList candidatePaths() const;

    QVector<NetworkProfile> m_profiles;
};

#endif



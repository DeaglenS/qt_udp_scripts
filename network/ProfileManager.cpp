#include "ProfileManager.h"

#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace {

// Fallback profile so the UI always has something usable even when JSON is missing.
NetworkProfile defaultProfile()
{
    NetworkProfile profile;
    profile.name = QStringLiteral("Localhost");
    profile.editorHost = QStringLiteral("127.0.0.1");
    profile.editorPort = 45454;
    profile.runnerHost = QStringLiteral("127.0.0.1");
    profile.runnerPort = 45455;
    return profile;
}

} // namespace

ProfileManager::ProfileManager(QObject *parent)
    : QObject(parent)
{
    loadProfiles();
}

QVector<NetworkProfile> ProfileManager::profiles() const
{
    return m_profiles;
}

NetworkProfile ProfileManager::profileByName(const QString &name) const
{
    for (const NetworkProfile &profile : m_profiles) {
        if (profile.name.compare(name, Qt::CaseInsensitive) == 0)
            return profile;
    }
    return defaultProfile();
}

void ProfileManager::loadProfiles()
{
    m_profiles.clear();

    const QStringList paths = candidatePaths();
    QFile file;
    for (const QString &path : paths) {
        file.setFileName(path);
        if (file.exists())
            break;
    }

    if (file.fileName().isEmpty() || !file.exists()) {
        m_profiles.append(defaultProfile());
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Silently fall back to localhost; the UI will show the bind failure if any.
        m_profiles.append(defaultProfile());
        return;
    }

    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject()) {
        m_profiles.append(defaultProfile());
        return;
    }

    const QJsonArray profilesArray = doc.object().value(QStringLiteral("profiles")).toArray();
    for (const QJsonValue &value : profilesArray) {
        const QJsonObject obj = value.toObject();
        NetworkProfile profile;
        profile.name = obj.value(QStringLiteral("name")).toString();
        profile.editorHost = obj.value(QStringLiteral("editorHost")).toString(QStringLiteral("127.0.0.1"));
        profile.editorPort = static_cast<quint16>(obj.value(QStringLiteral("editorPort")).toInt(45454));
        profile.runnerHost = obj.value(QStringLiteral("runnerHost")).toString(QStringLiteral("127.0.0.1"));
        profile.runnerPort = static_cast<quint16>(obj.value(QStringLiteral("runnerPort")).toInt(45455));

        if (profile.isValid())
            m_profiles.append(profile);
    }

    if (m_profiles.isEmpty())
        m_profiles.append(defaultProfile());
}

QStringList ProfileManager::candidatePaths() const
{
    const QString appDir = QCoreApplication::applicationDirPath();
    // Allow dropping profiles.json next to the exe or under config/ to keep deployment flexible.
    return {
        appDir + QStringLiteral("/profiles.json"),
        appDir + QStringLiteral("/config/profiles.json"),
        appDir + QStringLiteral("/../config/profiles.json"),
        appDir + QStringLiteral("/../../config/profiles.json"),
        QStringLiteral("config/profiles.json")
    };
}



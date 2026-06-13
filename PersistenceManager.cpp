#include "PersistenceManager.h"

#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

PersistenceManager::PersistenceManager()
{
}

QString PersistenceManager::dataFolder() const
{
    return QDir::homePath()
            + "/AgentePETE_Data";
}

QString PersistenceManager::profileFile() const
{
    return dataFolder()
            + "/user.json";
}

QString PersistenceManager::historyFile() const
{
    return dataFolder()
            + "/history.json";
}

bool PersistenceManager::initialize()
{
    QDir dir;

    if(!dir.exists(dataFolder()))
    {
        if(!dir.mkpath(dataFolder()))
        {
            return false;
        }
    }

    QFile history(historyFile());

    if(!history.exists())
    {
        if(history.open(QIODevice::WriteOnly))
        {
            history.write("[]");
            history.close();
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool PersistenceManager::saveUserProfile(
        const UserProfile &profile)
{
    QFile file(profileFile());

    if(!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonDocument doc(profile.toJson());

    file.write(doc.toJson());
    file.close();

    return true;
}

UserProfile PersistenceManager::loadUserProfile()
{
    QFile file(profileFile());

    if(!file.open(QIODevice::ReadOnly))
    {
        return UserProfile();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if(!doc.isObject())
    {
        return UserProfile();
    }

    return UserProfile::fromJson(doc.object());
}

bool PersistenceManager::saveConversation(
        const QString &prompt,
        const QString &response)
{
    QString cleanPrompt = prompt.trimmed();
    QString cleanResponse = response.trimmed();

    if(cleanPrompt.isEmpty())
    {
        return false;
    }

    if(cleanResponse.isEmpty())
    {
        cleanResponse = "[Sin respuesta]";
    }

    QJsonArray history = loadHistory();

    QJsonObject item;

    item["date"] = QDateTime::currentDateTime()
            .toString(Qt::ISODate);

    item["prompt"] = cleanPrompt;
    item["response"] = cleanResponse;

    history.append(item);

    QFile file(historyFile());

    if(!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonDocument doc(history);

    file.write(doc.toJson());
    file.close();

    return true;
}

bool PersistenceManager::saveConversation(
        const QString &prompt)
{
    return saveConversation(prompt, "[Sin respuesta]");
}

QJsonArray PersistenceManager::loadHistory()
{
    QFile file(historyFile());

    if(!file.exists())
    {
        return QJsonArray();
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        return QJsonArray();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if(!doc.isArray())
    {
        return QJsonArray();
    }

    return doc.array();
}

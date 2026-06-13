#include "UserProfile.h"

#include <QJsonObject>
#include <QStringList>

UserProfile::UserProfile()
{
    userName = "Usuario";
    preferredModel = "gemma3:4b";
}

QString UserProfile::getUserName() const
{
    return userName;
}

QString UserProfile::getPreferredModel() const
{
    return preferredModel;
}

void UserProfile::setUserName(const QString &name)
{
    QString cleanName = name.trimmed();

    if(cleanName.isEmpty())
    {
        userName = "Usuario";
        return;
    }

    userName = cleanName;
}

void UserProfile::setPreferredModel(const QString &model)
{
    QString cleanModel = model.trimmed();

    QStringList validModels;
    validModels << "gemma3:4b"
                << "llama3.2"
                << "mistral";

    if(validModels.contains(cleanModel))
    {
        preferredModel = cleanModel;
    }
    else
    {
        preferredModel = "gemma3:4b";
    }
}

QJsonObject UserProfile::toJson() const
{
    QJsonObject obj;

    obj["userName"] = userName;
    obj["preferredModel"] = preferredModel;

    return obj;
}

UserProfile UserProfile::fromJson(const QJsonObject &obj)
{
    UserProfile profile;

    profile.setUserName(
        obj["userName"].toString("Usuario"));

    profile.setPreferredModel(
        obj["preferredModel"].toString("gemma3:4b"));

    return profile;
}

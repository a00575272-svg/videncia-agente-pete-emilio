#pragma once

#include <QString>
#include <QJsonArray>

#include "UserProfile.h"

class IDataStorage
{
public:
    virtual ~IDataStorage() {}

    virtual bool initialize() = 0;

    virtual bool saveUserProfile(
            const UserProfile &profile) = 0;

    virtual UserProfile loadUserProfile() = 0;

    virtual bool saveConversation(
            const QString &prompt,
            const QString &response) = 0;

    virtual QJsonArray loadHistory() = 0;
};

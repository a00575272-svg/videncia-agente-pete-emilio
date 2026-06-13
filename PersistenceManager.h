#pragma once

#include <QString>
#include <QJsonArray>

#include "UserProfile.h"
#include "IDataStorage.h"

class PersistenceManager : public IDataStorage
{
public:
    PersistenceManager();

    bool initialize() override;

    bool saveUserProfile(
            const UserProfile &profile) override;

    UserProfile loadUserProfile() override;

    bool saveConversation(
            const QString &prompt,
            const QString &response) override;

    // Sobrecarga: mismo nombre, diferente cantidad de parámetros.
    bool saveConversation(
            const QString &prompt);

    QJsonArray loadHistory() override;

private:
    QString dataFolder() const;
    QString profileFile() const;
    QString historyFile() const;
};

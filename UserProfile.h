#pragma once

#include <QString>
#include <QJsonObject>

class UserProfile
{
public:
    UserProfile();

    QString getUserName() const;
    QString getPreferredModel() const;

    void setUserName(const QString &name);
    void setPreferredModel(const QString &model);

    QJsonObject toJson() const;
    static UserProfile fromJson(const QJsonObject &obj);

private:
    QString userName;
    QString preferredModel;
};

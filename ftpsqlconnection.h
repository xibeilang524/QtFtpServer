#ifndef FTPSQLCONNECTION_H
#define FTPSQLCONNECTION_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QList>
#include <QMap>
#include "ftpuser.h"
#include "ftpgroup.h"

class FtpSqlConnection
{
public:
    FtpSqlConnection(QString path,QString username,QString password);
    ~FtpSqlConnection();
    bool insertGroup(FtpGroup group);
    bool hasGroupByName(QString name);
    bool insertUser(FtpUser user);
    bool hasUserByName(QString name);
    bool deleteUserById(int id);
    QString queryGroupNameById(int id);
    int queryGroupIdByName(QString name);
    FtpUser queryUserByName(QString name);
    FtpGroup queryGroupById(int id);
    QList<QMap<QString,QString>> listGroupNames();
    QList<QMap<QString,QString>> listUserNames();
private:
    QSqlDatabase database;
};

#endif // FTPSQLCONNECTION_H

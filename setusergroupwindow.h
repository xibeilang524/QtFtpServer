#ifndef SETUSERGROUPWINDOW_H
#define SETUSERGROUPWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QPoint>
#include "newuserdialog.h"
#include "deleteuserdialog.h"
#include "ftpsqlconnection.h"
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class SetUserGroupWindow;
}

class SetUserGroupWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SetUserGroupWindow(QWidget *parent,FtpSqlConnection *sqlConnection);
    ~SetUserGroupWindow();


private:
    void init_data();
    void init_connect();

    Ui::SetUserGroupWindow *ui;
    NewUserDialog *newUserDialog;
    DeleteUserDialog *deleteUserDialog;
    FtpSqlConnection *sqlConnection;
    QStandardItemModel *group_standardItemModel;
    QStandardItemModel *user_standardItemModel;
    FtpUser ftpUser;
    FtpGroup ftpGroup;

    void showUserList();
    void showGroupList();
    void setFileAccess(QString file);
    void setDirectoryAcccess(QString directorty);

    bool edit_or_save;

private slots:
    void newUser();
    void editUser();
    void deleteUser();
    void newGroup();
    void editGroup();
    void deleteGroup();
    void refresh_user();
    void refresh_group();
    void user_list_item_click(const QModelIndex&);
    void group_list_item_click(const QModelIndex&);
    void edit_or_save_access();
    void file_access_click();
    void file_no_access_click();
    void dir_access_click();
    void dir_no_access_click();
};

#endif // SETUSERGROUPWINDOW_H

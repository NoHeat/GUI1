#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSortFilterProxyModel>
#include "changeinventory.h"



namespace Ui {
class UserList;
}

class UserList : public QDialog
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = 0);
    ~UserList();

private slots:


private:
    Ui::UserList *ui;
    QSqlDatabase mDatabase;
    QSqlQueryModel *mModel;
    QSortFilterProxyModel *proxyProducts;
};

#endif // USERLIST_H

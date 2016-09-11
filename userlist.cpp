#include "userlist.h"
#include "ui_userlist.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);


    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName("F:/QTprojects/FridgeAssistKitV4/database6.sqlite");
    if(!mDatabase.open()){
        QMessageBox::critical(this,"Error",mDatabase.lastError().text());
        return;
    }
    QSqlQuery qry;
    mModel = new QSqlQueryModel(this);
    mModel->setQuery("SELECT productName FROM supplies6");
    ui->listView->setModel(mModel);
}

UserList::~UserList()
{
    delete ui;
}



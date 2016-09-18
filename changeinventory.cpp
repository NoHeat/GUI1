#include "changeinventory.h"
#include "ui_changeinventory.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "userlist.h"


ChangeInventory::ChangeInventory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeInventory)
{
    ui->setupUi(this);

    //Tooltips section
    ui->comboBoxBY->setToolTip("Custom search by categories.");
    ui->pushButton_Add->setToolTip("To add an entry ensure to\ninclude a unique product ID.\nYou can make up your own Product ID.");
    ui->pushButton_ListView->setToolTip("Go to list view options menu.");
    ui->pushButton_Remove->setToolTip("To remove an item double click\n"
                                      "one of the entries in the table\n"
                                      "and then click remove.");
    ui->pushButton_Update->setToolTip("To update an entry double click\n"
                                      "one of the entries in the table\n"
                                      "and change the data in the lines\n"
                                      "provided. Lastly click update.");
    ui->lineEdit_ProductId->setToolTip("Unique identifier of an item\n"
                                       "used to add ad update entries.");
    ui->lineEdit_ProductName->setToolTip("Product name as scanned or\n"
                                         "provided by the user if is a\n "
                                         "custom item.");
    ui->lineEdit_ProductPrice->setToolTip("Product price as scanned or\n"
                                          "as input by user.");
    ui->lineEdit_ProductWeight->setToolTip("Item weight in milligramsm provided\n"
                                           "by scanner or user.");
    ui->lineSearch->setToolTip("Search bar that ignores capitalization.");

    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName("C:/Users/Big Teaze Toys/Desktop/latestGUI/GUI1/database6.sqlite");
   if(!mDatabase.open()){
       QMessageBox::critical(this,"Error",mDatabase.lastError().text());
       return;
   }
   QSqlQuery qry;
   mModel = new QSqlQueryModel(this);
   mModel->setQuery("SELECT * FROM supplies6");
   ui->tableView->setModel(mModel);

   //Trying code here related to proxyModel
   proxyProducts = new QSortFilterProxyModel(this);
   proxyProducts->setSourceModel(mModel);


   proxyProducts->setFilterCaseSensitivity(Qt::CaseInsensitive);
   proxyProducts->setFilterKeyColumn(-1); //The colunm I wat to filter. In this case proably by name. -1 searches in all colunms
   ui->comboBoxBY->addItems(QStringList() << "productID" << "productName" << "productPrice" << "productWeight" << "All");
   ui->tableView->setModel(proxyProducts);
}

ChangeInventory::~ChangeInventory()
{
    delete ui;
}

void ChangeInventory::on_pushButton_Add_clicked()
{
    QString productID,productName, productPrice, productWeight;
    productID = ui->lineEdit_ProductId->text();
    productName = ui->lineEdit_ProductName->text();
    productPrice = ui->lineEdit_ProductPrice->text();
    productWeight = ui->lineEdit_ProductWeight->text();

    QSqlQuery qry;
    qry.exec(QString("INSERT INTO supplies6 (productID,productName,productPrice,productWeight) VALUES ('"+productID+"','"+productName+"','"+productPrice+"','"+productWeight+"')"));
    if(qry.exec())
    {
        QMessageBox::information(this,tr("Add"),tr("Entry Added"));

    }
    else
    {
        //Review this error (Unable to fetch row)
        QMessageBox::critical(this,tr("Error"), qry.lastError().text());
    }
    mModel->setQuery("SELECT * FROM supplies6");
    ui->tableView->setModel(mModel);
    proxyProducts->setSourceModel(mModel);

    proxyProducts->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyProducts->setFilterKeyColumn(-1); //The colunm I wat to filter. In this case proably by name. -1 searches in all colunms
    //ui->comboBoxBY->addItems(QStringList() << "productID" << "productName" << "productPrice" << "productWeight" << "All");
    ui->tableView->setModel(proxyProducts);
}

void ChangeInventory::on_pushButton_Update_clicked()
{
    //Update
    //Add logic to check if the key being updated already exists. Otherwise it will do nothing.
    QString productID,productName, productPrice, productWeight;
    productID = ui->lineEdit_ProductId->text();
    productName = ui->lineEdit_ProductName->text();
    productPrice = ui->lineEdit_ProductPrice->text();
    productWeight = ui->lineEdit_ProductWeight->text();

    QSqlQuery qry;
    qry.prepare("update supplies6 set productID='"+productID+"',productName='"+productName+"',productPrice='"+productPrice+"',productWeight='"+productWeight+"' where productID='"+productID+"'");

    if(qry.exec())
    {
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(this,tr("Error"), qry.lastError().text());
    }
    mModel->setQuery("SELECT * FROM supplies6");
    ui->tableView->setModel(mModel);
    proxyProducts->setSourceModel(mModel);

    proxyProducts->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyProducts->setFilterKeyColumn(-1); //The colunm I wat to filter. In this case proably by name. -1 searches in all colunms
    //ui->comboBoxBY->addItems(QStringList() << "productID" << "productName" << "productPrice" << "productWeight" << "All");
    ui->tableView->setModel(proxyProducts);
}

void ChangeInventory::on_pushButton_Remove_clicked()
{
    //Remove
    QString productID,productName,productPrice,productWeight;
    productID = ui->lineEdit_ProductId->text();
    productName = ui->lineEdit_ProductName->text();
    productPrice = ui->lineEdit_ProductPrice->text();
    productWeight = ui->lineEdit_ProductWeight->text();

    QSqlQuery qry;
    qry.prepare("delete from supplies6 where productID='"+productID+"'");

    if(qry.exec())
    {
       //Use a QmessageBox to alert the user they are about to delete the entry

        //This message box will inform the user that the data was succesfully written and saved to the database
        QMessageBox::information(this,tr("Delete"),tr("Deleted"));


    }
    else
    {
        //This message will show that there was an error during execution
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }

    mModel->setQuery("SELECT * FROM supplies6");
    ui->tableView->setModel(mModel);
    proxyProducts->setSourceModel(mModel);

    proxyProducts->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyProducts->setFilterKeyColumn(-1); //The colunm I wat to filter. In this case proably by name. -1 searches in all colunms
    //ui->comboBoxBY->addItems(QStringList() << "productID" << "productName" << "productPrice" << "productWeight" << "All");
    ui->tableView->setModel(proxyProducts);
}

void ChangeInventory::on_pushButton_ListView_clicked()
{
    UserList *w = new UserList;
    w->setModal(true);
    w->show();
}

void ChangeInventory::on_lineSearch_textChanged(const QString &arg1)
{
     proxyProducts->setFilterFixedString(arg1);
}

void ChangeInventory::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from supplies6 where productID='"+val+"' or productName='"+val+"' or productPrice='"+val+"' or productWeight='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
         //From the database each colunm has an index. The index starts at 0. To specify eid we need colunm 0.
         //To specify name then the value is 1, surname would have value 2, and so on... going from left to right.

           ui->lineEdit_ProductId->setText(qry.value(0).toString());
           ui->lineEdit_ProductName->setText(qry.value(1).toString());
           ui->lineEdit_ProductPrice->setText(qry.value(2).toString());
           ui->lineEdit_ProductWeight->setText(qry.value(3).toString());
       }
        //This is closing the connection to the database when the function to write into it was sucessfully executed

    }
    else
    {
        //This message will show that there was an error during execution
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
}

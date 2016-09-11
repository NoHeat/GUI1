#ifndef CHANGEINVENTORY_H
#define CHANGEINVENTORY_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSortFilterProxyModel>

namespace Ui {
class ChangeInventory;
}
class QSqlQueryModel;
class ChangeInventory : public QDialog
{
     //Every widget inherits from QOBJECT. The Q_OBJECT macro shown below is what gives this library all of its functionality.
    Q_OBJECT

public:
    //This section contains slots which are of private type. Slots take an input signal such as a mouse click event and perform the
    //instrucions set by the programmer inside that block of code.
    explicit ChangeInventory(QWidget *parent = 0);
    ~ChangeInventory();

private slots:
    void on_pushButton_Add_clicked();
    void on_pushButton_Update_clicked();
    void on_pushButton_Remove_clicked();



    void on_pushButton_ListView_clicked();

    void on_lineSearch_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

private:
    //This pointer is very important. Is used to call many of the methods inherited by Q_OBJECT. It stands for "User Interface".
    Ui::ChangeInventory *ui;
    QSqlDatabase mDatabase;
    QSqlQueryModel *mModel;
    QSortFilterProxyModel *proxyProducts;
};

#endif // CHANGEINVENTORY_H

#ifndef ACTIONMENU_H
#define ACTIONMENU_H

#include <QDialog>

namespace Ui {
class ActionMenu;
}

class ActionMenu : public QDialog
{
    //Every widget inherits from QOBJECT. The Q_OBJECT macro shown below is what gives this library all of its functionality.
    Q_OBJECT

public:
    //destructor
    explicit ActionMenu(QWidget *parent = 0);
    ~ActionMenu();

private slots:
    //This section contains slots which are of private type. Slots take an input signal such as a mouse click event and perform the
    //instrucions set by the programmer inside that block of code.

    //This particular slot when clicked will take me to the "ChangeIventory" window
    void on_pushButton_ChangeInventory_clicked();
    //This particular slot when clicked will take me to the "CustomInput" window
    void on_pushButton_CustomInput_clicked();
    //This particular slot when clicked will take me to the "ShoppingList" window
    void on_pushButton_ShoppingList_clicked();

private:
    //This pointer is very important. Is used to call many of the methods inherited by Q_OBJECT. It stands for "User Interface".
    Ui::ActionMenu *ui;
};

#endif // ACTIONMENU_H

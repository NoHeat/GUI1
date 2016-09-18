#include "actionmenu.h"
#include "ui_actionmenu.h"
#include "changeinventory.h"
#include "custominput.h"
#include "userlist.h"
#include "changeinventory.h"

ActionMenu::ActionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActionMenu)
{
    //This is the constructor that creates the instance of "ActionMenu" window
    ui->setupUi(this);
    ui->pushButton_ChangeInventory->setToolTip("Lookup current items stored.");

    ui->pushButton_CustomInput->setToolTip("Go to custom input menu to add new items.");

    ui->pushButton_ShoppingList->setToolTip("Review shopping list options.");

}

ActionMenu::~ActionMenu()
{
    //This is the destructor that is called whenever the user finishes the program or X out of the window
    delete ui;

}

void ActionMenu::on_pushButton_ChangeInventory_clicked()
{
    //Change Inventory

    //In the line of code below I'm creating a pointer variable "w" (window) which points to the ChangeInventory window
    ChangeInventory *w = new ChangeInventory;
    //By Setting the modal to true when the user clicks on the "ChangeIventory" button, I only allow them to use that window.
    //If modal is not set to true the window can appear hidden behind another, and the user can open enought instances of
    //a window as to crash the program.
    w->setModal(true);
    //This line of code shows the window after the button is clicked
    w->show();

    //The code above applies to most other instances where windows are switched. The use of using a pointer is to make the transition
    //more customizable. For instances is possible to set stylesheets this way, but not in the case where the window is not called by
    //a pointer.
}

void ActionMenu::on_pushButton_CustomInput_clicked()
{
    //Explanation above applies here
    CustomInput *w = new CustomInput;
    w->setModal(true);
    w->show();
}

void ActionMenu::on_pushButton_ShoppingList_clicked()
{
    //Explanation above applies here
    UserList *w = new UserList;
    w->setModal(true);
    w->show();
}

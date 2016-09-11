#include "custominput.h"
#include "ui_custominput.h"
#include "changeinventory.h"

CustomInput::CustomInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomInput)
{
    ui->setupUi(this);
}

CustomInput::~CustomInput()
{
    delete ui;
}

void CustomInput::on_pushButton_Fruits_clicked()
{
    ChangeInventory *w = new ChangeInventory;
    w->setModal(true);
    w->show();
}

void CustomInput::on_pushButton_Vegetables_clicked()
{
    ChangeInventory *w = new ChangeInventory;
    w->setModal(true);
    w->show();
}

void CustomInput::on_pushButton_Meats_clicked()
{
    ChangeInventory *w = new ChangeInventory;
    w->setModal(true);
    w->show();
}

void CustomInput::on_pushButton_Other_clicked()
{
    ChangeInventory *w = new ChangeInventory;
    w->setModal(true);
    w->show();
}

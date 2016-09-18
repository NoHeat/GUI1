#include "custominput.h"
#include "ui_custominput.h"
#include "changeinventory.h"
#include <QStyle>

CustomInput::CustomInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomInput)
{
    ui->setupUi(this);

    QPixmap pixmap (":/GUIPictures/fru_fin.png");
    QIcon ButtonIconFruit(pixmap);
    //resize(pixmap.size());
    ui->pushButton_Fruits->setIcon(ButtonIconFruit);
    ui->pushButton_Fruits->setIconSize(pixmap.rect().size());

    QPixmap pixmap1 (":/GUIPictures/vegg_fin.png");
    QIcon ButtonIConVegetables(pixmap1);
    //resize(pixmap1.size());
    ui->pushButton_Vegetables->setIcon(ButtonIConVegetables);
    ui->pushButton_Vegetables->setIconSize(pixmap.rect().size());

    QPixmap pixmap2 (":/GUIPictures/meatsAndFish.jpg");
    QIcon ButtonIConMeatsAndFish(pixmap2);
    //resize(pixmap2.size());
    ui->pushButton_Meats->setIcon(ButtonIConMeatsAndFish);
    ui->pushButton_Meats->setIconSize(pixmap.rect().size());

    QPixmap pixmap3 (":/GUIPictures/can-question.jpg");
    QIcon ButtonIConOther(pixmap3);
    //resize(pixmap3.size());
    ui->pushButton_Other->setIcon(ButtonIConOther);
    ui->pushButton_Other->setIconSize(pixmap.rect().size());

    //tooltips
    ui->pushButton_Fruits->setToolTip("Select to add fruit item\n"
                                      "to inventory.");
    ui->pushButton_Meats->setToolTip("Select to add meats or fish\n"
                                     "products to inventory.");
    ui->pushButton_Other->setToolTip("Select to add other item.");
    ui->pushButton_Vegetables->setToolTip("Select to add vegetables\n"
                                          "to inventory.");
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

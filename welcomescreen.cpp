#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include "actionmenu.h"
#include "mycaledar.h"
//#include <QStyle>

WelcomeScreen::WelcomeScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeScreen)
{
    ui->setupUi(this);
    //This is an example of how to set a tooltip on to a button. Hover mouse over button to see tool tip.
    ui->WelcomeScreenStartButton->setToolTip("Go to Action Menu");

    //Comented below is an example of how to set up an icon on to a button. This icon uses Qt resources.
    //QIcon icon (":/ImagesAndIcons/Home.png");
    //ui->WelcomeScreenStartButton->set(icon);

    ui->WelcomeScreenButonCalendar->setToolTip("Calendar Widget");

    //QFont font ("Courier");
    //ui->WelcomeScreenStartButton->setFront(font);

    //This is a example of how to add a picture to a label
    //QPixmap pix ("Resource/Path/To/Picture.png");
    //ui->LabelNameHere->setPixmap(pix);
    //ui->LabelNameHere->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //This is an example of how to change the color of a button using StyleSheets
    //ui->WelcomeScreenButonCalendar->("background:red");

    //This is an example of how to make a button with an image. This is good for custominput.
    //QPixmap pixmap (":/ImagesAndIcons/fru_fin.png");
    //QIcon ButtonIconFruit(pixmap);
    //ui->btn_fruits_input->setIcon(ButtonIconFruit);
    //ui->btn_fruits_input->setIconSize(pixmap.rect().size());

    //QPixmap pixmap1 (":/ImagesAndIcons/vegg_fin.png");
    //QIcon ButtonIconVegetable(pixmap1);
    //ui->btn_vegetables_input->setIcon(ButtonIconVegetable);
    //ui->btn_vegetables_input->setIconSize(pixmap.rect().size());




}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;
}

void WelcomeScreen::on_WelcomeScreenStartButton_clicked()
{
    ActionMenu *w = new ActionMenu;
    w->setModal(true);
    w->show();
}

void WelcomeScreen::on_WelcomeScreenButonCalendar_clicked()
{
    MyCaledar *w = new MyCaledar;
    w->setModal(true);
    w->show();
}

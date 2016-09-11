#include "mycaledar.h"
#include "ui_mycaledar.h"

MyCaledar::MyCaledar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCaledar)
{
    ui->setupUi(this);
}

MyCaledar::~MyCaledar()
{
    delete ui;
}

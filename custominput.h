#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>

namespace Ui {
class CustomInput;
}

class CustomInput : public QDialog
{
    Q_OBJECT

public:
    explicit CustomInput(QWidget *parent = 0);
    ~CustomInput();

private slots:
    void on_pushButton_Fruits_clicked();

    void on_pushButton_Vegetables_clicked();

    void on_pushButton_Meats_clicked();

    void on_pushButton_Other_clicked();

private:
    Ui::CustomInput *ui;
};

#endif // CUSTOMINPUT_H

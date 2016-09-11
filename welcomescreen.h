#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QDialog>

namespace Ui {
class WelcomeScreen;
}

class WelcomeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeScreen(QWidget *parent = 0);
    ~WelcomeScreen();

private slots:
    void on_WelcomeScreenStartButton_clicked();

    void on_WelcomeScreenButonCalendar_clicked();

private:
    Ui::WelcomeScreen *ui;
};

#endif // WELCOMESCREEN_H

#ifndef MYCALEDAR_H
#define MYCALEDAR_H

#include <QDialog>

namespace Ui {
class MyCaledar;
}

class MyCaledar : public QDialog
{
    Q_OBJECT

public:
    explicit MyCaledar(QWidget *parent = 0);
    ~MyCaledar();

private:
    Ui::MyCaledar *ui;
};

#endif // MYCALEDAR_H

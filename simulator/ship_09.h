#ifndef SHIP_09_H
#define SHIP_09_H

#include <QDialog>

namespace Ui {
class ship_09;
}

class ship_09 : public QDialog
{
    Q_OBJECT

public:
    explicit ship_09(QWidget *parent = 0);
    ~ship_09();

private:
    Ui::ship_09 *ui;
};

#endif // SHIP_09_H

#ifndef SHIP_17_H
#define SHIP_17_H

#include <QDialog>

namespace Ui {
class Ship_17;
}

class Ship_17 : public QDialog
{
    Q_OBJECT

public:
    explicit Ship_17(QWidget *parent = 0);
    ~Ship_17();

private:
    Ui::Ship_17 *ui;
};

#endif // SHIP_17_H

#include "ship_17.h"
#include "ui_ship_17.h"

Ship_17::Ship_17(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ship_17)
{
    ui->setupUi(this);
}

Ship_17::~Ship_17()
{
    delete ui;
}

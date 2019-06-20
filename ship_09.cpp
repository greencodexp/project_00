#include "ship_09.h"
#include "ui_ship_09.h"

ship_09::ship_09(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ship_09)
{
    ui->setupUi(this);
}

ship_09::~ship_09()
{
    delete ui;
}

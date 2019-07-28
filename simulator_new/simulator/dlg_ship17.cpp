#include "dlg_ship17.h"
#include "ui_dlg_ship17.h"

Dlg_Ship17::Dlg_Ship17(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Ship17)
{
    ui->setupUi(this);
}

Dlg_Ship17::~Dlg_Ship17()
{
    delete ui;
}

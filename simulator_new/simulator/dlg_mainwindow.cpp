#include "dlg_mainwindow.h"
#include "ui_dlg_mainwindow.h"

Dlg_mainWindow::Dlg_mainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_mainWindow)
{
    ui->setupUi(this);
    f_init();
}

Dlg_mainWindow::~Dlg_mainWindow()
{
    delete ui;
}

void Dlg_mainWindow::f_init()
{
    // init
    // startup layout   
    // connections
    connect(this->ui->btn_ship09,SIGNAL(clicked(bool)),this,SLOT(f_showShip09()));
    connect(this->ui->btn_ship17,SIGNAL(clicked(bool)),this,SLOT(f_showShip17()));
}

void Dlg_mainWindow::f_showShip17()
{
    Dlg_Ship17 *dlg_ship17 = new Dlg_Ship17();
    dlg_ship17->show();
    this->hide();
    connect(dlg_ship17,SIGNAL(finished(int)),this,SLOT(show()));
}

void Dlg_mainWindow::f_showShip09()
{
    Dlg_ship09 *dlg_ship09 = new Dlg_ship09();
     dlg_ship09->show();
     this->hide();
     connect(dlg_ship09,SIGNAL(finished(int)),this,SLOT(show()));
}

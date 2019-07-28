#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f_init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::f_init()
{
    // init
    // connections
    connect(this->ui->btn_ship09,SIGNAL(clicked(bool)),this,SLOT(f_showShip09()));
    connect(this->ui->btn_ship17,SIGNAL(clicked(bool)),this,SLOT(f_showShip17()));
}

void MainWindow::f_showShip17()
{
    Dlg_Ship17 *dlg_ship17 = new Dlg_Ship17();
    dlg_ship17->show();
    this->hide();
    connect(dlg_ship17,SIGNAL(finished(int)),this,SLOT(show()));
}

void MainWindow::f_showShip09()
{
   Dlg_ship09 *dlg_ship09 = new Dlg_ship09();
    dlg_ship09->show();
    this->hide();
    connect(dlg_ship09,SIGNAL(finished(int)),this,SLOT(show()));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Ship_17();
    dialog->show();

    dialog1 = new ship_09();
    dialog1->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

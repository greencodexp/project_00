#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<dlg_ship09.h>
#include<dlg_ship17.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void f_init();
private:
    Ui::MainWindow *ui;    
public slots:
    void f_showShip17();
    void f_showShip09();
};

#endif // MAINWINDOW_H

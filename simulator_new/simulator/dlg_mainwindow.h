#ifndef DLG_MAINWINDOW_H
#define DLG_MAINWINDOW_H

#include <QDialog>
#include<dlg_ship09.h>
#include<dlg_ship17.h>

namespace Ui {
class Dlg_mainWindow;
}

class Dlg_mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_mainWindow(QWidget *parent = 0);
    ~Dlg_mainWindow();
    void f_init();

private:
    Ui::Dlg_mainWindow *ui;
public slots:
    void f_showShip17();
    void f_showShip09();
};

#endif // DLG_MAINWINDOW_H

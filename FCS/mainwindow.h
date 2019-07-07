#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QString>
#include <QDebug>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void f_Init();
    void f_SetupLayout();
    void f_getSocketConfFCS();
    void f_getSocketConfBCC();
private:
    Ui::MainWindow *ui;
    // port
    int m_portBCC;
    int m_portFCS;
    // ip
    QHostAddress *m_ipBCC;
    QHostAddress *m_ipFCS;
    // udpclient
    QUdpSocket *m_socketFCS;
    QUdpSocket *m_socketBCC;
    QTimer *m_timer;
public slots:
    void f_send();
};

#endif // MAINWINDOW_H

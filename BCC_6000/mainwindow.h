#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QString>
#include <cmessage.h>
#include <QMessageBox>
#include <QtCore>
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
    void f_readConfigFile(QString pathFile);
    void f_setUpLayout();
    void f_startListen();
    void f_sendMSG(unsigned int receivedMSGCouter);
private:
    Ui::MainWindow *ui;
    // port
    int m_portSendFCS;
    int m_portReceiveFCS;
    int m_portSendLocal;
    int m_portReceiveLocal;
    // ip
    QHostAddress *m_ipLocal;
    QHostAddress *m_ipFCC;
    QHostAddress *m_ipRFC;
    // udpclient
    QUdpSocket *m_socketSendLocal;
    QUdpSocket *m_socketRecieveLocal;

    QUdpSocket *m_socketFCC;
    QUdpSocket *m_socketRFC;
    // table
    int tableRowCount;
    //Timer m_sendTimer;
signals:

public slots:
    void s_receiveMSG();
    void s_sendMSG();
};

#endif // MAINWINDOW_H

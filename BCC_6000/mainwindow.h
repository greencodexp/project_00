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
#include "cglobal.h"
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
    void f_sendMSG(unsigned int receivedMSGCouter,  unsigned short int firemode, unsigned int msgCounter);
    void f_sendMSG(MSG_BCC6000STA msg,QHostAddress *remoteAdd,int remotePort);
    unsigned int m_statusMsgCouter;
private:
    Ui::MainWindow *ui;
    // port
    //int m_portSendFCS;
    int m_portRemote;
    int m_portSendLocal;
    int m_portReceiveLocal;
    // ip
    QHostAddress *m_ipLocal;
    QHostAddress *m_ipRemote;
    //QHostAddress *m_ipRFC;
    // udpclient
    QUdpSocket *m_socketSendLocal;
    QUdpSocket *m_socketRecieveLocal;

    QUdpSocket *m_socketRemote;
    //QUdpSocket *m_socketRFC;

    // received msg
    unsigned short int m_commandID;
    unsigned int m_receivedMSGCounter;
    unsigned short int m_fireModeRocketSelection ;//
    unsigned int m_msgSendCounter;
    // table
    int m_tableRcvRowCount;
    int m_tableSendRowCount;
    QTimer *m_timerStatusMsg;
    // flag
    bool m_flagSendStatusMsg;
signals:

public slots:
    void s_receiveMSG();
    void s_sendMSG();
    void sl_sendStatusMsg();
};

#endif // MAINWINDOW_H

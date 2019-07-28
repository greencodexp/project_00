#ifndef DLG_SHIP09_H
#define DLG_SHIP09_H
#include <QDialog>
#include <QByteArray>
#include <QDebug>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include <qmath.h>
namespace Ui {
class Dlg_ship09;
}

class Dlg_ship09 : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_ship09(QWidget *parent = 0);
    ~Dlg_ship09();
    void f_Init();
    void f_sendSelfTestMsg(QByteArray msg);
    QByteArray f_getCntrlMsg();
    void f_readConfigFile(QString path);
    // port
    int m_portSendLocal;
    int m_portRecivLocal;
    int m_portRecivB2500;
    int m_portSendB2500;
    int m_flagB2500Selected; // 1-B2500_1 2-B2500_2 3-B2500_3 4-B2500_4
    // ip
    QHostAddress *m_addLocal;
    QHostAddress *m_addB2500_1;
    QHostAddress *m_addB2500_2;
    QHostAddress *m_addB2500_3;
    QHostAddress *m_addB2500_4;
    // udpclient
    QUdpSocket *m_socketLocalSend;
    QUdpSocket *m_socketLocalReciv;
private:
    Ui::Dlg_ship09 *ui;
signals:
public slots:
    void f_sendCntrlMsg();
    void f_setB2500_1_Selected();
    void f_setB2500_2_Selected();
    void f_setB2500_3_Selected();
    void f_setB2500_4_Selected();
};

#endif // DLG_SHIP09_H

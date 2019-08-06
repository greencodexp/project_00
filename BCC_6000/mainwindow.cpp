#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f_Init();
    f_setUpLayout();
    f_startListen();
//    QMessageBox msg;
//    msg.setText("Receive udp msg");
//    msg.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::f_Init()
{
    m_statusMsgCouter =0;
    m_tableRcvRowCount = 0;
    m_tableSendRowCount =0;
    // init socket
    // port
    //m_portSendFCS = 6230;
    m_portRemote = 6235;
    m_portSendLocal = 6235;
    m_portReceiveLocal = 6230;
    // ip
    m_ipLocal = new QHostAddress("192.168.1.105");
    m_ipRemote = new QHostAddress("192.168.1.99");
    //m_ipRFC = new QHostAddress("192.168.1.99");
    // udpclient

    m_socketSendLocal = new QUdpSocket(this);
    m_socketSendLocal->bind(*m_ipLocal,m_portSendLocal);

    m_socketRecieveLocal = new QUdpSocket(this);
    m_socketRecieveLocal->bind(*m_ipLocal,m_portReceiveLocal);
    // flag
    m_flagSendStatusMsg=false;
    // Timer
    m_timerStatusMsg = new QTimer(this);
    m_timerStatusMsg->setInterval(20);
    m_msgSendCounter =0;

//    m_socketFCC = new QUdpSocket(this);
//    m_socketFCC->bind(*m_ipFCC,m_portSendFCS);

//    m_socketRFC = new QUdpSocket(this);
//    m_socketRFC->bind(*m_ipFCC,m_portSendFCS);
    // connection
    connect(m_socketRecieveLocal,SIGNAL(readyRead()), this, SLOT(s_receiveMSG()));
    //connect(ui->ctl_btnSendMSG,SIGNAL(clicked()),this,SLOT(s_sendMSG()));
    connect(m_timerStatusMsg,SIGNAL(timeout()),this,SLOT(sl_sendStatusMsg()));
    //connect(ui->ctl_btnSendMSG_2,SIGNAL(clicked(bool)),this,SLOT(s_sendMSG()));
//    connect(m_socketSendLocal,SIGNAL(se))
}

void MainWindow::f_setUpLayout()
{
    // message type
//    ui->ctl_cbSendMSGTypeFCC->addItem("Message 1");
//    ui->ctl_cbSendMSGTypeFCC->addItem("Message 2");
//    ui->ctl_cbSendMSGTypeFCC->addItem("Message 3");
//    ui->ctl_cbSendMSGTypeFCC->addItem("Message 4");

//    ui->ctl_cbSendMSGTypeRFC->addItem("Message 1");
//    ui->ctl_cbSendMSGTypeRFC->addItem("Message 2");
//    ui->ctl_cbSendMSGTypeRFC->addItem("Message 3");
//    ui->ctl_cbSendMSGTypeRFC->addItem("Message 4");

    //------------------------------------------ IP QLineEdit
    QRegExpValidator *v = new QRegExpValidator(this);
    QRegExp rx("((1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})\\.){3,3}(1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})");
    v->setRegExp(rx);
    ui->ctl_IP_BCC->setValidator(v);
    ui->ctl_IP_FCC->setValidator(v);
    ui->ctl_IP_RFC->setValidator(v);
    // socket config
    ui->ctl_IP_BCC->setText("192.168.1.101");
    ui->ctl_IP_FCC->setText("127.0.0.1");
    ui->ctl_IP_RFC->setText("127.0.0.1");

    ui->ctl_portBCC->setText("6231");
    ui->ctl_portFCC->setText("6230");
    ui->ctl_portRFC->setText("6230");


//    ui->ctl_tableFFC->setRowCount(100);

    // config log Recieve table
    ui->ctl_tableRciv->setColumnCount(6);
    QStringList m_TableHeader;
    m_TableHeader<<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght";
    ui->ctl_tableRciv->setHorizontalHeaderLabels(m_TableHeader);
    ui->ctl_tableRciv->verticalHeader()->setVisible(false);
    ui->ctl_tableRciv->setColumnWidth(0,40);
    ui->ctl_tableRciv->setColumnWidth(1,100);
    ui->ctl_tableRciv->setColumnWidth(2,100);
    ui->ctl_tableRciv->setColumnWidth(3,100);
    ui->ctl_tableRciv->setColumnWidth(4,300);
    ui->ctl_tableRciv->setColumnWidth(5,40);
    //
    // config log send table
    ui->ctl_tableSend->setColumnCount(6);
    m_TableHeader<<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght";
    ui->ctl_tableSend->setHorizontalHeaderLabels(m_TableHeader);
    ui->ctl_tableSend->verticalHeader()->setVisible(false);
    ui->ctl_tableSend->setColumnWidth(0,40);
    ui->ctl_tableSend->setColumnWidth(1,100);
    ui->ctl_tableSend->setColumnWidth(2,100);
    ui->ctl_tableSend->setColumnWidth(3,100);
    ui->ctl_tableSend->setColumnWidth(4,300);
    ui->ctl_tableSend->setColumnWidth(5,40);

//    ui->ctl_tableFFC->setItem(0,0,new QTableWidgetItem("1"));
//    ui->ctl_tableFFC->setItem(0,1,new QTableWidgetItem("00:00:00"));
//    ui->ctl_tableFFC->setItem(0,2,new QTableWidgetItem("Send"));
//    ui->ctl_tableFFC->setItem(0,3,new QTableWidgetItem("00 01 ba cs"));
}

void MainWindow::f_startListen()
{
//    while (socket->hasPendingDatagrams()) {
//            QByteArray datagram;
//            datagram.resize(socket->pendingDatagramSize());
//            socket->readDatagram(datagram.data(), datagram.size());
//            qDebug() << "Message receive: " << datagram.data();
    //        }
}

void MainWindow::f_sendMSG(unsigned int receivedMSGCouter, unsigned short int firemode, unsigned int msgCounter)
{
    //
    // status msg
    unsigned short int m_header = 0x5A5A;
    unsigned short int m_senderID = 0x0105;
    unsigned short int m_receivedID = 0x0001;
    unsigned short int m_statusDataID = 0x0001;
    unsigned short int m_commandID = 0x0001;
    unsigned int m_receivedMSGCounter = receivedMSGCouter;
    unsigned short int m_insulationCheckStatus = 0x0001;
    unsigned short int m_fireModeRocketSelection = firemode;//
    unsigned short int m_azimuthFiringAngle = 0x0001;
    unsigned char m_statusIndicator1 =0x01;
    unsigned short int m_statusIndicator2 = 0x0002;
    unsigned char m_testResultForSelfTest = 0x01;
    unsigned short int m_errorCode = 0x0000;
    unsigned short int m_fireCircuitCheck = 0x0001;
    //unsigned short int m_reserved1 =0x0000 ;
    unsigned short int m_reserved2=0x0000;
    unsigned short int m_reserved3=0x0000;
    unsigned short int m_reserved4=0x0000;
    unsigned int m_messageCounter = msgCounter;
    unsigned short int m_footer = 0xA5A5;
//    QMessageBox mesage;
//    mesage.setText("Send status msg");
//    mesage.exec();
    QByteArray msg;
    //QByteArray datagram_out;
    QDataStream out(&msg, QIODevice::WriteOnly);
    out <<m_header<< m_senderID << m_receivedID << m_statusDataID<<m_commandID<<m_receivedMSGCounter<<m_insulationCheckStatus
          <<m_fireModeRocketSelection<<m_azimuthFiringAngle<<m_statusIndicator1<<m_statusIndicator2
            <<m_testResultForSelfTest<<m_errorCode<<m_fireCircuitCheck<<m_reserved2<<m_reserved3
              <<m_reserved4<<m_messageCounter<<m_footer;

    int send = m_socketSendLocal->writeDatagram(msg,*m_ipRemote,m_portRemote);
    if(send==-1)
    {
        qDebug() << "Send msg error";
    }
    else
    {
        // convert QByteArray
        QString str_data;
        str_data="";
        for(int i=0;i<msg.count();i++)
           {
               QByteArray byte_i = msg.mid(i,1);
               QString strbyte_i = byte_i.toHex() +" ";
               str_data.append(strbyte_i);
           };
        // lenght
        QString str_lenght = QString::number(msg.size());
        // log to console
        qDebug() << "Send msg: "<< str_data;
        //qDebug() << "Send msg: "<<QString::number(send)<<" [bytes]";
    }
}

void MainWindow::s_receiveMSG()
{
     QByteArray datagram;
     datagram.resize(m_socketRecieveLocal->pendingDatagramSize());
     int msgcount = m_socketRecieveLocal->readDatagram(datagram.data(), datagram.size());
     if(msgcount>0)
     {
     // phan tich goi tin nhan duoc
     QDataStream streamMsg(&datagram, QIODevice::ReadOnly);

     MSG_BCC6000CTL ctlMsg;
     streamMsg>>ctlMsg.m_header
              >>ctlMsg.m_senderID
              >>ctlMsg.m_receivedID
              >>ctlMsg.m_commandID
              >>ctlMsg.m_activateEMU
              >>ctlMsg.m_activateMotorActualtor
              >>ctlMsg.m_firingAngleNx2
              >>ctlMsg.m_firingAngleNy2
              >>ctlMsg.m_firingAngleNz2
              >>ctlMsg.m_range
              >>ctlMsg.m_stopFiring
              >>ctlMsg.m_fireModeRocketSelection
              >>ctlMsg.m_signalForRingButtonBuzzer
              >>ctlMsg.m_trainingWithDrive
              >>ctlMsg.m_trainingMode
              >>ctlMsg.m_reserved3
              >>ctlMsg.m_reserved4
              >>ctlMsg.m_messageCounter
              >>ctlMsg.m_messageValidity
              >>ctlMsg.m_footer;

     //
     m_commandID = ctlMsg.m_commandID;
     m_receivedMSGCounter = ctlMsg.m_messageCounter;
     m_fireModeRocketSelection = ctlMsg.m_fireModeRocketSelection;//
     //
     if(m_flagSendStatusMsg==false)
     {
         m_timerStatusMsg->start();
         m_flagSendStatusMsg = true;
     }

     // cap nhat bang nhan
     // number
      QString tt = QString::number(m_tableRcvRowCount);
     // get current time
     QDateTime time = QDateTime::currentDateTime();
     QString str_time = time.toString("hh:mm:ss.zzz");
     // SRC
     QString str_src = m_ipRemote->toString()+":" + QString::number(m_portRemote);
     // DESTN
     QString str_destn = m_ipLocal->toString() + ":" + QString::number(m_portReceiveLocal);
     // convert QByteArray
     QString str_data;
     str_data="";
     for(int i=0;i<datagram.count();i++)
        {
            QByteArray byte_i = datagram.mid(i,1);
            QString strbyte_i = byte_i.toHex() +" ";
            str_data.append(strbyte_i);
        };
     // lenght
     QString str_lenght = QString::number(datagram.size());
     // add new row to table
     // <<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght;

     ui->ctl_tableRciv->setRowCount(m_tableRcvRowCount+1);
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,0, new QTableWidgetItem(tt));
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,1, new QTableWidgetItem(str_time));
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,2, new QTableWidgetItem(str_src));
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,3, new QTableWidgetItem(str_destn));
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,4, new QTableWidgetItem(str_data));
     ui->ctl_tableRciv->setItem(m_tableRcvRowCount,5, new QTableWidgetItem(str_lenght));
     m_tableRcvRowCount++;
     // log to console
     qDebug() << "Receive msg: "<< str_data;
     // send data to NIHAN
     // tinh message couter cua goi tin vua nhan duoc
//     QByteArray arrayCouter;
//     arrayCouter.resize(4);
//     arrayCouter[0] = datagram[28];
//     arrayCouter[1] = datagram[29];
//     arrayCouter[2] = datagram[30];
//     arrayCouter[3] = datagram[31];
//     QDataStream streamIN(&arrayCouter, QIODevice::ReadOnly);
//     unsigned int couter;
//     streamIN >> couter;
//     // tinh Fire mode / Rocket selection
//     QByteArray arrayFiremode;
//     arrayFiremode.resize(1);
//     arrayFiremode[0] = datagram[18];
//     QDataStream streamINFireMode(&arrayFiremode, QIODevice::ReadOnly);
//     unsigned short int firemode;
//     streamINFireMode>> firemode;
//     m_statusMsgCouter +=1;
     //f_sendMSG(couter,firemode,m_statusMsgCouter);
     } else

     {
         return;
     }
}

void MainWindow::f_sendMSG(MSG_BCC6000STA msg,QHostAddress *remoteAdd,int remotePort)
{
    QByteArray msgByte;
    //QByteArray datagram_out;
    QDataStream stream(&msgByte, QIODevice::WriteOnly);
    stream  <<msg.m_header
            <<msg.m_senderID
            <<msg.m_receivedID
            <<msg.m_statusDataID
            <<msg.m_commandID
            <<msg.m_receivedMSGCounter
            <<msg.m_insulationCheckStatus
            <<msg.m_fireModeRocketSelection
            <<msg.m_azimuthFiringAngle
            <<msg.m_statusIndicator1
            <<msg.m_statusIndicator2
            <<msg.m_testResultForSelfTest
            <<msg.m_errorCode
            <<msg.m_fireCircuitCheck
            <<msg.m_reserved2
            <<msg.m_reserved3
            <<msg.m_reserved4
            <<msg.m_messageCounter
            <<msg.m_footer;

    int send = m_socketSendLocal->writeDatagram(msgByte,*remoteAdd,remotePort);
    if(send==-1)
    {
        qDebug() << "Send msg error";
    }
    else
    {
        // cap nhat bang
        // cap nhat bang gui
        // number
         QString tt = QString::number(m_tableSendRowCount);
        // get current time
        QDateTime time = QDateTime::currentDateTime();
        QString str_time = time.toString("hh:mm:ss.zzz");
        // SRC
        QString str_src = m_ipLocal->toString()+":" + QString::number(m_portSendLocal);
        // DESTN
        QString str_destn = remoteAdd->toString() + ":" + QString::number(remotePort);
        // convert QByteArray
        QString str_data;
        str_data="";
        for(int i=0;i<msgByte.count();i++)
           {
               QByteArray byte_i = msgByte.mid(i,1);
               QString strbyte_i = byte_i.toHex() +" ";
               str_data.append(strbyte_i);
           };
        // lenght
        QString str_lenght = QString::number(msgByte.size());
        // add new row to table
        // <<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght;

        ui->ctl_tableSend->setRowCount(m_tableSendRowCount+1);
        ui->ctl_tableSend->setItem(m_tableSendRowCount,0, new QTableWidgetItem(tt));
        ui->ctl_tableSend->setItem(m_tableSendRowCount,1, new QTableWidgetItem(str_time));
        ui->ctl_tableSend->setItem(m_tableSendRowCount,2, new QTableWidgetItem(str_src));
        ui->ctl_tableSend->setItem(m_tableSendRowCount,3, new QTableWidgetItem(str_destn));
        ui->ctl_tableSend->setItem(m_tableSendRowCount,4, new QTableWidgetItem(str_data));
        ui->ctl_tableSend->setItem(m_tableSendRowCount,5, new QTableWidgetItem(str_lenght));
        m_tableSendRowCount++;
        // log to console
        qDebug() << "Receive msg: "<< str_data;
    }
}

void MainWindow::s_sendMSG()
{
    unsigned short int m_header = 0x5A5A;
    unsigned short int m_senderID = 0x0105;
    unsigned short int m_receivedID = 0x0001;
    unsigned short int m_statusDataID = 0x0001;
    unsigned short int m_commandID = 0x0001;
    unsigned int m_receivedMSGCounter = 0x0000;
    unsigned short int m_RLMode = 0x0001;
    unsigned short int m_fireModeRocketSelection = 0x41;
    unsigned short int m_azimuthFiringAngle = 45;
    unsigned short m_statusIndicator1 =0x01;
    unsigned short m_statusIndicator2 = 0x02;
    unsigned char m_testResultForSelfTest = 0x01;
    unsigned short m_errorCode = 18;
    unsigned short int m_reserved1 =0x0000 ;
    unsigned short int m_reserved2=0x0000;
    unsigned short int m_reserved3=0x0000;
    unsigned short int m_reserved4=0x0000;
    unsigned int m_messageCounter =0x0001;
    unsigned short int m_footer = 0xA5A5;
//    QMessageBox mesage;
//    mesage.setText("Send status msg");
//    mesage.exec();
    QByteArray msg;
    //QByteArray datagram_out;
    QDataStream out(&msg, QIODevice::WriteOnly);
    out <<m_header<< m_senderID << m_receivedID << m_statusDataID<<m_commandID<<m_receivedMSGCounter<<m_RLMode
          <<m_fireModeRocketSelection<<m_azimuthFiringAngle<<m_statusIndicator1<<m_statusIndicator2
            <<m_testResultForSelfTest<<m_errorCode<<m_reserved1<<m_reserved2<<m_reserved3
              <<m_reserved4<<m_messageCounter<<m_footer;

    int send = m_socketSendLocal->writeDatagram(msg,*m_ipRemote,m_portRemote);
    if(send==-1)
    {
        qDebug() << "Send msg error";
    }
    else
    {
        qDebug() << "Send msg: "<<QString::number(send)<<" [bytes]";
    }

}

void MainWindow::sl_sendStatusMsg()
{
    // chuan bi goi tin status msg
    MSG_BCC6000STA msg;
    // status msg
    msg.m_header = 0x5A5A;
    msg.m_senderID = 0x0105;
    msg.m_receivedID = 0x0001;
    msg.m_statusDataID = 0x0001;
    msg.m_commandID = m_commandID;
    msg.m_receivedMSGCounter = m_receivedMSGCounter;
    msg.m_insulationCheckStatus = 0x0001;
    msg.m_fireModeRocketSelection = m_fireModeRocketSelection;//
    msg.m_azimuthFiringAngle = 0x0001;
    msg.m_statusIndicator1 =0x01;
    msg.m_statusIndicator2 = 0x0002;
    msg.m_testResultForSelfTest = 0x01;
    msg.m_errorCode = 0x0000;
    msg.m_fireCircuitCheck = 0x0001;
    msg.m_reserved2=0x0000;
    msg.m_reserved3=0x0000;
    msg.m_reserved4=0x0000;
    msg.m_messageCounter = m_msgSendCounter++;
    msg.m_footer = 0xA5A5;
    f_sendMSG(msg,m_ipRemote,m_portRemote);
}

void MainWindow::f_readConfigFile(QString pathFile)
{

}

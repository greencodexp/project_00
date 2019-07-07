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
    tableRowCount = 0;
    // init socket
    // port
    m_portSendFCS = 6230;
    m_portReceiveFCS = 6231;
    m_portSendLocal = 6230;
    m_portReceiveLocal = 6231;
    // ip
    m_ipLocal = new QHostAddress("127.0.0.1");
    m_ipFCC = new QHostAddress("192.168.1.100");
    m_ipRFC = new QHostAddress("192.168.1.99");
    // udpclient

    m_socketSendLocal = new QUdpSocket(this);
    m_socketSendLocal->bind(*m_ipLocal,m_portSendLocal);

    m_socketRecieveLocal = new QUdpSocket(this);
    m_socketRecieveLocal->bind(*m_ipLocal,m_portReceiveLocal);

    m_socketFCC = new QUdpSocket(this);
    m_socketFCC->bind(*m_ipFCC,m_portSendFCS);

    m_socketRFC = new QUdpSocket(this);
    m_socketRFC->bind(*m_ipFCC,m_portSendFCS);
    // connection
    connect(m_socketRecieveLocal,SIGNAL(readyRead()), this, SLOT(s_receiveMSG()));
//    connect(m_socketSendLocal,SIGNAL(se))
}

void MainWindow::f_setUpLayout()
{
    // message type
    ui->ctl_cbSendMSGTypeFCC->addItem("Message 1");
    ui->ctl_cbSendMSGTypeFCC->addItem("Message 2");
    ui->ctl_cbSendMSGTypeFCC->addItem("Message 3");
    ui->ctl_cbSendMSGTypeFCC->addItem("Message 4");

    ui->ctl_cbSendMSGTypeRFC->addItem("Message 1");
    ui->ctl_cbSendMSGTypeRFC->addItem("Message 2");
    ui->ctl_cbSendMSGTypeRFC->addItem("Message 3");
    ui->ctl_cbSendMSGTypeRFC->addItem("Message 4");

    //------------------------------------------ IP QLineEdit
    QRegExpValidator *v = new QRegExpValidator(this);
    QRegExp rx("((1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})\\.){3,3}(1{0,1}[0-9]{0,2}|2[0-4]{1,1}[0-9]{1,1}|25[0-5]{1,1})");
    v->setRegExp(rx);
    ui->ctl_IP_BCC->setValidator(v);
    ui->ctl_IP_FCC->setValidator(v);
    ui->ctl_IP_RFC->setValidator(v);




    // socket config
    ui->ctl_IP_BCC->setText("127.0.0.1");
    ui->ctl_IP_FCC->setText("127.0.0.1");
    ui->ctl_IP_RFC->setText("127.0.0.1");

    ui->ctl_portBCC->setText("6231");
    ui->ctl_portFCC->setText("6230");
    ui->ctl_portRFC->setText("6230");


//    ui->ctl_tableFFC->setRowCount(100);

    // config log FFC table
    ui->ctl_tableFCC->setColumnCount(6);
    QStringList m_TableHeader;
    m_TableHeader<<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght";
    ui->ctl_tableFCC->setHorizontalHeaderLabels(m_TableHeader);
    ui->ctl_tableFCC->verticalHeader()->setVisible(false);
    ui->ctl_tableFCC->setColumnWidth(0,40);
    ui->ctl_tableFCC->setColumnWidth(1,100);
    ui->ctl_tableFCC->setColumnWidth(2,100);
     ui->ctl_tableFCC->setColumnWidth(3,100);
    ui->ctl_tableFCC->setColumnWidth(4,300);
     ui->ctl_tableFCC->setColumnWidth(5,40);

    //
    // config log RFC table
    ui->ctl_tableRFC->setColumnCount(5);
    m_TableHeader<<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA"<<"Lenght";
    ui->ctl_tableRFC->setHorizontalHeaderLabels(m_TableHeader);
    ui->ctl_tableRFC->verticalHeader()->setVisible(false);
    ui->ctl_tableRFC->setColumnWidth(0,40);
    ui->ctl_tableRFC->setColumnWidth(1,100);
    ui->ctl_tableRFC->setColumnWidth(2,100);
     ui->ctl_tableRFC->setColumnWidth(3,100);
    ui->ctl_tableRFC->setColumnWidth(4,300);
    ui->ctl_tableRFC->setColumnWidth(5,40);

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

void MainWindow::s_receiveMSG()
{
    // number
     QString tt = QString::number(tableRowCount);
    // get current time
    QDateTime time = QDateTime::currentDateTime();
    QString str_time = time.toString("hh:mm:ss.zzz");
    // SRC
    QString str_src = m_ipFCC->toString()+":" + QString::number(m_portSendFCS);
    // DESTN
    QString str_destn = m_ipLocal->toString() + ":" + QString::number(m_portReceiveLocal);
    //DATA
     QByteArray datagram;
     datagram.resize(m_socketRecieveLocal->pendingDatagramSize());
     m_socketRecieveLocal->readDatagram(datagram.data(), datagram.size());
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


     ui->ctl_tableFCC->setRowCount(tableRowCount+1);
     ui->ctl_tableFCC->setItem(tableRowCount,0, new QTableWidgetItem(tt));
     ui->ctl_tableFCC->setItem(tableRowCount,1, new QTableWidgetItem(str_time));
     ui->ctl_tableFCC->setItem(tableRowCount,2, new QTableWidgetItem(str_src));
     ui->ctl_tableFCC->setItem(tableRowCount,3, new QTableWidgetItem(str_destn));
     ui->ctl_tableFCC->setItem(tableRowCount,4, new QTableWidgetItem(str_data));
     ui->ctl_tableFCC->setItem(tableRowCount,5, new QTableWidgetItem(str_lenght));
     tableRowCount++;
     // log to console
     qDebug() << "Receive msg: "<< str_data;
}

void MainWindow::s_sendMSG()
{

}

void MainWindow::f_readConfigFile(QString pathFile)
{

}

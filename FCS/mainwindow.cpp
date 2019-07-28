#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f_Init();
    f_SetupLayout();
    //f_getSocketConfBCC();
    //m_timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::f_Init()
{
    m_portFCS = 6230;
    m_portBCC = 6231;
    m_ipFCS = new QHostAddress("192.168.2.10");
    m_ipBCC = new QHostAddress("192.168.2.11");

    m_socketFCS = new QUdpSocket(this);
    m_socketFCS->bind(*m_ipFCS,m_portFCS);

    //m_socketBCC = new QUdpSocket(this);
    //m_socketBCC->bind(*m_ipBCC,m_portBCC);
    // init timer
    m_timer = new QTimer(this);
    m_timer->setInterval(20);
    // connect
    connect(ui->ctl_btnSend,SIGNAL(clicked(bool)),this,SLOT(f_send()));    
    connect(ui->ctl_btnAutoTest,SIGNAL(clicked(bool)),m_timer,SLOT(start()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(f_send()));
    //connect ()
}
void MainWindow::f_SetupLayout()
{
    ui->ctl_cbMSGType->addItem("Message 1");
    ui->ctl_cbMSGType->addItem("Message 2");
    ui->ctl_cbMSGType->addItem("Message 3");
    ui->ctl_cbMSGType->addItem("Message 4");

    // config log table
    ui->ctl_tableFCS->setColumnCount(5);
    QStringList m_TableHeader;
    m_TableHeader<<"#"<<"Time"<<"SRC"<<"DESTN"<<"DATA";
    ui->ctl_tableFCS->setHorizontalHeaderLabels(m_TableHeader);
    ui->ctl_tableFCS->verticalHeader()->setVisible(false);
    ui->ctl_tableFCS->setColumnWidth(0,40);
    ui->ctl_tableFCS->setColumnWidth(1,100);
    ui->ctl_tableFCS->setColumnWidth(2,100);
     ui->ctl_tableFCS->setColumnWidth(3,100);
    ui->ctl_tableFCS->setColumnWidth(4,300);

    // layout config tab
    ui->ctl_IP_BCC->setText("127.0.0.1");
    ui->ctl_IP_FCS->setText("127.0.0.1");
    ui->ctl_portBCC->setText("6231");
    ui->ctl_portFCS->setText("6230");
}

void MainWindow::f_getSocketConfBCC()
{
    // get ip
    QString ipadd = ui->ctl_IP_BCC->text();
    ipadd = ipadd.simplified();
    ipadd.replace( " ", "" );
    m_ipBCC->setAddress(ipadd);
    // get port
    QString port = ui->ctl_portBCC->text();
    port = port.simplified();
    port.replace( " ", "" );
    bool ok;
    m_portBCC = port.toInt(&ok,10);
}

void MainWindow::f_getSocketConfFCS()
{
}
void MainWindow::f_send()
{
    QByteArray msg;
    msg.resize(5);
    msg[0] = 0x01;
    msg[1] = 0x02;
    msg[2] = 0x03;
    msg[3] = 0x04;
    msg[4] = 0x05;
    for(int i=0;i<1000;i++)
    {

    int send = m_socketFCS->writeDatagram(msg,*m_ipBCC,m_portBCC);
    if(send==-1)
    {
        qDebug() << "Send msg error";
    }
    else
    {
        qDebug() << "Send msg: "<<QString::number(send)<<" [bytes]";
    }
    }
}

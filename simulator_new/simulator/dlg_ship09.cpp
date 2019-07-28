#include "dlg_ship09.h"
#include "ui_dlg_ship09.h"
#include "QMessageBox"
Dlg_ship09::Dlg_ship09(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_ship09)
{
    ui->setupUi(this);
    f_Init();
}

Dlg_ship09::~Dlg_ship09()
{
    delete ui;
}

void Dlg_ship09::f_Init()
{
    //init
    m_flagB2500Selected = 0; // no B2500 is selected
    // port

    m_portSendLocal = 6230;
    m_portRecivLocal =6231;
    m_portRecivB2500 = 6230;
    m_portSendB2500 = 6231;
    // ip
    // NIHAN FCS(FCC) = 192.168.1.100
    // NIHAN FCS(RFC) = 192.168.1.99
    m_addLocal = new QHostAddress("192.168.1.100");
    m_addB2500_1 = new QHostAddress("192.168.1.101");
    m_addB2500_2 = new QHostAddress("192.168.1.102");
    m_addB2500_3 = new QHostAddress("192.168.1.103");
    m_addB2500_4 = new QHostAddress("192.168.1.104");
    // udpclient
    m_socketLocalSend = new QUdpSocket(this);
    m_socketLocalSend->bind(*m_addLocal,m_portSendLocal);
    m_socketLocalReciv = new QUdpSocket(this);
    m_socketLocalReciv->bind(*m_addLocal,m_portRecivLocal);
    // connection
    connect(ui->ctl_btnSend,SIGNAL(clicked(bool)),this,SLOT(f_sendCntrlMsg()));
    connect(ui->ctl_btnB2500_1,SIGNAL(clicked(bool)),this,SLOT(f_setB2500_1_Selected()));
    connect(ui->ctl_btnB2500_2,SIGNAL(clicked(bool)),this,SLOT(f_setB2500_2_Selected()));
    connect(ui->ctl_btnB2500_3,SIGNAL(clicked(bool)),this,SLOT(f_setB2500_3_Selected()));
    connect(ui->ctl_btnB2500_4,SIGNAL(clicked(bool)),this,SLOT(f_setB2500_4_Selected()));
    // set up layout
    ui->ctl_chkEMUDeactive->isChecked();
    ui->ctl_chkMotorDeactive->isChecked();
    ui->ctl_chkMsgValid->isChecked();
    ui->ctl_chkRingNotPressed->isChecked();
}

void Dlg_ship09::f_sendCntrlMsg()
{
    if(m_flagB2500Selected==0)
    {
        QMessageBox msgBox;
        msgBox.setText("Select B2500 to send control message");
        msgBox.exec();
        return;
    } else
    {
        QByteArray msg = f_getCntrlMsg();
        if(m_flagB2500Selected==1)
        {
            int lenght = m_socketLocalSend->writeDatagram(msg,*m_addB2500_1,m_portRecivB2500);
            qDebug() << "Send control msg to B2500_1: lenght = "<< QString::number(lenght);
        }
        if(m_flagB2500Selected==2)
        {
            int lenght = m_socketLocalSend->writeDatagram(msg,*m_addB2500_2,m_portRecivB2500);
            qDebug() << "Send control msg to B2500_2: lenght = "<< QString::number(lenght);
        }
        if(m_flagB2500Selected==3)
        {
            int lenght = m_socketLocalSend->writeDatagram(msg,*m_addB2500_3,m_portRecivB2500);
            qDebug() << "Send control msg to B2500_3: lenght = "<< QString::number(lenght);
        }
        if(m_flagB2500Selected==4)
        {
            int lenght = m_socketLocalSend->writeDatagram(msg,*m_addB2500_4,m_portRecivB2500);
            qDebug() << "Send control msg to B2500_4: lenght = "<< QString::number(lenght);
        }
    }
}

void Dlg_ship09::f_setB2500_1_Selected()
{
    m_flagB2500Selected =1;
    //
    ui->ctl_btnB2500_1->setStyleSheet("background-color: rgb(169,171,174);");
    ui->ctl_btnB2500_2->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_3->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_4->setStyleSheet("background-color: rgb(254,254,254);");
}
void Dlg_ship09::f_setB2500_2_Selected()
{
    m_flagB2500Selected =2;
    //
    ui->ctl_btnB2500_2->setStyleSheet("background-color: rgb(169,171,174);");
    ui->ctl_btnB2500_1->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_3->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_4->setStyleSheet("background-color: rgb(254,254,254);");
}
void Dlg_ship09::f_setB2500_3_Selected()
{
    m_flagB2500Selected =3;
    //
    ui->ctl_btnB2500_3->setStyleSheet("background-color: rgb(169,171,174);");
    ui->ctl_btnB2500_1->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_2->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_4->setStyleSheet("background-color: rgb(254,254,254);");
}
void Dlg_ship09::f_setB2500_4_Selected()
{
    m_flagB2500Selected =4;
    //
    ui->ctl_btnB2500_4->setStyleSheet("background-color: rgb(169,171,174);");
    ui->ctl_btnB2500_2->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_3->setStyleSheet("background-color: rgb(254,254,254);");
    ui->ctl_btnB2500_1->setStyleSheet("background-color: rgb(254,254,254);");
}

void Dlg_ship09::f_sendSelfTestMsg(QByteArray msg)
{

}

QByteArray Dlg_ship09::f_getCntrlMsg()
{
    QByteArray msg;
    QDataStream out(&msg, QIODevice::WriteOnly);
    // 1 Header 0x5A5A 2 bytes
    unsigned short int m_header = 0x5A5A;
    out<< m_header;
    // 2 Sender ID
    unsigned short int m_senderID = 0x0001;
    out<< m_senderID;
    // 3 Receiver ID
     unsigned short int m_receiverID;
     if(m_flagB2500Selected==1)
     {
         m_receiverID = 0x0101;
     }
     if(m_flagB2500Selected==2)
     {
         m_receiverID = 0x0102e;
     }
     if(m_flagB2500Selected==3)
     {
         m_receiverID = 0x0103;
     }
     if(m_flagB2500Selected==4)
     {
         m_receiverID = 0x0104;
     }
     out<<m_receiverID;
     // 4 Command ID
     unsigned short int m_commandID = 0x0001;
     out<<m_commandID;
     // 5 Active EMU
     unsigned char m_activateEMU;
     if(ui->ctl_chkEMUActive->isChecked())
     {
         m_activateEMU = 0x0001;
     }
     if(ui->ctl_chkEMUDeactive->isChecked())
     {
         m_activateEMU = 0x0000;
     }
     out<< m_activateEMU;
     // 6 Activate motor actuator
     unsigned char m_activateMotor;
     if(ui->ctl_chkMotorActive->isChecked())
     {
         m_activateMotor = 0x0001;
     }
     if(ui->ctl_chkMotorDeactive->isChecked())
     {
         m_activateMotor = 0x0000;
     }
     out<<m_activateMotor;
     // 7 Firing angle Nx2 signal
     unsigned short int m_fireAngleNx2;
     double res_mag = pow(2,15) -1;
     double Nt = qCos(ui->ctl_lneAngleAlpha->text().toDouble()*M_PI/360);
     double Nx = Nt*qCos(ui->ctl_lneAngleGamma->text().toDouble()*M_PI/360);
     double Nz = Nt*qSin(ui->ctl_lneAngleGamma->text().toDouble()*M_PI/360);
     double Nx2 = Nx * qCos(ui->ctl_lneAnglePsi->text().toDouble()*M_PI/360) + Nz* qSin(ui->ctl_lneAnglePsi->text().toDouble()*M_PI/360);
     int signNx2;
     if(Nx2<1)
     {
         signNx2 = 1;
     }else
     {
         signNx2 =0;
     }     
     Nx2= fabs(Nx2);
     unsigned short magNx2 = (unsigned short)(Nx2*res_mag);
     unsigned short Nx2Signal = magNx2;
     if(signNx2==1)
     {
         Nx2Signal = Nx2Signal | 0x8000;
     }
     m_fireAngleNx2 = Nx2Signal;
     out<<m_fireAngleNx2;
     // 8 Firing angle Ny2 signal
     unsigned short int m_fireAngleNy2;
     int signNy2;
     double Ny1 = Nt*qSin(ui->ctl_lneAngleGamma->text().toDouble()*M_PI/360);
     double Nz1 = Nz* qCos(ui->ctl_lneAnglePsi->text().toDouble()*M_PI/360) - Nx* qSin(ui->ctl_lneAnglePsi->text().toDouble()*M_PI/360);
     double Ny2 = Ny1*qCos(ui->ctl_lneAngleTeta->text().toDouble()*M_PI/360) - Nz1*qSin(ui->ctl_lneAngleTeta->text().toDouble()*M_PI/360);

     if(Ny2<1)
     {
         signNy2 = 1;
     }else
     {
         signNy2 =0;
     }
     Ny2= fabs(Ny2);
     unsigned short magNy2 = (unsigned short)(Ny2*res_mag);
     unsigned short Ny2signal = magNy2;
     if(signNy2==1)
     {
         Ny2signal = Ny2signal|0x8000;
     }
     m_fireAngleNy2 = Ny2signal;
     out<<m_fireAngleNy2;
     // 9 Firing angle Nz2 signal
     unsigned short int m_fireAngleNz2;
     int signNz2;
     double Nz2 = Nz1* qCos(ui->ctl_lneAngleTeta->text().toDouble()*M_PI/360) + Ny1* qSin(ui->ctl_lneAngleTeta->text().toDouble()*M_PI/360);

     if(Nz2<1)
     {
         signNz2 = 1;
     }else
     {
         signNz2 =0;
     }
     Nz2= fabs(Nz2);
     unsigned short magNz2 = (unsigned short)(Nz2*res_mag);
     unsigned short Nz2signal = magNz2;
     if(signNz2==1)
     {
         Nz2signal = Nz2signal|0x8000;
     }
     m_fireAngleNz2 = Nz2signal;
     out<<m_fireAngleNz2;
     // 10 Fire mode / Rocket selection
     unsigned short int m_rocketSelection;
     if(ui->ctl_cmbRocketSelection->currentIndex()==0)
     {
         m_rocketSelection = 0x0000;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==1)
     {
         m_rocketSelection = 0x0106;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==2)
     {
         m_rocketSelection = 0x0086;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==3)
     {
         m_rocketSelection = 0x0046;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==4)
     {
         m_rocketSelection = 0x0027;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==5)
     {
         m_rocketSelection = 0x0017;
     }
     if(ui->ctl_cmbRocketSelection->currentIndex()==6)
     {
         m_rocketSelection = 0x000F;
     }
     out<<m_rocketSelection;
     // 11 ctl_chkRingPressed Signal for RING button/Buzzer
     unsigned char m_signalForRing;
     if(ui->ctl_chkRingPressed->isChecked())
     {
         m_signalForRing = 0x01;
     }
     if(ui->ctl_chkRingNotPressed->isChecked())
     {
         m_signalForRing = 0x00;
     }
     out<< m_signalForRing;
     // 12 Reserved 1
     unsigned short int m_reserved_1 = 0x00;
     out<<m_reserved_1;
     // 13 Reserved 2
     unsigned short int m_reserved_2 = 0x00;
     out<<m_reserved_2;
     // 14 Reserved 3
     unsigned short int m_reserved_3 = 0x00;
     out<<m_reserved_3;
     // 15 Reserved 4
     unsigned short int m_reserved_4 = 0x00;
     out<<m_reserved_4;
     // 16 Message Counter // 0x0000 0001 - 0xffff ffff
     unsigned int m_msgCounter = 0x00;
     out<<m_msgCounter;
     // 17 Message validity
     unsigned char m_msgValidity;
     if(ui->ctl_chkMsgValid->isChecked())
     {
         m_msgValidity = 0x01;
     }
     if(ui->ctl_chkMsgInvalid->isChecked())
     {
         m_msgValidity = 0x00;
     }
     out<<m_msgValidity;
     // 18 Footer
     unsigned short int m_footer;
     m_footer = 0xA5A5;
     out<< m_footer;
     return msg;
}

void Dlg_ship09::f_readConfigFile(QString path)
{

}

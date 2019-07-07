#ifndef CGLOBAL_H
#define CGLOBAL_H

#include <QObject>
struct MSG_BCC6000CTL
{
    MSG_BCC6000CTL() {
        unsigned short int m_header;
        unsigned short int m_senderID;
        unsigned short int m_receivedID;
        unsigned short int m_commandID;
        unsigned char m_activateEMU;
        unsigned char m_activateMotorActualtor;
        unsigned short int m_firingAngleNx2;
        unsigned short int m_firingAngleNy2;
        unsigned short int m_firingAngleNz2;
        unsigned char m_range;
        unsigned char m_stopFiring;
        unsigned char m_fireModeRocketSelection;
        unsigned char m_signalForRingButtonBuzzer;
        unsigned short int m_reserved1;
        unsigned short int m_reserved2;
        unsigned short int m_reserved3;
        unsigned short int m_reserved4;
        unsigned int m_messageCounter;
        unsigned int m_messageValidity;
        unsigned short int m_footer;
    }
};
struct MSG_BCC6000SFT
{
    MSG_BCC6000SFT() {
        unsigned short int m_header;
        unsigned short int m_senderID;
        unsigned short int m_receivedID;
        unsigned short int m_commandID;
        unsigned char m_launcherSelfTest;
        unsigned int m_messageCounter;
        unsigned char m_messageValidity;
        unsigned short int m_footer;
    }
};
struct MSG_BCC6000STA
{
    MSG_BCC6000STA() {
        unsigned short int m_header;
        unsigned short int m_senderID;
        unsigned short int m_receivedID;
        unsigned short int m_statusDataID;
        unsigned short int m_commandID;
        unsigned int m_receivedMSGCounter;
        unsigned short int m_RLMode;
        unsigned short int m_fireModeRocketSelection;
        unsigned short int m_azimuthFiringAngle;
        unsigned short m_statusIndicator1;
        unsigned short m_statusIndicator2;
        unsigned char m_testResultForSelfTest;
        unsigned short m_errorCode;
        unsigned short int m_reserved1;
        unsigned short int m_reserved2;
        unsigned short int m_reserved3;
        unsigned short int m_reserved4;
        unsigned int m_messageCounter;
        unsigned short int m_footer;

    }
};
class CGlobal : public QObject
{
    Q_OBJECT
public:
    explicit CGlobal(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CGLOBAL_H

#ifndef CGLOBAL_H
#define CGLOBAL_H
struct MSG_BCC6000CTL
{
        //1
        unsigned short int m_header; // 2
        //2
        unsigned short int m_senderID; //2
        //2
        unsigned short int m_receivedID;// 2
        //2
        unsigned short int m_commandID;// 2
        //2
        unsigned char m_activateEMU;// 1
        //2
        unsigned char m_activateMotorActualtor; ///1
        //2
        unsigned short int m_firingAngleNx2;//2
        //2
        unsigned short int m_firingAngleNy2;//2
        //2
        unsigned short int m_firingAngleNz2;//2
        //2
        unsigned char m_range;//1
        //2
        unsigned char m_stopFiring;//1
        //2
        unsigned char m_fireModeRocketSelection;//1
        //2
        unsigned char m_signalForRingButtonBuzzer;//1
        // 14
        unsigned short int m_trainingWithDrive;//2
        // 15
        unsigned short int m_trainingMode;//2
        //16
        unsigned short int m_reserved3;//2
        //17
        unsigned short int m_reserved4;//2
        //18
        unsigned int m_messageCounter;//4
        //19
        unsigned char m_messageValidity;//1
        //20
        unsigned short int m_footer;//2
        // tatol 35 byte
};
struct MSG_BCC6000SFT
{
        unsigned short int m_header;
        unsigned short int m_senderID;
        unsigned short int m_receivedID;
        unsigned short int m_commandID;
        unsigned char m_launcherSelfTest;
        unsigned int m_messageCounter;
        unsigned char m_messageValidity;
};
struct MSG_BCC6000STA
{
    // status msg
    unsigned short int m_header;
    unsigned short int m_senderID;
    unsigned short int m_receivedID;
    unsigned short int m_statusDataID ;
    unsigned short int m_commandID;
    unsigned int m_receivedMSGCounter;
    unsigned short int m_insulationCheckStatus ;
    unsigned short int m_fireModeRocketSelection ;//
    unsigned short int m_azimuthFiringAngle ;
    unsigned char m_statusIndicator1 ;
    unsigned short int m_statusIndicator2 ;
    unsigned char m_testResultForSelfTest;
    unsigned short int m_errorCode ;
    unsigned short int m_fireCircuitCheck ;
    unsigned short int m_reserved2;
    unsigned short int m_reserved3;
    unsigned short int m_reserved4;
    unsigned int m_messageCounter;
    unsigned short int m_footer;
};
class CGlobal
{
public:
    CGlobal();
};

#endif // CGLOBAL_H

#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QObject>
#include <QByteArray>
class CMessage: public QObject
{    
    Q_OBJECT
public:
    CMessage();
    QByteArray m_data;
};

#endif // CMESSAGE_H

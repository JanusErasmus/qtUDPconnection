#ifndef UDPCONNECT_H
#define UDPCONNECT_H

#include <QObject>
#include <QUdpSocket>
#include <QMutex>
#include <QWaitCondition>

#include "duplexinterface.h"

class UDPconnect : public QObject, public duplexInterface
{
    Q_OBJECT

    QUdpSocket *mSocket;
    bool mConnected;

    QMutex mMutex;
    QWaitCondition mWait;
    uint8_t mRXbuffer[256];
    int mRXlen;

public:
    explicit UDPconnect(QString server, quint16 port = 7777);
    virtual ~UDPconnect();

    int transmit(uint8_t * buff, int len);
    int receive(uint8_t * buff, int buff_len, int timeout = 5000);

signals:

public slots:
    void readyRead();

};

class UDPconnectConnectException
{
public:
    UDPconnectConnectException(){}
};

#endif // UDPCONNECT_H

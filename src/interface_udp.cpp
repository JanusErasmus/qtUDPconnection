#include <QDebug>
#include <QHostInfo>

#include "interface_udp.h"

UDPconnect::UDPconnect(QString server, quint16 port) :
    QObject(0)
{    
    mRXlen = 0;
    mConnected = false;
    mSocket = new QUdpSocket();
    connect(mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    mSocket->connectToHost(server, port);
    if(!mSocket->waitForConnected(5000))
    {
        throw UDPconnectConnectException();
    }

    if(mSocket->state() != QAbstractSocket::ConnectedState)
    {
        throw UDPconnectConnectException();
    }

    mConnected = true;

    qDebug() << "Connected to host state: " << mSocket->state();
}

int UDPconnect::transmit(uint8_t * buff, int len)
{
    if(!mConnected)
        return -1;

    return mSocket->write((const char*)buff, len );
}


int UDPconnect::receive(uint8_t * buff, int buff_len, int timeout)
{
    if(!mConnected)
        return -1;

    int rxLen = -1;
    mMutex.lock();
    if(mWait.wait(&mMutex, timeout))
    {
        if(mRXlen > buff_len)
            mRXlen = buff_len;

        memcpy(buff, mRXbuffer, mRXlen);
        rxLen = mRXlen;
    }

    mMutex.unlock();

    return rxLen;
}

void UDPconnect::readyRead()
{
    mMutex.lock();
    mRXlen = mSocket->pendingDatagramSize();
    //qDebug() << " RX data" << mRXlen;
    mSocket->read((char*)mRXbuffer, mRXlen);
    mWait.wakeAll();
    mMutex.unlock();
}

UDPconnect::~UDPconnect()
{
    if(mSocket)
    {
        mSocket->disconnect();
        delete mSocket;
    }
}

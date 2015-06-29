#include <QDebug>
#include <QHostInfo>

#include "udpconnect.h"

UDPconnect::UDPconnect(QString server, quint16 port) :
    QObject(0)
{    
    mConnected = false;
    mSocket = new QUdpSocket();
    connect(mSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(error(QAbstractSocket::SocketError)));
    connect(mSocket, SIGNAL(hostFound()), SLOT(hostfount()));
    connect(mSocket, SIGNAL(connected()), SLOT(connected()));
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

int UDPconnect::transmit(char * string)
{
    if(!mConnected)
        return -1;

    QByteArray Data;
    Data.append(string);
    return mSocket->write(Data);
}

void UDPconnect::error(QAbstractSocket::SocketError e)
{
    qDebug() << "UDPconnect ERROR " << e;
}

void UDPconnect::hostfount()
{
qDebug() << "Host found";
}

void UDPconnect::connected()
{
    qDebug() << "Connected to host";
}

void UDPconnect::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(mSocket->pendingDatagramSize());

    mSocket->read(buffer.data(), buffer.size());

    qDebug() << "Message: " << buffer;
}

UDPconnect::~UDPconnect()
{
    if(mSocket)
    {
        mSocket->disconnect();
        delete mSocket;
    }
}

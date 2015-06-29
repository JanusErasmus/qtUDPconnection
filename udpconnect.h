#ifndef UDPCONNECT_H
#define UDPCONNECT_H

#include <QObject>
#include <QUdpSocket>

class UDPconnect : public QObject
{
    Q_OBJECT

    QUdpSocket *mSocket;
    bool mConnected;

public:
    explicit UDPconnect(QString server, quint16 port = 7777);
    virtual ~UDPconnect();

    int transmit(char * string);

signals:

public slots:
    void hostfount();
    void connected();
    void readyRead();
    void error(QAbstractSocket::SocketError);

};

class UDPconnectConnectException
{
public:
    UDPconnectConnectException(){}
};

#endif // UDPCONNECT_H

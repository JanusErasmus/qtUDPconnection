#include <QCoreApplication>
#include <QDebug>

#include "udpconnect.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "UDPconnection";

    QString server = "127.0.0.1";
    quint16 port = 5555;

    if(argc > 1)
    {
        server = QString(argv[1]);
    }
    if(argc > 2)
    {
        server = QString(argv[1]);
        port = atoi(argv[2]);
    }
    qDebug() << "Send to " << server << ":" << port;

    UDPconnect * c = 0;
    try
    {
        c = new UDPconnect(server, port);
        if(c->transmit("Hallo") > 0)
        {
            qDebug() << "Sent string";
        }
    }
    catch(UDPconnectConnectException &e)
    {
        qDebug() << "UDPconnectConnectException";
    }

//    if(c)
//        delete c;

    return a.exec();
}

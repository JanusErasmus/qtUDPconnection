#include <QCoreApplication>
#include <QDebug>

#include "interface_udp.h"
#include "sess_get_info.h"

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
    }
    catch(UDPconnectConnectException &e)
    {
        qDebug() << "UDPconnectConnectException";
    }

    cSessGetInfo * s = new cSessGetInfo(c);

    return a.exec();
}

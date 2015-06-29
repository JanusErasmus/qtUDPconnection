#ifndef CSESSGETINFO_H
#define CSESSGETINFO_H
#include <QObject>

#include "duplexinterface.h"
#include "glamdict.h"

class cSessGetInfo : public QObject
{
    Q_OBJECT

    duplexInterface * mIface;

    void handleReply(KMsg * m);

public:
    cSessGetInfo(duplexInterface * iface);

public slots:
    void execute();

signals:
    void finished();
};

#endif // CSESSGETINFO_H

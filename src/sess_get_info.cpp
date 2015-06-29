#include <QDebug>
#include <QByteArray>
#include <QThread>

#include "sess_get_info.h"

cSessGetInfo::cSessGetInfo(duplexInterface *iface) : mIface(iface)
{    
    QThread * t = new QThread();
    this->moveToThread(t);
    connect(t, SIGNAL(started()), SLOT(execute()));
    connect(this, SIGNAL(finished()), t, SLOT(quit()));
    connect(this, SIGNAL(finished()), SLOT(deleteLater()));
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    t->start();
}

 void cSessGetInfo::execute()
 {
     KMsg m(GLAM::MSG_REQ);
     m.addTag(KTagFactory::createKTag(GLAM::TAG_LOCK_OPEN, (uint8_t)0));

     uint8_t buff[1024];
     int len = m.getMsg(buff, 1024);
     if(len > 0)
     {
         mIface->transmit(buff, len);

         len = mIface->receive(buff, 1024);
         if(len > 0)
         {
             KMsg * reply = KMsg::parseMsg(buff, len);
             if(reply)
             {
                 handleReply(reply);
                 delete reply;
             }
         }
     }

     emit finished();
 }

  void cSessGetInfo::handleReply(KMsg * m)
  {
      if(!m || (m->getMsgID() != GLAM::MSG_SET))
          return;

      qDebug() << "handleReply";

      uint32_t serial = 0;
      QString box;
      QString version;
      QString server;
      int port = 0;

      char tempChar[128];

      m->gotoFirst();
      const KTag * t = m->getTag();
      while(t)
      {
          switch(t->getTagID())
          {
          case GLAM::TAG_KEY_SN:
              serial = ((KTagUInt32*)t)->getValue();
              break;
          case GLAM::TAG_KEY_BOX:
              ((KTagString*)t)->getValue(tempChar, 128);
              box = QString(tempChar);
              break;
          case GLAM::TAG_KEY_SW:
              ((KTagString*)t)->getValue(tempChar, 128);
              version = QString(tempChar);
              break;
          case GLAM::TAG_SRV_NAME:
              ((KTagString*)t)->getValue(tempChar, 128);
              server = QString(tempChar);
              break;
          case GLAM::TAG_SRV_PORT:
              ((KTagString*)t)->getValue(tempChar, 128);
              port = ((KTagUInt16*)t)->getValue();
              break;
          }
          t = m->getTag();
      }

      qDebug() << "Serial: " << serial;
      qDebug() << "Box: " << box;
      qDebug() << "Version: " << version;
      qDebug() << "Server: " << server;
      qDebug() << "Port: " << port;
  }


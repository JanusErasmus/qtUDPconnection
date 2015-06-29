#-------------------------------------------------
#
# Project created by QtCreator 2015-01-17T10:00:32
#
#-------------------------------------------------
QT       += core
QT       += network
QT       -= gui

TARGET = UDPconnection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += src/main.cpp \
    src/sess_get_info.cpp \
    src/interface_udp.cpp \
    src/glamdict.cpp

HEADERS += \
    src/sess_get_info.h \
    src/duplexinterface.h \
    src/interface_udp.h \
    src/glamdict.h

win32 {
INCLUDEPATH += $$PWD/../libKmsg/include
LIBS += -L$$PWD/../libKmsg/lib -lkmsg -lwsock32
}

unix {
INCLUDEPATH += $$PWD/../libKMsg/include
LIBS += -lkmsg
}

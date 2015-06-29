#ifndef DUPLEXINTERFACE_H
#define DUPLEXINTERFACE_H
#include <stdint.h>

class duplexInterface
{
public:
    duplexInterface(){}

    virtual int transmit(uint8_t * buff, int buff_len) = 0;
    virtual int receive(uint8_t * buff, int buff_len, int timeout = 5000) = 0;

    virtual ~duplexInterface(){}
};


#endif // DUPLEXINTERFACE_H


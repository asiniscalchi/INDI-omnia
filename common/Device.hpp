#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <QString>

#include "indibase/basedevice.h"

struct Device
{
    QString name;
    bool connected = false;
    QString deviceInterface;

    static Device fromBaseDevice(const INDI::BaseDevice &baseDevice);
};


#endif // DEVICE_HPP

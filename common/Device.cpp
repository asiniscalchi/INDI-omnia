#include "Device.hpp"

Device::Device(const QString &name)
    : mName(name)
{
}

QString Device::name() const
{
    return mName;
}

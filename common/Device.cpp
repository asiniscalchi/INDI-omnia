#include "Device.hpp"

Device Device::fromBaseDevice(INDI::BaseDevice &baseDevice)
{
    Device device;
    device.name = QString(baseDevice.getDeviceName());
    device.connected = baseDevice.isConnected();
    return device;
}

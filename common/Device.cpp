#include "Device.hpp"

Device Device::fromBaseDevice(const INDI::BaseDevice &baseDevice)
{
    Device device;
    device.name = QString(baseDevice.getDeviceName());
    device.connected = baseDevice.isConnected();
    device.deviceInterface = QString::number(baseDevice.getDriverInterface());
    return device;
}

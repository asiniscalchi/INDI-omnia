#ifndef DEVICEMODELFACADE_HPP
#define DEVICEMODELFACADE_HPP

#include <QObject>

#include "DeviceModel.hpp"

class DeviceModelFacade : public QObject
{
    Q_OBJECT
public:
    explicit DeviceModelFacade(DeviceModel& model, QObject *parent = nullptr);

    Q_INVOKABLE bool setDeviceConnected(int row, bool connected);

private:
    DeviceModel& mModel;
};

#endif // DEVICEMODELFACADE_HPP

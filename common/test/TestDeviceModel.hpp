#ifndef TESTDEVICEMODEL_HPP
#define TESTDEVICEMODEL_HPP

#include <QTest>

class TestDeviceModel : public QObject
{
    Q_OBJECT

private slots:
    void countDevicesOnEmplyModel();
    void countDevicesAfterAddDevice();
    void clearModel();
};

#endif // TESTDEVICEMODEL_HPP

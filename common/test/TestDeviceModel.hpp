#ifndef TESTDEVICEMODEL_HPP
#define TESTDEVICEMODEL_HPP

#include <QTest>

class TestDeviceModel : public QObject
{
    Q_OBJECT

private slots:
    void countDevicesOnEmplyModel();
};

#endif // TESTDEVICEMODEL_HPP

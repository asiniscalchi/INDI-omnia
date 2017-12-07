#include "TestDeviceModel.hpp"

#include "DeviceModel.hpp"

void TestDeviceModel::countDevicesOnEmplyModel()
{
    DeviceModel model;
    QVERIFY(model.rowCount() == 0);
}

void TestDeviceModel::countDevicesAfterAddDevice()
{
    DeviceModel model;
    model.addDevice(Device());
    QVERIFY(model.rowCount() == 1);
}

void TestDeviceModel::clearModel()
{
    DeviceModel model;
    model.clear();
    QVERIFY(model.rowCount() == 0);
    model.addDevice(Device());
    model.clear();
    QVERIFY(model.rowCount() == 0);
}

QTEST_MAIN(TestDeviceModel)

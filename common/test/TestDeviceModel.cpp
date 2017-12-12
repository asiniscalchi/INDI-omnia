#include "TestDeviceModel.hpp"

#include "DeviceModel.hpp"

void TestDeviceModel::countDevicesOnEmplyModel()
{
    DeviceModel model;
    QVERIFY(model.rowCount() == 0);
}


QTEST_MAIN(TestDeviceModel)

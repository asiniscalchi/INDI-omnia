#include "TestDeviceModel.hpp"

#include "DeviceModel.hpp"

void TestDeviceModel::countDevicesOnEmplyModel()
{
    IndiConnection client;
    DeviceModel model(client);
    QVERIFY(model.rowCount() == 0);
}

QTEST_MAIN(TestDeviceModel)

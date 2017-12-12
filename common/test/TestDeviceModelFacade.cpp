#include "TestDeviceModelFacade.hpp"

#include "DeviceModelFacade.hpp"

void TestDeviceModelFacade::connectDeviceOnNotConnectedModel()
{
    DeviceModel model;
    DeviceModelFacade facede(model);

    QVERIFY(facede.setDeviceConnected(0, true) == false);
}

QTEST_MAIN(TestDeviceModelFacade)

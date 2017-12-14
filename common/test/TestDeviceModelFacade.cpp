#include "TestDeviceModelFacade.hpp"

#include "DeviceModelFacade.hpp"

void TestDeviceModelFacade::connectDeviceOnNotConnectedModel()
{
    IndiClient client;
    DeviceModel model(client);
    DeviceModelFacade facede(model);

    QVERIFY(facede.setDeviceConnected(0, true) == false);
}

QTEST_MAIN(TestDeviceModelFacade)

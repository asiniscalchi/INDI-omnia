#include "TestDeviceModelFacade.hpp"

#include "DeviceModelFacade.hpp"

void TestDeviceModelFacade::connectDeviceOnNotConnectedModel()
{
    IndiConnection client;
    DeviceModel model(client);
    DeviceModelFacade facede(model);

    QVERIFY(facede.connectDevice(0) == false);
    QVERIFY(facede.disconnectDevice(0) == false);
}

QTEST_MAIN(TestDeviceModelFacade)

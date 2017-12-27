#include "TestIndiConnection.hpp"

#include <QSignalSpy>

#include "IndiConnection.hpp"

void TestIndiConnection::onServerDisconnected()
{
    IndiConnection connection;
    QSignalSpy spy(&connection, SIGNAL(serverConnectedChanged(bool)));

    connection.serverDisconnected(0);
    QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly one time
    QList<QVariant> arguments = spy.takeFirst(); // take the first signal

    QVERIFY(arguments.at(0).toBool() == false); // verify the first argument
}

QTEST_MAIN(TestIndiConnection)

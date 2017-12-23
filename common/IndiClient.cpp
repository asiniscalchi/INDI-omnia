#include "IndiClient.hpp"

#include "IndiConnection.hpp"

IndiClient::IndiClient(QObject *parent) : QObject(parent)
{
    moveToThread(&mThread);
    mThread.start();
    QMetaObject::invokeMethod(this, "init", Qt::BlockingQueuedConnection);
}

IndiClient::~IndiClient()
{
    QMetaObject::invokeMethod(this, "deinit", Qt::BlockingQueuedConnection);
    mThread.quit();
    mThread.wait();
}

void IndiClient::connect(const QString &host, int port)
{
    QMetaObject::invokeMethod(mConnection, "connect", Q_ARG(QString, host), Q_ARG(int, port));
}

bool IndiClient::isConnected() const
{
    return mConnection->isConnected();
}

void IndiClient::disconnect()
{
    mConnection->disconnect();
}

void IndiClient::connectDevice(QString name)
{

}

void IndiClient::disconnectDevice(QString name)
{

}

void IndiClient::init()
{
    mConnection = new IndiConnection;
    QObject::connect(mConnection, &IndiConnection::log, this, &IndiClient::log);
    QObject::connect(mConnection, &IndiConnection::serverConnectedChanged, this, &IndiClient::serverConnectedChanged);
    QObject::connect(mConnection, &IndiConnection::newDeviceReceived, this, &IndiClient::newDeviceReceived);
    QObject::connect(mConnection, &IndiConnection::deviceConnectedChanged, this, &IndiClient::deviceConnectedChanged);
}

void IndiClient::deinit()
{
    delete mConnection;
}


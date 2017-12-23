#include "IndiClient.hpp"

#include <QMetaObject>

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
    QMetaObject::invokeMethod(this, "selfConnect", Q_ARG(QString, host), Q_ARG(int, port));
}

bool IndiClient::isConnected()
{
    bool connected = false;
    QMetaObject::invokeMethod(this, "selfIsConnected", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, connected));
    return connected;
}

void IndiClient::disconnect()
{
    QMetaObject::invokeMethod(this, "selfDisconnect");
}

void IndiClient::connectDevice(QString name)
{
    QMetaObject::invokeMethod(this, "selfConnectDevice", Q_ARG(QString, name));
}

void IndiClient::disconnectDevice(QString name)
{
    QMetaObject::invokeMethod(this, "selfDisconnectDevice", Q_ARG(QString, name));
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

void IndiClient::selfConnectDevice(QString name)
{
    mConnection->connectDevice(name.toStdString().c_str());
}

void IndiClient::selfDisconnectDevice(QString name)
{
    mConnection->disconnectDevice(name.toStdString().c_str());
}

void IndiClient::selfConnect(QString host, int port)
{
    mConnection->connect(host, port);
}

void IndiClient::selfDisconnect()
{
    mConnection->disconnect();
}

bool IndiClient::selfIsConnected() const
{
    return mConnection->isServerConnected();
}



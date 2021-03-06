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

void IndiClient::connectServer(const QString &host, int port)
{
    QMetaObject::invokeMethod(this, "selfConnect", Q_ARG(QString, host), Q_ARG(int, port));
}

bool IndiClient::isServerConnected()
{
    bool connected = false;
    QMetaObject::invokeMethod(this, "selfIsConnected", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, connected));
    return connected;
}

void IndiClient::disconnectServer()
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
    QObject::connect(mConnection, &IndiConnection::log, this, &IndiClient::log, Qt::QueuedConnection);
    QObject::connect(mConnection, &IndiConnection::serverConnectedChanged, this, &IndiClient::serverConnectedChanged, Qt::QueuedConnection);
    QObject::connect(mConnection, &IndiConnection::newDeviceReceived, this, &IndiClient::newDeviceReceived, Qt::QueuedConnection);
    QObject::connect(mConnection, &IndiConnection::deviceConnectedChanged, this, &IndiClient::deviceConnectedChanged, Qt::QueuedConnection);
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
    emit log("Connecting to host " + host + " port " + QString::number(port) + "...");
    mConnection->setServer(host.toStdString().c_str(), port);
    if (mConnection->connectServer() == false)
        emit log("(EE) can't connect");
}

void IndiClient::selfDisconnect()
{
    mConnection->disconnectServer();
}

bool IndiClient::selfIsConnected() const
{
    return mConnection->isServerConnected();
}



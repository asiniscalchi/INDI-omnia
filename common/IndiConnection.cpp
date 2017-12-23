#include "IndiConnection.hpp"

#include "indibase/basedevice.h"
#include "indibase/indistandardproperty.h"

IndiConnection::IndiConnection(QObject *parent) : INDI::BaseClientQt(parent)
{
    qRegisterMetaType<Device>();
}

bool IndiConnection::connect(const QString &host, int port)
{
    emit log("Connecting to host " + host + " port " + QString::number(port) + "...");
    setServer(host.toStdString().c_str(), port);
    bool ans = connectServer();

    if (!ans)
        emit log("(EE) can't connect");

    return ans;
}

bool IndiConnection::isConnected() const
{
    return isServerConnected();
}

void IndiConnection::disconnect()
{
    disconnectServer();
}

void IndiConnection::newDevice(INDI::BaseDevice *dp)
{
    emit log("newDevice: " + QString(dp->getDeviceName()));
    emit newDeviceReceived(Device::fromBaseDevice(*dp));
}

void IndiConnection::removeDevice(INDI::BaseDevice *dp)
{
    emit log("removeDevice: " + QString(dp->getDeviceName()));
}

void IndiConnection::newProperty(INDI::Property *property)
{
    emit log("[" + QString(property->getDeviceName()) + "] newProperty : " + QString(property->getName()));

    QString deviceName(property->getDeviceName());
    QString propertyConnection(INDI::SP::CONNECTION);
    QString propertyName(property->getName());

    if (propertyName == propertyConnection)
        emit deviceConnectedChanged(deviceName, property->getBaseDevice()->isConnected());
}

void IndiConnection::removeProperty(INDI::Property *property)
{
    emit log("[" + QString(property->getDeviceName()) + "] removeProperty : " + QString(property->getName()));
}

void IndiConnection::newBLOB(IBLOB *bp)
{
    emit log("[" + QString(bp->name) + "] newBLOB");
}

void IndiConnection::newSwitch(ISwitchVectorProperty *svp)
{
    emit log("[" + QString(svp->device) + "] newSwitch : " + QString(svp->name));

    QString deviceName(svp->device);
    QString propertyConnection(INDI::SP::CONNECTION);
    QString propertyName(svp->name);

    if (propertyName == propertyConnection)
    {
        bool isConnected = (svp->sp->s == ISS_ON);
        emit deviceConnectedChanged(deviceName, isConnected);
    }
}

void IndiConnection::newNumber(INumberVectorProperty *nvp)
{
    emit log("[" + QString(nvp->device) + "] newNumber : " + QString(nvp->name));
}

void IndiConnection::newText(ITextVectorProperty *tvp)
{
    emit log("[" + QString(tvp->device) + "] newText : " + QString(tvp->name));
}

void IndiConnection::newLight(ILightVectorProperty *lvp)
{
    emit log("[" + QString(lvp->device) + "] newLight");
}

void IndiConnection::newMessage(INDI::BaseDevice *dp, int messageID)
{
    emit log("[" + QString(dp->getDeviceName()) + "] newMessage");
}

void IndiConnection::serverConnected()
{
    emit log("server connected");
    emit serverConnectedChanged(true);
}

void IndiConnection::serverDisconnected(int exit_code)
{
    emit log("server disconnected (code=" + QString::number(exit_code) + ")");
    emit serverConnectedChanged(false);
}

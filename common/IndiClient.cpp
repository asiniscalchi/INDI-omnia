#include "IndiClient.hpp"

#include "indibase/basedevice.h"
#include "indibase/indistandardproperty.h"

IndiClient::IndiClient(QObject *parent) : INDI::BaseClientQt(parent)
{

}

bool IndiClient::connect(const QString &host, int port)
{
    emit message("Connecting to host " + host + " port " + QString::number(port) + "...");
    setServer(host.toStdString().c_str(), port);
    bool ans = connectServer();

    if (!ans)
        emit message("(EE) can't connect");

    return ans;
}

bool IndiClient::isConnected() const
{
    return mConnected;
}

void IndiClient::disconnect()
{
    disconnectServer();
}

void IndiClient::newDevice(INDI::BaseDevice *dp)
{
    emit message("newDevice: " + QString(dp->getDeviceName()));
    emit newDeviceReceived(Device::fromBaseDevice(*dp));
}

void IndiClient::removeDevice(INDI::BaseDevice *dp)
{
    emit message("removeDevice: " + QString(dp->getDeviceName()));
}

void IndiClient::newProperty(INDI::Property *property)
{
    emit message("[" + QString(property->getDeviceName()) + "] newProperty : " + QString(property->getName()));

    QString deviceName(property->getDeviceName());
    QString propertyConnection(INDI::SP::CONNECTION);
    QString propertyName(property->getName());

    if (propertyName == propertyConnection)
        emit deviceConnectedChanged(deviceName, property->getBaseDevice()->isConnected());
}

void IndiClient::removeProperty(INDI::Property *property)
{
    emit message("[" + QString(property->getDeviceName()) + "] removeProperty : " + QString(property->getName()));
}

void IndiClient::newBLOB(IBLOB *bp)
{
    emit message("[" + QString(bp->name) + "] newBLOB");
}

void IndiClient::newSwitch(ISwitchVectorProperty *svp)
{
    emit message("[" + QString(svp->device) + "] newSwitch : " + QString(svp->name));

    QString deviceName(svp->device);
    QString propertyConnection(INDI::SP::CONNECTION);
    QString propertyName(svp->name);

    if (propertyName == propertyConnection)
    {
        bool isConnected = (svp->sp->s == ISS_ON);
        emit deviceConnectedChanged(deviceName, isConnected);
    }
}

void IndiClient::newNumber(INumberVectorProperty *nvp)
{
    emit message("[" + QString(nvp->device) + "] newNumber : " + QString(nvp->name));
}

void IndiClient::newText(ITextVectorProperty *tvp)
{
    emit message("[" + QString(tvp->device) + "] newText : " + QString(tvp->name));
}

void IndiClient::newLight(ILightVectorProperty *lvp)
{
    emit message("[" + QString(lvp->device) + "] newLight");
}

void IndiClient::newMessage(INDI::BaseDevice *dp, int messageID)
{
    emit message("[" + QString(dp->getDeviceName()) + "[ newMessage");
}

void IndiClient::serverConnected()
{
    emit message("server connected");
    mConnected = true;
    emit connectedChanged(mConnected);
}

void IndiClient::serverDisconnected(int exit_code)
{
    emit message("server disconnected (code=" + QString::number(exit_code) + ")");
    mConnected = false;
    emit connectedChanged(mConnected);
    emit serverDisconnectedReceived(exit_code);
}

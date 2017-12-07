#include "IndiClient.hpp"

#include "indibase/basedevice.h"

IndiClient::IndiClient(QObject *parent) : INDI::BaseClientQt(parent)
{

}

bool IndiClient::connect(const QString &host, int port)
{
    emit message("connecting to host " + host + " port " + QString::number(port));
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
    emit message("disconnecting from host");
    disconnectServer();
}

void IndiClient::newDevice(INDI::BaseDevice *dp)
{
    emit message("(INDI) newDevice: " + QString(dp->getDeviceName()));
    emit newDeviceReceived(Device::fromBaseDevice(*dp));
}

void IndiClient::removeDevice(INDI::BaseDevice *dp)
{
    emit message("(INDI) removeDevice: " + QString(dp->getDeviceName()));
}

void IndiClient::newProperty(INDI::Property *property)
{
    emit message("(INDI) newProperty (" + QString(property->getDeviceName()) + "): " + QString(property->getName()));
}

void IndiClient::removeProperty(INDI::Property *property)
{
    emit message("(INDI) removeProperty");
}

void IndiClient::newBLOB(IBLOB *bp)
{
    emit message("(INDI) newBLOB");
}

void IndiClient::newSwitch(ISwitchVectorProperty *svp)
{
    emit message("(INDI) newSwitch (" + QString(svp->device) + "): " + QString(svp->name));
}

void IndiClient::newNumber(INumberVectorProperty *nvp)
{
    emit message("(INDI) newNumber (" + QString(nvp->device) + "): " + QString(nvp->name));
}

void IndiClient::newText(ITextVectorProperty *tvp)
{
    emit message("(INDI) newText (" + QString(tvp->device) + "): " + QString(tvp->name));
}

void IndiClient::newLight(ILightVectorProperty *lvp)
{
    emit message("(INDI) newLight");
}

void IndiClient::newMessage(INDI::BaseDevice *dp, int messageID)
{
    emit message("(INDI) newMessage: " + QString(dp->getDeviceName()));
}

void IndiClient::serverConnected()
{
    emit message("(INDI) server connected");
    mConnected = true;
    emit connectedChanged(mConnected);
}

void IndiClient::serverDisconnected(int exit_code)
{
    emit message("(INDI) server disconnected (code=" + QString::number(exit_code) + ")");
    mConnected = false;
    emit connectedChanged(mConnected);
}

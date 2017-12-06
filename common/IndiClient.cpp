#include "IndiClient.hpp"

IndiClient::IndiClient(QObject *parent) : INDI::BaseClientQt(parent)
{

}

bool IndiClient::connect(const QString &host, int port)
{
    setServer(host.toStdString().c_str(), port);
    return connectServer();
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
}

void IndiClient::removeDevice(INDI::BaseDevice *dp)
{
}

void IndiClient::newProperty(INDI::Property *property)
{
}

void IndiClient::removeProperty(INDI::Property *property)
{
}

void IndiClient::newBLOB(IBLOB *bp)
{
}

void IndiClient::newSwitch(ISwitchVectorProperty *svp)
{
}

void IndiClient::newNumber(INumberVectorProperty *nvp)
{
}

void IndiClient::newText(ITextVectorProperty *tvp)
{
}

void IndiClient::newLight(ILightVectorProperty *lvp)
{
}

void IndiClient::newMessage(INDI::BaseDevice *dp, int messageID)
{
}

void IndiClient::serverConnected()
{
    mConnected = true;
    emit connectedChanged(mConnected);
}

void IndiClient::serverDisconnected(int exit_code)
{
    mConnected = false;
    emit connectedChanged(mConnected);
}

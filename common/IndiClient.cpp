#include "IndiClient.hpp"

IndiClient::IndiClient(QObject *parent) : INDI::BaseClientQt(parent)
{

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
}

void IndiClient::serverDisconnected(int exit_code)
{
}

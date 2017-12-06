#include "IndiClient.hpp"

IndiClient::IndiClient(QObject *parent) : INDI::BaseClientQt(parent)
{

}

bool IndiClient::connect(const QString &host, int port)
{
    emit message("(II) connecting to host " + host + " port " + QString::number(port));
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
    emit message("(II) disconnecting from host");
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

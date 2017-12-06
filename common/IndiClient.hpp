#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include <QString>

#include "indibase/baseclientqt.h"

class IndiClient : public INDI::BaseClientQt
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectedChanged)

public:
    explicit IndiClient(QObject *parent = nullptr);

    Q_INVOKABLE bool connect(const QString& host, int port);
    bool isConnected() const;
    Q_INVOKABLE void disconnect();

    void newDevice(INDI::BaseDevice *dp) final;
    void removeDevice(INDI::BaseDevice *dp) final;
    void newProperty(INDI::Property *property) final;
    void removeProperty(INDI::Property *property) final;
    void newBLOB(IBLOB *bp) final;
    void newSwitch(ISwitchVectorProperty *svp) final;
    void newNumber(INumberVectorProperty *nvp) final;
    void newText(ITextVectorProperty *tvp) final;
    void newLight(ILightVectorProperty *lvp) final;
    void newMessage(INDI::BaseDevice *dp, int messageID) final;
    void serverConnected() final;
    void serverDisconnected(int exit_code) final;

signals:
    void message(const QString& msg);
    void connectedChanged(bool connected);

private:
    bool mConnected = false;
};

#endif // INDICLIENT_HPP

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

    void newDevice(INDI::BaseDevice *dp) override;
    void removeDevice(INDI::BaseDevice *dp) override;
    void newProperty(INDI::Property *property) override;
    void removeProperty(INDI::Property *property) override;
    void newBLOB(IBLOB *bp) override;
    void newSwitch(ISwitchVectorProperty *svp) override;
    void newNumber(INumberVectorProperty *nvp) override;
    void newText(ITextVectorProperty *tvp) override;
    void newLight(ILightVectorProperty *lvp) override;
    void newMessage(INDI::BaseDevice *dp, int messageID) override;
    void serverConnected() override;
    void serverDisconnected(int exit_code) override;

signals:
    void connectedChanged(bool connected);

private:
    bool mConnected = false;
};

#endif // INDICLIENT_HPP

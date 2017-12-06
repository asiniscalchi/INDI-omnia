#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include "indibase/baseclientqt.h"

class IndiClient : public INDI::BaseClientQt
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);

signals:

public slots:

    // INDI::BaseMediator interface
public:
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
};

#endif // INDICLIENT_HPP

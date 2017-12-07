#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

/*
* Copyright (C) 2017 Alessandro Siniscalchi <asiniscalchi@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "indibase/baseclientqt.h"

#include <QString>

#include "Device.hpp"

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
    void newDeviceReceived(Device device);
    void serverDisconnectedReceived(int exit_code);

private:
    bool mConnected = false;
};

#endif // INDICLIENT_HPP

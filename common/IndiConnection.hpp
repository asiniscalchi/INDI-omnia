#ifndef INDICONNECTION_HPP
#define INDICONNECTION_HPP

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

class IndiConnection : public INDI::BaseClientQt
{
    Q_OBJECT

public:
    explicit IndiConnection(QObject *parent = nullptr);

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
    void log(const QString& msg);
    void serverConnectedChanged(bool connected);
    void newDeviceReceived(Device device);
    void deviceConnectedChanged(QString name, bool connected);

private:
    bool mConnected = false;
};

#endif // INDICONNECTION_HPP

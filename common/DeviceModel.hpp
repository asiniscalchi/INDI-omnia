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

#ifndef DEVICEMODEL_HPP
#define DEVICEMODEL_HPP

#include <QAbstractListModel>

#include <QStringList>

#include "Device.hpp"
#include "IndiClient.hpp"

class DeviceModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectedChanged)

public:
    enum DeviceRoles {
        TypeRole = Qt::UserRole + 1,
        ConnectedRole,
        DeviceInterfaceRole
    };

    DeviceModel(QObject *parent = 0);

    Q_INVOKABLE bool connect(const QString& host, int port);
    Q_INVOKABLE void disconnect();
    bool isConnected() const;

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

signals:
    void log(QString msg);
    void connectedChanged(bool connected);

protected:
    QHash<int, QByteArray> roleNames() const;

private slots:
    void addDevice(const Device &device);
    void clear();

private:
    QList<Device> mDevices;
    IndiClient mConnection;
};

#endif // DEVICEMODEL_HPP

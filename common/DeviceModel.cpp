#include "DeviceModel.hpp"

#include <QDebug>

#include "modeltest.h"

DeviceModel::DeviceModel(QObject *parent)
    : QAbstractListModel(parent)
{
    new ModelTest(this, this);

    QObject::connect(&mConnection, &IndiClient::message, this, &DeviceModel::log);
    QObject::connect(&mConnection, &IndiClient::connectedChanged, this, &DeviceModel::connectedChanged);
    QObject::connect(&mConnection, &IndiClient::newDeviceReceived, this, &DeviceModel::addDevice);
    QObject::connect(&mConnection, &IndiClient::serverDisconnectedReceived, this, &DeviceModel::clear);
}

bool DeviceModel::connect(const QString &host, int port)
{
    return mConnection.connect(host, port);
}
void DeviceModel::disconnect()
{
    mConnection.disconnectServer();
}

bool DeviceModel::isConnected() const
{
    return mConnection.isConnected();
}

void DeviceModel::addDevice(const Device &device)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mDevices << device;
    endInsertRows();
}

void DeviceModel::clear()
{
    beginResetModel();
    mDevices.clear();
    endResetModel();
}

int DeviceModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return mDevices.count();
}

QVariant DeviceModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= mDevices.count())
        return QVariant();

    const Device &device = mDevices[index.row()];

    switch (role) {
    case TypeRole:
        return device.name;
    case ConnectedRole:
        return device.connected;
    case DeviceInterfaceRole:
        return device.deviceInterface;
    default:
        break;
    }
    return QVariant();
}

QHash<int, QByteArray> DeviceModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "name";
    roles[ConnectedRole] = "connected";
    roles[DeviceInterfaceRole] = "deviceInterface";
    return roles;
}


bool DeviceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "DeviceModel::setData role = " << roleNames()[role];
    return false;
}

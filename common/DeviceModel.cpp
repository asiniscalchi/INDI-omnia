#include "DeviceModel.hpp"

DeviceModel::DeviceModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void DeviceModel::addDevice(const Device &device)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mDevices << device;
    endInsertRows();
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

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

    const Device &Device = mDevices[index.row()];
    if (role == TypeRole)
        return Device.name();
    return QVariant();
}

QHash<int, QByteArray> DeviceModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "name";
    return roles;
}

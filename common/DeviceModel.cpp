#include "DeviceModel.hpp"

#include <QDebug>
#include <QQmlEngine>

DeviceModel::DeviceModel(QObject *parent)
    : QAbstractListModel(parent)
{
    qmlRegisterType<DeviceModel>("DeviceRoles", 1, 0, "DeviceRoles");

    QObject::connect(&mConnection, &IndiClient::message, this, &DeviceModel::log);
    QObject::connect(&mConnection, &IndiClient::connectedChanged, this, &DeviceModel::connectedChanged);
    QObject::connect(&mConnection, &IndiClient::newDeviceReceived, this, &DeviceModel::addDevice);
    QObject::connect(&mConnection, &IndiClient::serverDisconnectedReceived, this, &DeviceModel::clear);
    QObject::connect(&mConnection, &IndiClient::deviceConnectedChanged, this, &DeviceModel::onDeviceConnectedChanged);
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

bool DeviceModel::setDeviceConnected(int row, bool connected)
{
    QModelIndex modelIndex = index(row, 0);
    return setData(modelIndex, connected, ConnectedRole);
}



void DeviceModel::addDevice(const Device &device)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mDevices << device;
    endInsertRows();
}

void DeviceModel::onDeviceConnectedChanged(QString name, bool connected)
{
    qDebug() << name << " is connected " << connected;

    for (int i=0 ; i < mDevices.size() ; ++i)
    {
        Device& device = mDevices[i];
        if (device.name == name)
        {
            device.connected = connected;
            QModelIndex idx = index(i, 0);
            emit dataChanged(idx, idx);
        }
    }
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
    qDebug() << "DeviceModel::setData value = " << value << ", role = " << role;

    if (!index.isValid())
        return false;

    int row = index.row();

    QString name = mDevices.at(row).name;

    if (role == ConnectedRole)
    {
        if (value.toBool())
            mConnection.connectDevice(name.toStdString().c_str());
        else
            mConnection.disconnectDevice(name.toStdString().c_str());
    }

    return true;
}


Qt::ItemFlags DeviceModel::flags(const QModelIndex &index) const
{
    auto flags = QAbstractListModel::flags(index);

    if (index.isValid())
        flags |= Qt::ItemIsEditable;

    return flags;
}

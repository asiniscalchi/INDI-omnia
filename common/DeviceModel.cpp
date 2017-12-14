#include "DeviceModel.hpp"

#include <QDebug>
#include <QQmlEngine>

DeviceModel::DeviceModel(IndiClient &client, QObject *parent) : QAbstractListModel(parent)
  , mClient(client)
{
    qRegisterMetaType<Device>();

    QObject::connect(&mClient, &IndiClient::message, this, &DeviceModel::log, Qt::QueuedConnection);
    QObject::connect(&mClient, &IndiClient::serverConnectedChanged, this, &DeviceModel::onServerConnectedChanged, Qt::QueuedConnection);
    QObject::connect(&mClient, &IndiClient::newDeviceReceived, this, &DeviceModel::onAddDeviceReceived, Qt::QueuedConnection);
    QObject::connect(&mClient, &IndiClient::deviceConnectedChanged, this, &DeviceModel::onDeviceConnectedChanged, Qt::QueuedConnection);
}

bool DeviceModel::connect(const QString &host, int port)
{
    return mClient.connect(host, port);
}
void DeviceModel::disconnect()
{
    mClient.disconnectServer();
}

bool DeviceModel::isConnected() const
{
    return mClient.isConnected();
}

void DeviceModel::onAddDeviceReceived(const Device &device)
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

void DeviceModel::onServerConnectedChanged(bool connected)
{
    if (connected == false)
    {
        beginResetModel();
        mDevices.clear();
        endResetModel();
    }

    emit connectedChanged(connected);
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
            mClient.connectDevice(name.toStdString().c_str());
        else
            mClient.disconnectDevice(name.toStdString().c_str());
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

#ifndef DEVICEMODEL_HPP
#define DEVICEMODEL_HPP

#include <QAbstractListModel>

#include <QStringList>

#include "Device.hpp"

class DeviceModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DeviceRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    DeviceModel(QObject *parent = 0);

    void addDevice(const Device &device);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Device> mDevices;
};

#endif // DEVICEMODEL_HPP

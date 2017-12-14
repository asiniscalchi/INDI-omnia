#include "DeviceModelFacade.hpp"

DeviceModelFacade::DeviceModelFacade(DeviceModel &model, QObject *parent) : QObject(parent)
  , mModel(model)
{

}

bool DeviceModelFacade::connectDevice(int row)
{
    QModelIndex modelIndex = mModel.index(row, 0);
    return mModel.setData(modelIndex, true, DeviceModel::ConnectedRole);
}

bool DeviceModelFacade::disconnectDevice(int row)
{
    QModelIndex modelIndex = mModel.index(row, 0);
    return mModel.setData(modelIndex, false, DeviceModel::ConnectedRole);
}


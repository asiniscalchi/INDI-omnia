#include "DeviceModelFacade.hpp"

DeviceModelFacade::DeviceModelFacade(DeviceModel &model, QObject *parent) : QObject(parent)
  , mModel(model)
{

}

bool DeviceModelFacade::setDeviceConnected(int row, bool connected)
{
    QModelIndex modelIndex = mModel.index(row, 0);
    return mModel.setData(modelIndex, connected, DeviceModel::ConnectedRole);
}


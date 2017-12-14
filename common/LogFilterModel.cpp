#include "LogFilterModel.hpp"

#include <QDebug>

LogFilterModel::LogFilterModel(QObject *parent) : QSortFilterProxyModel(parent)
{

}

void LogFilterModel::addFilter(QString filter)
{
    mDevices.push_back(filter);
    applyFilter();
}

void LogFilterModel::removeFilter(QString filter)
{
    auto iter = std::find(mDevices.begin(), mDevices.end(), filter);
    mDevices.erase(iter, iter+1);
    applyFilter();
}

void LogFilterModel::applyFilter()
{
    QString filter;
    if (!mDevices.empty())
    {
        filter.append("^(");
        for (auto device : mDevices)
            filter += "(?!\\[" + device + "\\])";
        filter.append(".)*$");
    }
    qDebug() << "LogFilterModel::applyFilter " + filter;
    setFilterRegExp(filter);
}

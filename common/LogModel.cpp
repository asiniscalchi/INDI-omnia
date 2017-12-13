#include "LogModel.hpp"

#include <QDebug>

LogModel::LogModel(QObject *parent) : QStringListModel(parent)
{

}

void LogModel::onLogReceived(QString log)
{
    if (insertRow(rowCount()) == false)
    {
        qWarning() << "LogModel::onLogReceived| can't add rows";
        return;
    }

    QModelIndex lastIndex = index(rowCount());
    if (setData(lastIndex, log) == false)
        qWarning() << "LogModel::onLogReceived| can't populate the new row with the log";
}

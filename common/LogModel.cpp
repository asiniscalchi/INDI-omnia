#include "LogModel.hpp"

#include <QDebug>

LogModel::LogModel(IndiConnection &client, QObject *parent) : QStringListModel(parent)
{
    QObject::connect(&client, &IndiConnection::log, this, &LogModel::onLogReceived);
}

void LogModel::onLogReceived(QString log)
{
    if (insertRow(rowCount()) == false)
    {
        qWarning() << "LogModel::onLogReceived| can't add rows";
        return;
    }

    QModelIndex lastIndex = index(rowCount()-1);
    if (setData(lastIndex, log) == false)
        qWarning() << "LogModel::onLogReceived| can't populate the new row with the log";
}

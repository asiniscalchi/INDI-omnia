#ifndef LOGMODEL_HPP
#define LOGMODEL_HPP

#include <QStringListModel>

#include <IndiConnection.hpp>

class LogModel : public QStringListModel
{
    Q_OBJECT

public:
    explicit LogModel(IndiConnection& client, QObject* parent = nullptr);

private slots:
    void onLogReceived(QString log);
};

#endif // LOGMODEL_HPP

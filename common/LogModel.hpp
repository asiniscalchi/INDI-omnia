#ifndef LOGMODEL_HPP
#define LOGMODEL_HPP

#include <QStringListModel>

#include <IndiClient.hpp>

class LogModel : public QStringListModel
{
    Q_OBJECT

public:
    explicit LogModel(IndiClient& client, QObject* parent = nullptr);

private slots:
    void onLogReceived(QString log);
};

#endif // LOGMODEL_HPP

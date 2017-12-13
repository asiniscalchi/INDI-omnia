#ifndef LOGMODEL_HPP
#define LOGMODEL_HPP

#include <QStringListModel>

class LogModel : public QStringListModel
{
    Q_OBJECT

public:
    explicit LogModel(QObject* parent = nullptr);

public slots:
    void onLogReceived(QString log);
};

#endif // LOGMODEL_HPP

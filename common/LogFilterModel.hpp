#ifndef LOGFILTERMODEL_HPP
#define LOGFILTERMODEL_HPP

#include <QSortFilterProxyModel>

class LogFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit LogFilterModel(QObject *parent = nullptr);

    Q_INVOKABLE void addFilter(QString filter);
    Q_INVOKABLE void removeFilter(QString filter);

private:
    void applyFilter();

    std::vector<QString> mDevices;
};

#endif // LOGFILTERMODEL_HPP

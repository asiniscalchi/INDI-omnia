#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

class IndiClient : public QObject
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);

signals:

public slots:
};

#endif // INDICLIENT_HPP
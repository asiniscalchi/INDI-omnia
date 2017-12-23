#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include <QThread>

class IndiClient final: public QObject
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);
    ~IndiClient();

private:
    QThread mThread;
};

#endif // INDICLIENT_HPP

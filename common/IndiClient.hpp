#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include <QThread>

class IndiConnection;

class IndiClient final: public QObject
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);
    ~IndiClient();

private slots:
    void init();

private:
    QThread mThread;
    IndiConnection* mConnection = nullptr;
};

#endif // INDICLIENT_HPP

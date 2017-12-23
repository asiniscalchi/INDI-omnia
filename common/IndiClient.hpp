#ifndef INDICLIENT_HPP
#define INDICLIENT_HPP

#include <QObject>

#include <QThread>

#include "Device.hpp"

class IndiConnection;

class IndiClient final: public QObject
{
    Q_OBJECT
public:
    explicit IndiClient(QObject *parent = nullptr);
    ~IndiClient();

    void connect(const QString& host, int port);
    bool isConnected();
    void disconnect();
    void connectDevice(QString name);
    void disconnectDevice(QString name);

signals:
    void log(const QString& msg);
    void serverConnectedChanged(bool connected);
    void newDeviceReceived(Device device);
    void deviceConnectedChanged(QString name, bool connected);

private slots:
    void init();
    void deinit();
    void selfConnectDevice(QString name);
    void selfDisconnectDevice(QString name);
    void selfConnect(QString host, int port);
    void selfDisconnect();
    bool selfIsConnected() const;

private:
    QThread mThread;
    IndiConnection* mConnection = nullptr;
};

#endif // INDICLIENT_HPP

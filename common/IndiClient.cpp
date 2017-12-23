#include "IndiClient.hpp"

#include "IndiConnection.hpp"

IndiClient::IndiClient(QObject *parent) : QObject(parent)
{
    moveToThread(&mThread);
    mThread.start();

    QMetaObject::invokeMethod(this, "init", Qt::BlockingQueuedConnection);
}

IndiClient::~IndiClient()
{
    mThread.quit();
    mThread.wait();
}

void IndiClient::init()
{
    mConnection = new IndiConnection(&mThread);
}


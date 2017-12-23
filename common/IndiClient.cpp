#include "IndiClient.hpp"

IndiClient::IndiClient(QObject *parent) : QObject(parent)
{
    moveToThread(&mThread);
    mThread.start();
}

IndiClient::~IndiClient()
{
    mThread.quit();
    mThread.wait();
}

#ifndef TESTINDICONNECTION_HPP
#define TESTINDICONNECTION_HPP

#include <QTest>

class TestIndiConnection : public QObject
{
    Q_OBJECT

private slots:
    void onServerDisconnected();
};

#endif // TESTINDICONNECTION_HPP

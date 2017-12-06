#ifndef TESTINDICLIENT_HPP
#define TESTINDICLIENT_HPP

#include <QTest>

class TestIndiClient : public QObject
{
    Q_OBJECT

private slots:
    void instantiate();
};

#endif // TESTINDICLIENT_HPP

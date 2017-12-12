#ifndef TESTDEVICEMODELFACADE_HPP
#define TESTDEVICEMODELFACADE_HPP

#include <QTest>

class TestDeviceModelFacade : public QObject
{
    Q_OBJECT

private slots:
    void connectDeviceOnNotConnectedModel();
};


#endif // TESTDEVICEMODELFACADE_HPP

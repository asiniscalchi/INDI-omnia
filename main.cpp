#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "common/IndiClient.hpp"
#include "common/DeviceModel.hpp"

int main(int argc, char *argv[])
{
    IndiClient indiClient;
    DeviceModel deviceModel;

    QObject::connect(&indiClient, &IndiClient::newDeviceReceived, &deviceModel, &DeviceModel::addDevice);

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("indiClient", &indiClient);
    engine.rootContext()->setContextProperty("deviceModel", &deviceModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

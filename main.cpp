#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Version.h"
#include "common/IndiClient.hpp"
#include "common/DeviceModel.hpp"

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Indi-Omnia");
    QGuiApplication::setApplicationVersion(QString(VERSION_MAJOR) + "." + QString(VERSION_MINOR) + "." + QString(VERSION_RELEASE));
    QGuiApplication::setApplicationDisplayName(QGuiApplication::applicationName() + " " + QGuiApplication::applicationVersion());

    IndiClient indiClient;
    DeviceModel deviceModel;
    QObject::connect(&indiClient, &IndiClient::newDeviceReceived, &deviceModel, &DeviceModel::addDevice);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("indiClient", &indiClient);
    engine.rootContext()->setContextProperty("deviceModel", &deviceModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

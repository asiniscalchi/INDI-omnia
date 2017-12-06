#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "common/IndiClient.hpp"

int main(int argc, char *argv[])
{
    IndiClient indiClient;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("indiClient", &indiClient);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

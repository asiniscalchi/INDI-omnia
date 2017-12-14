/*
* Copyright (C) 2017 Alessandro Siniscalchi <asiniscalchi@gmail.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>

#include "Version.h"
#include "common/IndiClient.hpp"
#include "common/DeviceModel.hpp"
#include "common/DeviceModelFacade.hpp"
#include "common/LogModel.hpp"
#include "common/LogFilterModel.hpp"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qml);
    Q_INIT_RESOURCE(resources);

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("Lysergic");
    QGuiApplication::setApplicationName("Indi-Omnia");
    QGuiApplication::setApplicationVersion(QString(VERSION_MAJOR) + "." + QString(VERSION_MINOR) + "." + QString(VERSION_RELEASE));
    QGuiApplication::setApplicationDisplayName(QGuiApplication::applicationName() + " " + QGuiApplication::applicationVersion());
    QGuiApplication::setWindowIcon(QIcon(":/magic_hat.svg"));

    IndiClient client;
    LogModel logModel(client);
    LogFilterModel logFilterModel;
    logFilterModel.setSourceModel(&logModel);
    DeviceModel deviceModel(client);
    DeviceModelFacade deviceModelFacade(deviceModel);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("deviceModel", &deviceModel);
    engine.rootContext()->setContextProperty("deviceModelFacade", &deviceModelFacade);
    engine.rootContext()->setContextProperty("logFilterModel", &logFilterModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

QT += qml quick svg xml core
QTPLUGIN += qsvg
CONFIG += c++11
QMAKE_CFLAGS += -std=c99

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
$$PWD/external \
$$PWD/external/zlib \
$$PWD/external/libindi \
$$PWD/external/libindi/libs \
$$PWD/external/libindi/libs/indibase \
$$PWD/common \
$$PWD/android

HEADERS += \
    common/IndiClient.hpp \
    common/DeviceModel.hpp \
    common/DeviceModelFacade.hpp \
    common/LogModel.hpp \
    common/Device.hpp \
    common/LogFilterModel.hpp \
    external/libindi/libs/indibase/baseclientqt.h \

SOURCES += external/zlib/adler32.c \
    external/zlib/compress.c \
    external/zlib/crc32.c \
    external/zlib/crc32.h \
    external/zlib/deflate.c \
    external/zlib/deflate.h \
    external/zlib/gzclose.c \
    external/zlib/gzguts.h \
    external/zlib/gzlib.c \
    external/zlib/gzread.c \
    external/zlib/gzwrite.c \
    external/zlib/infback.c \
    external/zlib/inffast.c \
    external/zlib/inffast.h \
    external/zlib/inffixed.h \
    external/zlib/inflate.c \
    external/zlib/inflate.h \
    external/zlib/inftrees.c \
    external/zlib/inftrees.h \
    external/zlib/trees.c \
    external/zlib/trees.h \
    external/zlib/uncompr.c \
    external/zlib/zconf.h \
    external/zlib/zlib.h \
    external/zlib/zutil.c \
    external/zlib/zutil.h \
    common/IndiClient.cpp \
    common/DeviceModel.cpp \
    common/Device.cpp \
    common/DeviceModelFacade.cpp \
    common/LogModel.cpp \
    common/LogFilterModel.cpp \
    external/libindi/libs/lilxml.h \
    external/libindi/libs/lilxml.c \
    external/libindi/libs/indicom.h \
    external/libindi/libs/indicom.c \
    external/libindi/base64.h \
    external/libindi/base64.c \
    external/libindi/libs/indibase/basedevice.h \
    external/libindi/libs/indibase/basedevice.cpp \
    external/libindi/libs/indibase/baseclientqt.cpp \
    external/libindi/libs/indibase/indiproperty.h \
    external/libindi/libs/indibase/indiproperty.cpp \
    external/libindi/libs/indibase/indistandardproperty.h \
    external/libindi/libs/indibase/indistandardproperty.cpp \
    main.cpp

RESOURCES += resources/resources.qrc qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

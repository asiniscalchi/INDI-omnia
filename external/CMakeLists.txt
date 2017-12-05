set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Network)

set(INDI_SOVERSION "1")
set(CMAKE_INDI_VERSION_MAJOR 1)
set(CMAKE_INDI_VERSION_MINOR 6)
set(CMAKE_INDI_VERSION_RELEASE 0)
set(CMAKE_INDI_VERSION_STRING "${CMAKE_INDI_VERSION_MAJOR}.${CMAKE_INDI_VERSION_MINOR}.${CMAKE_INDI_VERSION_RELEASE}")
set(INDI_VERSION ${CMAKE_INDI_VERSION_MAJOR}.${CMAKE_INDI_VERSION_MINOR}.${CMAKE_INDI_VERSION_RELEASE})
set(DATA_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/share/indi/")
configure_file(indi/libindi/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h )
configure_file(indi/libindi/indiversion.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/indiversion.h )
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(indi/libindi)
include_directories(indi/libindi/libs)
include_directories(indi/libindi/libs/indibase)
add_library(indiclient
    indi/libindi/libs/lilxml.c
    indi/libindi/base64.c
    indi/libindi/libs/indibase/basedevice.h
    indi/libindi/libs/indibase/basedevice.cpp
    indi/libindi/libs/indibase/baseclient.h
    indi/libindi/libs/indibase/baseclient.cpp
    indi/libindi/libs/indibase/baseclientqt.h
    indi/libindi/libs/indibase/baseclientqt.cpp
    indi/libindi/libs/indibase/indiproperty.cpp
    indi/libindi/libs/indibase/indistandardproperty.cpp
    indi/libindi/libs/indicom.c
    )

target_link_libraries(indiclient Qt5::Network)

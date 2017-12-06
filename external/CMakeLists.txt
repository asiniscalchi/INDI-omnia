set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(ZLIB REQUIRED)
find_package (Threads REQUIRED)
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
    indi/libindi/libs/lilxml.h
    indi/libindi/libs/lilxml.c
    indi/libindi/libs/indicom.h
    indi/libindi/libs/indicom.c
    indi/libindi/base64.h
    indi/libindi/base64.c
    indi/libindi/libs/indibase/basedevice.h
    indi/libindi/libs/indibase/basedevice.cpp
    indi/libindi/libs/indibase/baseclientqt.h
    indi/libindi/libs/indibase/baseclientqt.cpp
    indi/libindi/libs/indibase/indiproperty.h
    indi/libindi/libs/indibase/indiproperty.cpp
    indi/libindi/libs/indibase/indistandardproperty.h
    indi/libindi/libs/indibase/indistandardproperty.cpp
    )

target_link_libraries(indiclient Qt5::Network ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES})
target_include_directories(indiclient INTERFACE indi/libindi)
target_include_directories(indiclient INTERFACE indi/libindi/libs)

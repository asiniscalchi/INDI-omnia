set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Threads REQUIRED)
find_package(Qt5Network)

add_library(zlib
    zlib/adler32.c
    zlib/compress.c
    zlib/crc32.c
    zlib/crc32.h
    zlib/deflate.c
    zlib/deflate.h
    zlib/gzclose.c
    zlib/gzguts.h
    zlib/gzlib.c
    zlib/gzread.c
    zlib/gzwrite.c
    zlib/infback.c
    zlib/inffast.c
    zlib/inffast.h
    zlib/inffixed.h
    zlib/inflate.c
    zlib/inflate.h
    zlib/inftrees.c
    zlib/inftrees.h
    zlib/trees.c
    zlib/trees.h
    zlib/uncompr.c
    zlib/zconf.h
    zlib/zlib.h
    zlib/zutil.c
    zlib/zutil.h)
target_include_directories(zlib INTERFACE zlib)

set(INDI_SOVERSION "1")
set(CMAKE_INDI_VERSION_MAJOR 1)
set(CMAKE_INDI_VERSION_MINOR 6)
set(CMAKE_INDI_VERSION_RELEASE 0)
set(CMAKE_INDI_VERSION_STRING "${CMAKE_INDI_VERSION_MAJOR}.${CMAKE_INDI_VERSION_MINOR}.${CMAKE_INDI_VERSION_RELEASE}")
set(INDI_VERSION ${CMAKE_INDI_VERSION_MAJOR}.${CMAKE_INDI_VERSION_MINOR}.${CMAKE_INDI_VERSION_RELEASE})
set(DATA_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/share/indi/")
configure_file(libindi/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h )
configure_file(libindi/indiversion.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/indiversion.h )
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(libindi)
include_directories(libindi/libs)
include_directories(libindi/libs/indibase)
add_library(indiclient
    libindi/libs/lilxml.h
    libindi/libs/lilxml.c
    libindi/libs/indicom.h
    libindi/libs/indicom.c
    libindi/base64.h
    libindi/base64.c
    libindi/libs/indibase/basedevice.h
    libindi/libs/indibase/basedevice.cpp
    libindi/libs/indibase/baseclientqt.h
    libindi/libs/indibase/baseclientqt.cpp
    libindi/libs/indibase/indiproperty.h
    libindi/libs/indibase/indiproperty.cpp
    libindi/libs/indibase/indistandardproperty.h
    libindi/libs/indibase/indistandardproperty.cpp
    )

target_link_libraries(indiclient Qt5::Network ${CMAKE_THREAD_LIBS_INIT} zlib)
target_include_directories(indiclient INTERFACE libindi)
target_include_directories(indiclient INTERFACE libindi/libs)

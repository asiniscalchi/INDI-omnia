set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml REQUIRED)

add_library(common
    IndiClient.hpp
    IndiClient.cpp
    DeviceModel.hpp
    DeviceModel.cpp
    Device.hpp
    Device.cpp
    )

target_link_libraries(common Qt5::Qml indiclient)
target_include_directories(indiclient INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)

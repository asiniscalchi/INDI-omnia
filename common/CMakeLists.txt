set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Qml REQUIRED)

add_library(common
    IndiConnection.hpp
    IndiConnection.cpp
    IndiClient.hpp
    IndiClient.cpp
    DeviceModel.hpp
    DeviceModel.cpp
    Device.hpp
    Device.cpp
    DeviceModelFacade.hpp
    DeviceModelFacade.cpp
    LogModel.hpp
    LogModel.cpp
    LogFilterModel.hpp
    LogFilterModel.cpp
    )

target_link_libraries(common Qt5::Qml indiclient)
target_include_directories(indiclient INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)

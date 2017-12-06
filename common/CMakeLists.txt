set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_library(common
    IndiClient.hpp
    IndiClient.cpp
    DeviceModel.hpp
    DeviceModel.cpp
    Device.hpp
    Device.cpp
    )

target_link_libraries(common indiclient)
target_include_directories(indiclient INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)

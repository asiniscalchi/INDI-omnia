cmake_minimum_required(VERSION 3.0.1)

project(indi-omnia LANGUAGES CXX C)

set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_RELEASE "0_devel")
configure_file (Version.h.in Version.h)

enable_testing()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_subdirectory(external)
add_subdirectory(common)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    common
    )

add_subdirectory(installer)

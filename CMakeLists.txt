cmake_minimum_required(VERSION 3.1.0)
enable_testing()

project(indi-omnia LANGUAGES CXX C)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wno-long-long -pedantic")

set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_RELEASE "1_devel")
configure_file (Version.h.in Version.h)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 5.9 COMPONENTS Core Quick REQUIRED)

add_subdirectory(external)
add_subdirectory(common)
add_subdirectory(resources)
add_subdirectory(qml)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    qml
    resources
    common
    )

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

add_subdirectory(installer)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_library(common
    IndiClient.hpp
    IndiClient.cpp
    )

target_link_libraries(common indiclient)

add_subdirectory(test)

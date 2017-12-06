set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Test)

set(TEST_NAME testIndiClient)
add_executable(${TEST_NAME} ${TEST_NAME}.cpp ${TEST_NAME}.hpp)
target_link_libraries(${TEST_NAME} Qt5::Test)
add_test(${TEST_NAME}${TEST_NAME})

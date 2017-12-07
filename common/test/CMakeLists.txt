set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Test)

set(TEST_NAME TestIndiClient)
add_executable(${TEST_NAME} ${TEST_NAME}.cpp ${TEST_NAME}.hpp)
target_link_libraries(${TEST_NAME} Qt5::Test common indiclient)
add_test(${TEST_NAME} ${TEST_NAME})

set(TEST_NAME TestDeviceModel)
add_executable(${TEST_NAME} ${TEST_NAME}.cpp ${TEST_NAME}.hpp)
target_link_libraries(${TEST_NAME} Qt5::Test common indiclient)
add_test(${TEST_NAME} ${TEST_NAME})

cmake_minimum_required(VERSION 3.27)
project(WalkAwakeGtest)

set(CMAKE_CXX_STANDARD 17)

add_executable(WalkAwakeGtest Tests/AlarmManagerTest.cpp)

include_directories(Google_test/WalkAwake_Backend)
add_subdirectory(Google_test/WalkAwake_Backend)

target_link_libraries(WalkAwakeGtest gmock gtest gtest_main waSettingsLib waAlarmLib waCameraLib curl ao mpg123 pthread)

add_subdirectory(Google_test)

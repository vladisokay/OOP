cmake_minimum_required(VERSION 3.10)
project(labWork_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lw2 main.cpp ../src/decimal.cpp)
add_executable(tests ../tests/test_main.cpp ../src/decimal.cpp)

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

target_include_directories(lw2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

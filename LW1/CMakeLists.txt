cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lw1 main.cpp textReplace.cpp)

add_executable(tests test_main.cpp textReplace.cpp)

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

target_include_directories(lw1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

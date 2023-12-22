cmake_minimum_required(VERSION 3.10)
project(labWork_5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDE_SOURCES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)

add_executable(lw5 main.cpp
        include/list.hpp
        include/allocator.hpp)

enable_testing()
add_executable(tests ${TEST_SOURCES})
add_test(MyTest tests)

target_include_directories(tests PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(tests PRIVATE gtest gtest_main)

set_target_properties(lw5 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

set_target_properties(tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
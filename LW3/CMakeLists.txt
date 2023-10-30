cmake_minimum_required(VERSION 3.10)
project(labWork_3)


set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CONTAINERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/containers)


file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.h)
file(GLOB_RECURSE CONTAINERS LIST_DIRECTORIES false ${CONTAINERS_DIR}/*)

add_library(containers_lib ${CONTAINERS})  


set_target_properties(containers_lib PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)


add_library(${PROJECT_NAME}_lib
            ${SOURCES}
            ${INCLUDES})            

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(${PROJECT_NAME}_lib containers_lib)
target_link_libraries(${PROJECT_NAME}_lib containers_lib)



add_executable(lw3 main.cpp )

add_dependencies(lw3 ${PROJECT_NAME}_lib containers_lib)
target_link_libraries(lw3 ${PROJECT_NAME}_lib containers_lib)

# add_executable(testVector 
#               tests/VectorTest.cpp
#               src/containers/vector.cpp)

# add_executable(testPoint
#                tests/PointTest.cpp
#                src/figures/point.cpp)

# add_executable(testPentagon
#                tests/PentagonTest.cpp 
#                src/figures/pentagon.cpp)

# add_executable(testHexagon
#                tests/HexagonTest.cpp 
#                src/figures/hexagon.cpp)

# add_executable(testOctagon
#                tests/OctagonTest.cpp
#                src/figures/octagon.cpp)

# find_package(GTest REQUIRED)
# target_link_libraries(testVector GTest::GTest GTest::Main)
# target_link_libraries(testPoint GTest::GTest GTest::Main)
# target_link_libraries(testPentagon GTest::GTest GTest::Main)
# target_link_libraries(testHexagon GTest::GTest GTest::Main)
# target_link_libraries(testOctagon GTest::GTest GTest::Main)



CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P2)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g -std=c++11 -lgcov --coverage")

add_executable(testEntero ${PROJECT_SOURCE_DIR}entero_unittest.cpp ${PROJECT_SOURCE_DIR}Entero.cpp)
target_link_libraries(testEntero ${GTEST_LIBRARIES} pthread)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P2)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g -lgcov --coverage")

add_executable(practica3 ${PROJECT_SOURCE_DIR}main.cpp ${PROJECT_SOURCE_DIR}Entero.cpp ${PROJECT_SOURCE_DIR}funciones.cpp)
add_executable(testEntero ${PROJECT_SOURCE_DIR}entero_unittest.cpp ${PROJECT_SOURCE_DIR}Entero.cpp ${PROJECT_SOURCE_DIR}funciones.cpp)
target_link_libraries(testEntero ${GTEST_LIBRARIES} pthread)

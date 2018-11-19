CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P4)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g -lgcov --coverage")

# add_executable(practica3 ${PROJECT_SOURCE_DIR}main.cpp ${PROJECT_SOURCE_DIR}Entero.cpp ${PROJECT_SOURCE_DIR}funciones.cpp)
add_executable(mochila ${PROJECT_SOURCE_DIR}opcion-B/main.cpp
                       ${PROJECT_SOURCE_DIR}opcion-B/Material.cpp
                       ${PROJECT_SOURCE_DIR}opcion-B/Datos.cpp
                       ${PROJECT_SOURCE_DIR}opcion-B/Solucion.cpp
                       ${PROJECT_SOURCE_DIR}opcion-B/funciones.cpp)
add_executable(testMaterial ${PROJECT_SOURCE_DIR}opcion-B/tests/material_unittest.cpp
                            ${PROJECT_SOURCE_DIR}opcion-B/Material.cpp)
target_link_libraries(testMaterial ${GTEST_LIBRARIES} pthread)

add_executable(testDatos ${PROJECT_SOURCE_DIR}opcion-B/tests/datos_unittest.cpp
                         ${PROJECT_SOURCE_DIR}opcion-B/Material.cpp
                         ${PROJECT_SOURCE_DIR}opcion-B/Datos.cpp)
target_link_libraries(testDatos ${GTEST_LIBRARIES} pthread)

add_executable(testSolucion ${PROJECT_SOURCE_DIR}opcion-B/tests/solucion_unittest.cpp
                            ${PROJECT_SOURCE_DIR}opcion-B/Material.cpp
                            ${PROJECT_SOURCE_DIR}opcion-B/Datos.cpp
                            ${PROJECT_SOURCE_DIR}opcion-B/Solucion.cpp)
target_link_libraries(testSolucion ${GTEST_LIBRARIES} pthread)
add_executable(testGrafo ${PROJECT_SOURCE_DIR}opcion-C/test/grafo_unittest.cpp
                         ${PROJECT_SOURCE_DIR}opcion-C/Edge.cpp
                         ${PROJECT_SOURCE_DIR}opcion-C/funcionesAuxiliares.cpp
                         ${PROJECT_SOURCE_DIR}opcion-C/Vertex.cpp
                         ${PROJECT_SOURCE_DIR}opcion-C/Graph.cpp)
target_link_libraries(testGrafo ${GTEST_LIBRARIES} pthread)
add_executable(TSP ${PROJECT_SOURCE_DIR}opcion-C/main.cpp
                       ${PROJECT_SOURCE_DIR}opcion-C/Edge.cpp
                       ${PROJECT_SOURCE_DIR}opcion-C/funcionesAuxiliares.cpp
                       ${PROJECT_SOURCE_DIR}opcion-C/Vertex.cpp
                       ${PROJECT_SOURCE_DIR}opcion-C/Graph.cpp)

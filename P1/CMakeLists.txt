CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P1)
set (PROJECT_SOURCE_DIR "./src/")
set (CMAKE_CXX_FLAGS "-lrt -g -lm")
add_executable(ordenacion.exe ${PROJECT_SOURCE_DIR}main.cpp
${PROJECT_SOURCE_DIR}funcionesAuxiliares.cpp
${PROJECT_SOURCE_DIR}Tiempo.cpp
${PROJECT_SOURCE_DIR}Vector.cpp
${PROJECT_SOURCE_DIR}sistemaEcuaciones.cpp)

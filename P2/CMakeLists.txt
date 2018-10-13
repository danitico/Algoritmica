CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P2)
set (PROJECT_SOURCE_DIR "./src/")
set (CMAKE_CXX_FLAGS "-lrt -g -lm")
add_executable(practica2.exe ${PROJECT_SOURCE_DIR}main.cpp
${PROJECT_SOURCE_DIR}funcionesAuxiliares.cpp
${PROJECT_SOURCE_DIR}Tiempo.cpp
${PROJECT_SOURCE_DIR}sistemaEcuaciones.cpp
${PROJECT_SOURCE_DIR}Datos.cpp)

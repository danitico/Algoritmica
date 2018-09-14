CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P1)
set (CMAKE_CXX_FLAGS "-lrt")
add_executable(ordenacion.exe main.cpp funcionesAuxiliares.cpp Tiempo.cpp Vector.cpp)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P6)
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g -std=c++11 -O2")

add_executable(ciclosHamiltonianos
   ${PROJECT_SOURCE_DIR}problemaViajero/main.cpp
   ${PROJECT_SOURCE_DIR}problemaViajero/funcionesAuxiliares.cpp
   ${PROJECT_SOURCE_DIR}problemaViajero/Graph.cpp
   ${PROJECT_SOURCE_DIR}problemaViajero/Edge.cpp
   ${PROJECT_SOURCE_DIR}problemaViajero/Vertex.cpp
)

add_executable(integracion
   ${PROJECT_SOURCE_DIR}integracion/main.cpp
   ${PROJECT_SOURCE_DIR}integracion/funciones.cpp
)

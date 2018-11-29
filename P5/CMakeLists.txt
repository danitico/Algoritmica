CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P4)
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g -std=c++11")

add_executable(mochila ${PROJECT_SOURCE_DIR}mochila/main.cpp
                       ${PROJECT_SOURCE_DIR}mochila/Material.cpp
                       ${PROJECT_SOURCE_DIR}mochila/Datos.cpp
                       ${PROJECT_SOURCE_DIR}mochila/Solucion.cpp
                       ${PROJECT_SOURCE_DIR}mochila/funciones.cpp)
add_executable(cambio ${PROJECT_SOURCE_DIR}cambio/main.cpp
                      ${PROJECT_SOURCE_DIR}cambio/SistemaMonetario.cpp
                      ${PROJECT_SOURCE_DIR}cambio/Moneda.cpp
                      ${PROJECT_SOURCE_DIR}cambio/funciones.cpp)

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(P4)
set (PROJECT_SOURCE_DIR "./src/")
SET(CMAKE_CXX_FLAGS "-g")

add_executable(mochila ${PROJECT_SOURCE_DIR}main.cpp
                       ${PROJECT_SOURCE_DIR}Material.cpp
                       ${PROJECT_SOURCE_DIR}Datos.cpp
                       ${PROJECT_SOURCE_DIR}Solucion.cpp
                       ${PROJECT_SOURCE_DIR}funciones.cpp)
# add_executable(cambio ${PROJECT_SOURCE_DIR}Cambio/SistemaMonetario.cpp
#                       ${PROJECT_SOURCE_DIR}Cambio/Moneda.cpp
#                       ${PROJECT_SOURCE_DIR}Cambio/funciones.cpp)

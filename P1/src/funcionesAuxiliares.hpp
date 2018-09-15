#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <stdint.h>
#include <string>
void obtenerDatosDeSacudida();
void obtenerDatosDeQuicksort();
// void imprimirDatos(std::vector<int> const &n, std::vector<uint64_t> const &t);
void guardarDatos(std::vector<int> const &n, std::vector<uint64_t> const &t, std::string fichero);
#endif

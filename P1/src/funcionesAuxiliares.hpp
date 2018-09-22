#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <stdint.h>
#include <string>
void obtenerDatosDeSacudida();
void obtenerDatosDeQuicksort();
void ajusteDatosnoSofisticado(std::vector<double> n, std::vector<double> t);
double sumatorio(std::vector<double> n, std::vector<double> t, int a, int b);
// void imprimirDatos(std::vector<int> const &n, std::vector<uint64_t> const &t);
void guardarDatos(std::vector<double> const &n, std::vector<double> const &t, std::string fichero);
#endif

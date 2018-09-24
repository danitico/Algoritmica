#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <stdint.h>
#include <string>
void obtenerDatosDeSacudida();
void obtenerDatosDeQuicksort();
void ajusteDatosnoSofisticado(std::vector<double> n, std::vector<double> t);
void ajusteDatosSofisticado(std::vector<double> n, std::vector<double> t);
void verFunciones(std::vector<std::vector<double> > & X, double & coeficiente);
double sumatorio(std::vector<double> n, std::vector<double> t, int a, int b);
void guardarDatos(std::vector<double> const &n, std::vector<double> const &t, std::vector<double> const & tiempoestimado, std::string fichero);
#endif

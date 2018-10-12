#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
unsigned long long int combinatorioConRecursividad(int n, int k);
unsigned long long int combinatorioSinRecursividad(int n, int k);
unsigned long long int combinatorioConRecursividadyTabla(int n, int k, std::vector<std::vector<unsigned long long int> > & datos);
void combinatorios(int n);
#endif

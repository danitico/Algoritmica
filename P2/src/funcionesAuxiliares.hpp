#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <string>
double combinatorioConRecursividad(int n, int k);
double combinatorioSinRecursividad(int n, int k);
double combinatorioConRecursividadyTabla(int n, int k, std::vector<std::vector<double> > & datos);
void combinatorios(/*int n_minimo, int n_maximo, int repeticiones*/);
void preparacionMatriz(std::vector<std::vector<double> > & datos, int filas, int columnas);
void Hanoi(int discos, int varilla_origen, int varilla_destino, int & contador);
void guardarDatos(std::vector<double> & n, std::vector<double> & t, std::string fichero);
#endif

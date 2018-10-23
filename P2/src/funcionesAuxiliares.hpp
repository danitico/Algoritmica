#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include <vector>
#include <string>
#include "Datos.hpp"
double combinatorioConRecursividad(int n, int k);
double combinatorioSinRecursividad(int n, int k);
double combinatorioConRecursividadyTabla(int n, int k, std::vector<std::vector<double> > & datos);
void combinatorios1();
void combinatorios2();
void combinatorios3();
void preparacionMatriz(std::vector<std::vector<double> > & datos, int filas, int columnas);
void Hanoi(int discos, int varilla_origen, int varilla_destino, int & contador);
void datosHanoi();
#endif

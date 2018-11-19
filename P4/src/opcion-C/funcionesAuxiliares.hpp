#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "Graph.hpp"
#include <string>
void cargarVertices(Graph & grafo, std::string fichero1, std::string fichero2);
void mostrarGrafo(Graph & grafo, int & coste_total);
Graph TSP(Graph & grafo, int & coste_total);
#endif

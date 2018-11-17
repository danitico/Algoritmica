#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "Graph.hpp"
   void cargarVertices(Graph & grafo, std::string fichero1, std::string fichero2);
   void mostrarGrafo(Graph & grafo);
   Graph kruskal_algorithm(Graph const & grafo, float & coste_total);
#endif

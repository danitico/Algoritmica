/*!
   \file funcionesAuxiliares.hpp
   \brief Fichero con funciones auxiliares
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP
#include "clases/Graph.hpp"
namespace ed{
   void cargarVertices(Graph & grafo, std::string fichero);
   void mostrarGrafo(Graph & grafo);
   void borrarGrafo(Graph & grafo);
   void BorrarVertice(Graph & grafo, Vertex a);
   void borrarLado(Graph & grafo, Vertex a, Vertex b);
   void modificarCosteConexion(Graph & grafo, Vertex a, Vertex b);
   void agnadirVertice(Graph & grafo, Punto & a);
   Graph kruskal_algorithm(Graph const & grafo, float & coste_total);
}
#endif

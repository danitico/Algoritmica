/*!
   \file Graph.hpp
   \brief Fichero de la clase Graph
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Edge.hpp"
#include <vector>
// #include "Vertex.hpp"
// #include "Punto.hpp"
#include <vector>
namespace ed{
   //!  Definición de la clase Graph
   class Graph{
      //! @name Atributos de la clase Graph
      private:
         std::vector<Vertex> vertexes_; //!< Vector de la STL que contiene todos los vertices del grafo
         std::vector<Edge> edges_; //!< Vector de la STL que contiene todos los lados del grafo
         std::vector<std::vector<int> > matrix_; //!< Matriz que representa la matriz de adyacencias del grafo
         int currentVertex_;
         int currentEdge_;
         int etiquetas_;
      //! @name Metodos publicos de la clase Graph
      public:
         //! @name Constructor de la clase Graph
         /**
          * @fn inline Graph()
          * @brief Inicializa un objeto de la clase Graph
          * @note Constructor de la clase Graph
          * @note Función de tipo inline
          */
         inline Graph(){
            vertexes_.resize(0);
            edges_.resize(0);
            matrix_.resize(0);
            currentVertex_=-1;
            currentEdge_=-1;
            etiquetas_=0;
         }
         //! @name Observadores de la clase Graph
         /**
          * @fn inline std::vector<Vertex> getVertexVector() const
          * @brief Nos devuelve el vector de vértices
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un vector de objetos Vertex
          */
         inline std::vector<Vertex> getVertexVector() const{return vertexes_;}
         /**
          * @fn inline std::vector<Edge> getEdgeVector() const
          * @brief Nos devuelve el vector de lados
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un vector de objetos Edge
          */
         inline std::vector<Edge> getEdgeVector() const{return edges_;}
         /**
          * @fn inline std::vector<std::vector<int> > getMatrix() const
          * @brief Nos devuelve la matriz de conexiones
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un vector de vectores de enteros
          */
         inline std::vector<std::vector<int> > getMatrix() const{return matrix_;}
         /**
          * @fn inline int getCurrentVertex() const
          * @brief Nos devuelve el valor del cursor de vertices
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un entero
          */
         inline int getCurrentVertex() const{return currentVertex_;}
         /**
          * @fn inline int getCurrentEdge() const
          * @brief Nos devuelve el valor del cursor de lados
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un entero
          */
         inline int getCurrentEdge() const{return currentEdge_;}
         /**
          * @fn inline int getEtiquetas() const
          * @brief Nos devuelve la siguiente etiqueta que tendra el vertice nuevo a añadir
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un entero
          */
         inline int getEtiquetas() const{return etiquetas_;}
         /**
          * @fn bool isEmpty() const
          * @brief Nos dice si el grafo esta vacio, es decir, que no tenga ningun vertice
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un valor booleano
          */
         bool isEmpty() const;
         /**
          * @fn bool isDirected() const
          * @brief Nos dice si el grafo es dirigido
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @return Devuelve un valor booleano
          */
         bool isDirected() const;
         /**
          * @fn bool adjacent(Vertex u, Vertex v) const
          * @brief Devuelve true si los dos vertices son adyacentes y false en el caso contrario
          * @param u Objeto de la clase Vertex
          * @param v Objeto de la clase Vertex
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre u y v son vertices del grafo
          * @return Devuelve un valor booleano
          */
         bool adjacent(Vertex u, Vertex v) const;
         /**
          * @fn bool hasCurrVertex() const
          * @brief Nos dice si el cursor de vertices apunta a uno de ellos
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @return Devuelve un valor booleano
          */
         bool hasCurrVertex() const;
         /**
          * @fn Vertex currVertex() const
          * @brief Nos devuelve el vertice al que apunta el cursor
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre hasCurrVertex()
          * @return Devuelve un objeto de la clase Vertex
          */
         Vertex currVertex() const;
         /**
          * @fn bool hasCurrEdge() const
          * @brief Devuelve true si el cursor apunta a un lado
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @return Devuelve un valor booleano
          */
         bool hasCurrEdge() const;
         /**
          * @fn Edge currEdge() const
          * @brief Devuelve el lado al que apunta el cursor
          * @note Observador de la clase Graph
          * @note Funcion de tipo const
          * @pre hasCurrEdge()
          * @return Devuelve un objeto de la clase Edge
          */
         Edge currEdge() const;
         //! @name Modificadores de la clase Graph
         /**
          * @fn void setEdgeVector(int x, Edge & a)
          * @brief Modifica el vector de objetos de la clase Edge
          * @param x Entero que representa la posicion
          * @param a Objeto de la clase Edge
          * @note Modificador de la clase Graph
          */
         void setEdgeVector(int x, Edge & a);
         /**
          * @fn void setMatrix(int x, int y, int data)
          * @brief Modifica el vector de objetos de la clase Edge
          * @param x Entero que representa la posicion
          * @param y Entero que representa la posicion
          * @param data Representa la posicion del lado
          * @note Modificador de la clase Graph
          */
         void setMatrix(int x, int y, int data);
         /**
          * @fn void addVertex(Punto p)
          * @brief Crea un nuevo vertice
          * @note Modificador de la clase Graph
          * @param p Posicion del vertice
          * @post hasCurrVertex() && currVertex.getData()=d
          */
         void addVertex(Punto p);
         /**
          * @fn void addEdge(Vertex u, Vertex v, float distancia)
          * @brief Crea un enlace entre el vertice u y v
          * @note Modificador de la clase Graph
          * @param u Vertice inicio
          * @param v Vertice final
          * @param distancia Distancia entre el vertice inicio y final
          * @pre U y V son vertices del grafo
          * @post hasCurrEdge() && currEdge().has(v) && currEdge().other(v)=u && currEdge().getData()=e
          * @post hasCurrVertex() && currVertex.getData()=d
          */
         void addEdge(Vertex const & u, Vertex const & v, float distancia);
         /**
          * @fn void removeVertex()
          * @brief Borra el vertice actual y todas sus conexiones o lados
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void removeVertex();
         /**
          * @fn void removeEdge()
          * @brief Borra el lado actual
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void removeEdge();
         //! @name Modificadores de la clase Graph que se encarga del movimiento del cursor
         /**
          * @fn void gotoVertex(Vertex const & v)
          * @brief Mueve el cursor al vertice pasado por argumentos
          * @param v Objeto de la clase Vertex
          * @note Modificador de la clase Graph
          * @pre v es un vértice del grafo
          * @post currVertex().getData()=v.getData()
          */
         void gotoVertex(Vertex const & v);
         /**
          * @fn void gotoEdge(Vertex const & u, Vertex const & v)
          * @brief Mueve el cursor hacia el lado que conectan los dos vertices pasados por argumentos
          * @param u Objeto de la clase Vertex
          * @param v Objeto de la clase Vertex
          * @note Modificador de la clase Graph
          * @pre u,v son vértices del grafo
          * @post hasCurrEdge() implies currVertex()=u
          * @post currEdge().first()=u
          * @post currEdge().second()=v
          */
         void gotoEdge(Vertex const & u, Vertex const & v);
         /**
          * @fn void goToFirstVertex()
          * @brief El cursor se mueve al primer vértice
          * @note Modificador de la clase Graph
          * @post isEmpty() implies not hasCurrVertex()
          */
         void goToFirstVertex();
         /**
          * @fn void nextVertex()
          * @brief El cursor se mueve al siguiente vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          */
         void nextVertex();
         /**
          * @fn void goToFirstEdge()
          * @brief El cursor se mueve a la primera conexión del vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge()
          * @post isDirected() implies currVertex()==currEdge().first()
          * @post not isDirected( implies currEdge().has(currVertex())
          */
         void goToFirstEdge();
         /**
          * @fn void nextEdge()
          * @brief El cursor se mueve a la siguiente conexión del vértice
          * @note Modificador de la clase Graph
          * @pre hasCurrVertex()
          * @post hasCurrEdge()
          * @post isDirected() implies currVertex()==currEdge().first()
          * @post not isDirected( implies currEdge().has(currVertex())
          */
         void nextEdge();
         //! @name Operadores de la clase Graph
         /**
          * @fn Graph & operator=(Graph const &g)
          * @brief Operador = sobrecargado
          * @note Operador sobrecargado de la clase Graph
          * @pre *this != g
          * @return Objeto de la clase Graph
          */
         Graph & operator=(Graph const &g);
   };
}
#endif

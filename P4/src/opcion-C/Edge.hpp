/*!
   \file Edge.hpp
   \brief Fichero de la clase Edge
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef EDGE_HPP
#define EDGE_HPP
#include "Vertex.hpp"
namespace ed{
   //!  Definición de la clase Edge
   class Edge{
      //! @name Atributos de la clase Edge
      private:
         float distancia_;//!< Variable flotante que representa la distancia entre dos vertices
         Vertex inicio_;//!< Primer vertice del segmento
         Vertex fin_;//!< Segundo vertice del segmento
      //! @name Métodos públicos de la clase Edge
      public:
         //! @name Observadores de la clase Edge
         /**
          * @fn inline float getData() const
          * @brief Devuelve el atributo privado distancia_
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve la distancia entre los dos vertices
          */
         inline float getData() const{return distancia_;}
         /**
          * @fn bool has(Vertex u) const
          * @brief Dice si el objeto Vertex se encuentra en el lado
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @return Devuelve true si el parametro es uno de los vertices, y false en el caso contrario
          */
         bool has(Vertex const & u) const;
         /**
          * @fn Vertex other(Vertex u) const
          * @brief Devuelve el otro vertice que forma parte del segmento
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @pre has(u)
          * @post has(retVal) && and other(retVal)=u
          * @return Devuelve un objeto de la clase Vertex
          */
         Vertex other(Vertex const & u) const;
         /**
          * @fn inline Vertex first() const
          * @brief Devuelve el vertice inicial si estamos en grafo dirigido, si no devuelve uno de los vertices
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @post other(retVal)==second()
          * @return Devuelve un objeto de la clase Vertex
          */
         inline Vertex first() const{return inicio_;}
         /**
          * @fn inline Vertex second() const
          * @brief Devuelve el vertice final si estamos en grafo dirigido, si no devuelve uno de los vertices
          * @note Observador de la clase Edge
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @post other(retVal)==first()
          * @return Devuelve un objeto de la clase Vertex
          */
         inline Vertex second() const{return fin_;}
         //! @name Modificadores de la clase Edge
         /**
          * @fn inline void setData(float distancia)
          * @brief Modifica el atributo privado distancia_
          * @param distancia El nuevo valor del atributo privado distancia_
          * @note Funcion de tipo inline
          * @note Modificador de la clase Edge
          */
         inline void setData(float const & distancia){distancia_=distancia;}
         /**
          * @fn inline void setFirstVertex(Vertex const & u)
          * @brief Modifica el atributo privado inicio_
          * @param u El nuevo valor del atributo privado inicio_
          * @note Funcion de tipo inline
          * @note Modificador de la clase Edge
          */
         inline void setFirstVertex(Vertex const & u){inicio_=u;}
         /**
          * @fn inline void setSecondVertex(Vertex const & u)
          * @brief Modifica el atributo privado fin_
          * @param u El nuevo valor del atributo privado fin_
          * @note Funcion de tipo inline
          * @note Modificador de la clase Edge
          */
         inline void setSecondVertex(Vertex const & u){fin_=u;}
         /**
          * @fn bool operator<(Edge const & lado)
          * @brief Nos dice si un lado es más pequeno que otro segun su coste
          * @note Operador sobrecargado de la clase Edge
          * @return Nos devuelve true si el primero es menor que el segundo. False en el caso contrario
          */
         bool operator<(Edge const & lado);
         /**
          * @fn Edge & operator=(Edge const & lado)
          * @brief Operador sobrecargado =
          * @note Operador sobrecargado de la clase Edge
          * @return Objeto de las clase Edge
          */
         Edge & operator=(Edge const & lado);
   };
}
#endif

/*!
   \file Vertex.hpp
   \brief Fichero de la clase Vertex
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <stdlib.h>
#include <cassert>
#include <vector>
#include "Punto.hpp"
#define COTA_ERROR 1.0e-6 //!< Cota de error para la comparación de números reales
namespace ed{
   //!  Definición de la clase Vertex
   class Vertex{
      //! @name Atributos de la clase Vertex
      private:
         Punto p_; //!< Objeto de la clase Punto que representa la posicion del vertice
         int label_; //!< Etiqueta que diferencia a unos vertices de otros
      //! @name Métodos públicos de la clase Vertex
      public:
         //! @name Observadores de la clase Vertex
         /**
          * @fn inline Punto getData() const
          * @brief Devuelve el atributo privado p_
          * @note Observador de la clase Vertex
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @return Devuelve un objeto de la clase Punto
          */
         inline Punto getData() const{return p_;}
         /**
          * @fn inline int getLabel() const
          * @brief Devuelve el atributo privado label_
          * @note Observador de la clase Vertex
          * @note Funcion de tipo const
          * @note Funcion de tipo inline
          * @post La etiqueta es única en el grafo que se encuentre
          * @return Devuelve un entero que represeta la etiqueta del vertice
          */
         inline int getLabel() const{return label_;}
         //! @name Modificadores de la clase Vertex
         /**
          * @fn void setData(Punto const & p)
          * @brief Modifica el atributo privado p_
          * @param p El nuevo valor del atributo privado p_
          * @note Modificador de la clase Vertex
          */
         void setData(Punto const & p){p_=p;}
         /**
          * @fn void setLabel(int label)
          * @brief Modifica el atributo privado label_
          * @param label El nuevo valor del atributo privado label_
          * @note Modificador de la clase Vertex
          */
         void setLabel(int label){label_=label;}
         //! @name Operadores
         /**
          * @fn bool operator==(Vertex const & vertice) const
          * @brief Compara las coordenadas de los vértices
          * @param vertice Objeto de la clase Vertex
          * @note Operador sobrecargado de la clase Vertex
          * @note Funcion de tipo const
          * @post valorDevuelto == (this->getData() == vertice.getData())
          * @return Devuelve true si las coordenadas de los vertices son iguales,y false en el caso contrario
          */
         bool operator==(Vertex const & vertice) const;
         /**
          * @fn bool operator!=(Vertex const & vertice) const
          * @brief Compara las coordenadas de los vértices
          * @param vertice Objeto de la clase Vertex
          * @note Operador sobrecargado de la clase Vertex
          * @note Funcion de tipo const
          * @post valorDevuelto == (this->getData() == vertice.getData())
          * @return Devuelve true si las coordenadas de los vertices son distintas,y false en el caso contrario
          */
         bool operator!=(Vertex const & vertice) const;
         /**
          * @fn Vertex &operator=(Vertex const &vertice)
          * @brief Iguala un vertice a otro
          * @param vertice Objeto de la clase Vertex
          * @note Operador sobrecargado de la clase Vertex
          * @post *this == vertice
          * @return Devuelve un objeto de la clase Vertex
          */
         Vertex &operator=(Vertex const &vertice);
   };
}
#endif

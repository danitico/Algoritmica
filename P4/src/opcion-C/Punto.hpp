/*!
   \file Punto.hpp
   \brief Fichero de la clase Punto
   \author Daniel Ranchal Parrado
   \date
*/
#ifndef PUNTO_HPP
#define PUNTO_HPP
#include <cmath>
#include <iostream>
using std::istream;
using std::ostream;
#define COTA_ERROR 1.0e-6 //!< Cota de error para la comparación de números reales
namespace ed{
   //!  Definición de la clase Vertex
   class Punto{
      //! @name Atributos de la clase Punto
      private:
         float x_;
         float y_;
      //! @name Funciones o metodos publicos de la clase Punto
      public:
         //! @name Constructores de la clase Punto
         /**
          * @fn Punto(float x=0.0, float y=0.0)
          * @param x Parametro por defecto
          * @param y Parametro por defecto
          * @brief Construye un objeto de la clase Punto
          * @note Constructor de la clase Punto
          */
         Punto(float x=0.0, float y=0.0){
            this->setX(x);
            this->setY(y);
         }
         /**
          * @fn Punto(Punto const &p)
          * @param p Objeto de la clase Punto
          * @brief Constructor de copia
          * @note Constructor de copia la clase Punto
          */
         Punto(Punto const &p){
            this->setX(p.getX());
            this->setY(p.getY());
         }
         //! @name Observadores de la clase Punto
         /**
          * @fn inline float getX() const
          * @brief Devuelve la coordenada x
          * @note Observador de la clase Punto
          * @note Funcion inline
          * @note Funcion const
          * @return devuelve la coordenada x
          */
         inline float getX() const{return x_;}
         /**
          * @fn inline float getY() const
          * @brief Devuelve la coordenada y
          * @note Observador de la clase Punto
          * @note Funcion inline
          * @note Funcion const
          * @return devuelve la coordenada y
          */
         inline float getY() const{return y_;}
         //! @name Modificadores de la clase Punto
         /**
          * @fn inline void setX(float const &x)
          * @brief Modifica la coordenada x
          * @note Modificador de la clase Punto
          * @note Funcion inline
          */
         inline void setX(float const &x){x_=x;}
         /**
          * @fn inline void setY(float const &y)
          * @brief Modifica la coordenada y
          * @note Modificador de la clase Punto
          * @note Funcion inline
          */
         inline void setY(float const &y){y_=y;}
         //! @name Operadores
         /**
          * @fn Punto & operator=(Punto const &p)
          * @brief Operador sobrecargado =
          * @note Operador sobrecargado de la clase Punto
          * @return Objeto de las clase Punto
          */
         Punto & operator=(Punto const &p);
         /**
          * @fn Punto & operator=(Punto const &p)
          * @brief Nos dice si dos objetos son iguales
          * @note Operador sobrecargado de la clase Punto
          * @return Nos devuelve true si son iguales. False en el caso contrario
          */
         bool operator==(Punto const &p) const;
         /**
          * @fn void leerPunto()
          * @brief Nos permite introducir por pantalla las coordenadas
          */
         void leerPunto();
         /**
          * @fn void escribirPunto();
          * @brief Nos permite mostrar por pantalla un objeto de la clase Punto
          */
         void escribirPunto();
   };
   /**
    * @fn float distancia(Punto const &p1, Punto const &p2)
    * @brief Devuelve la distancia euclidea entre dos objetos de la clase Punto
    * @return Devuelve un float que representa la distancia
    */
   float distancia(Punto const &p1, Punto const &p2);
}
#endif

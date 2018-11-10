/*!
   \file Punto.cpp
   \brief Fichero de la clase Punto
   \author Daniel Ranchal Parrado
   \date
*/
#include "Punto.hpp"
#include "../macros.hpp"
#include <iostream>
ed::Punto & ed::Punto::operator=(Punto const &p){
   if(this != &p){
      setX(p.getX());
      setY(p.getY());
   }
   return *this;
}
bool ed::Punto::operator==(Punto const &p) const{
   if( (std::abs(p.getX() - this->getX()) < COTA_ERROR) && (std::abs(p.getY() - this->getY()) < COTA_ERROR) ){
      return true;
   }
   else{
      return false;
   }
}
void ed::Punto::leerPunto(){
   float x, y;
   std::cout<<BIPURPLE<<"Introduzca las coordenadas del punto"<<RESET<<std::endl;
   std::cout<<BIPURPLE<<"Introduzca el valor de x: "<<RESET;
   std::cin>>x;

   std::cout<<BIPURPLE<<"Introduzca el valor de y: "<<RESET;
   std::cin>>y;

   this->setX(x);
   this->setY(y);
}
void ed::Punto::escribirPunto(){
   std::cout<<"("<<this->getX()<<", "<<this->getY()<<")";
}
float ed::distancia(Punto const &p1, Punto const &p2){
   return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

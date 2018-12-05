#include "Datos.hpp"
#include <fstream>
#include <algorithm>
#include "../macros.hpp"
void Datos::setMateriales(std::string fichero_datos){
   std::ifstream f(fichero_datos.c_str());
   if(f.is_open()){
      std::string stream;
      int etiqueta, volumen;
      float precio;

      while(getline(f, stream, ' ')){
         etiqueta=stoi(stream);

         getline(f, stream, ' ');
         volumen=stoi(stream);

         getline(f, stream, '\n');
         precio=stof(stream);

         materiales_.push_back(Material(etiqueta, volumen, precio, true));
      }
      f.close();
   }
   else{
      materiales_.resize(0);
   }
}
void Datos::operator=(const Datos & a){
   this->setMateriales(a.getMateriales());
   this->setVolumenMochila(a.getVolumenMochila());
}
bool Datos::operator==(const Datos & b) const{
   if(materiales_ == b.materiales_ && getVolumenMochila() == b.getVolumenMochila()){
      return true;
   }
   else{
      return false;
   }
}
std::istream & operator>>(std::istream & stream, Datos & a){
   std::cout << BIPURPLE << "Introduzca el tamaño de la mochila: " << RESET;
   stream >> a.volumenMochila_;

   return stream;
}

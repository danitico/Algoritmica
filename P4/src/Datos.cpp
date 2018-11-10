#include "Datos.hpp"
#include <fstream>
#include <algorithm>
void Datos::setMateriales(std::string fichero_datos){
   std::ifstream f(fichero_datos.c_str());
   if(f.is_open()){
      std::string stream;
      int etiqueta, volumen, precio;

      while(getline(f, stream, ' ')){
         etiqueta=stoi(stream);

         getline(f, stream, ' ');
         volumen=stoi(stream);

         getline(f, stream, '\n');
         precio=stoi(stream);

         materiales_.push_back(Material(etiqueta, volumen, precio, true));
      }
      f.close();
   }
   else{
      materiales_.resize(0);
   }
}
void Datos::ordenarMateriales(){
   if(this->getMateriales().size()>1){
      std::sort(materiales_.begin(), materiales_.end(), ordenacionAscendente);
   }
}

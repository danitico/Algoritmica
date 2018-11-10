#ifndef DATOS_HPP
#define DATOS_HPP
#include "Material.hpp"
#include <vector>
#include <string>
class Datos{
   private:
      std::vector<Material> materiales_;
      int volumenMochila_;

      void ordenarMateriales();
      static inline bool ordenacionAscendente(Material i, Material j){return i.getPrecio() >= j.getPrecio();}
   public:
      Datos(int volumenMochila=0, std::string fichero_datos=""){
         this->setVolumenMochila(volumenMochila);
         this->setMateriales(fichero_datos);
         this->ordenarMateriales();
      }
      inline std::vector<Material> getMateriales(){
         return materiales_;
      }
      void setMateriales(std::string fichero_datos);
      inline int getVolumenMochila(){
         return volumenMochila_;
      }
      inline void setVolumenMochila(int volumenMochila){
         volumenMochila_=volumenMochila;
      }
};
#endif

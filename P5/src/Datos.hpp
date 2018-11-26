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
      inline void setMateriales(std::vector<Material> materiales){materiales_=materiales;}
   public:
      Datos(int volumenMochila=0, std::string fichero_datos="../src/opcion-B/txt/materiales.txt"){
         this->setVolumenMochila(volumenMochila);
         this->setMateriales(fichero_datos);
      }
      inline std::vector<Material> getMateriales() const{
         return materiales_;
      }
      void setMateriales(std::string fichero_datos);
      inline int getVolumenMochila() const{
         return volumenMochila_;
      }
      inline void setVolumenMochila(int volumenMochila){
         volumenMochila_=volumenMochila;
      }
      void operator=(const Datos & a);
      bool operator==(const Datos & b) const;
      friend std::istream & operator>>(std::istream & stream, Datos & a);
};
#endif

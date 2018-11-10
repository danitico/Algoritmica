#ifndef SOLUCION_HPP
#define SOLUCION_HPP
#include "Datos.hpp"
class Solucion{
   private:
      std::vector<Material> utilizados_;
      Datos datos_;
   public:
      Solucion(){
         utilizados_.resize(0);
      }
      inline std::vector<Material> getUtilizados(){
         return utilizados_;
      }
      inline Datos getDatos(){
         return datos_;
      }
      inline void setDatos(Datos datos){
         datos_=datos;
      }
};
#endif

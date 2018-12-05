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
      inline Material getUtilizados(int indice) const{
         return utilizados_[indice];
      }
      inline Datos getDatos(){
         return datos_;
      }
      inline void setDatos(Datos datos){
         datos_=datos;
      }
      void tablaMochila(std::vector<std::vector<float> > & tabla);
      void solucionMochila(std::vector<std::vector<float> > & tabla);
      friend std::ostream & operator<<(std::ostream & stream, const Solucion & a);
};
#endif

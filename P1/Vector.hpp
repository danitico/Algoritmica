#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
class Vector{
   private:
      std::vector<int> v_;
      int partition(int primero, int ultimo);
   public:
      Vector(int tamano=0){
         v_.resize(tamano);
      }
      inline void cambiarTamano(int tamano){
         v_.resize(tamano);
      }
      inline void borrarElementos(){
         v_.clear();
      }
      void rellenarVector();
      bool estaOrdenado() const;
      void ordenacionSacudida();
      void quicksort(int primero, int ultimo);
};
#endif

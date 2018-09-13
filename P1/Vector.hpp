#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
class Vector{
   private:
      std::vector<int> datos_;
      int tamano_;

   public:
      Vector(int tamano){
         datos_.resize(tamano);
      }
      void borrarElementos();
      void rellenarVector();
      bool estaOrdenado();
      void ordenacionSacudida();
};
#endif

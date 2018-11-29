#ifndef SISTEMA_MONETARIO_HPP
#define SISTEMA_MONETARIO_HPP
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Moneda.hpp"
class SistemaMonetario{
   private:
      std::vector<Moneda> monedas_;
      int cursor_max_;

      static bool sortFunct(Moneda i, Moneda j){
         return i.getValor() < j.getValor();
      }
      void sortMonedas();
      void cargarArchivo(std::string archivo);
   public:
      SistemaMonetario(std::string archivo="../src/cambio/txt/Euros.txt"){
         cursor_max_=-1;
         cargarArchivo(archivo);
      }
      std::vector<Moneda> getSistemaMonetario()const{
         return monedas_;
      }
      int size() const{
         return monedas_.size();
      }
      void cambio(std::vector<std::vector<int> > & tabla, int N);
      void solucion(std::vector<std::vector<int> > & tabla, int N);
      friend std::ostream & operator<<(std::ostream & stream, const SistemaMonetario & sistema);
};
#endif

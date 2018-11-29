#ifndef SISTEMA_MONETARIO_HPP
#define SISTEMA_MONETARIO_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include "Moneda.hpp"
class SistemaMonetario{
   private:
      std::vector<Moneda> monedas_;
      int cursor_max_;
      static bool sortFunct(Moneda i,Moneda j){return i.getValor()<j.getValor();}
      void sortMonedas();
   public:
      SistemaMonetario(){
         cursor_max_=-1;
      }
      std::vector<Moneda> getSistemaMonetario()const{
         return monedas_;
      }
      int size() const{
         return monedas_.size();
      }
      bool setMaximo(int k);
      Moneda getMaximo(){
         return monedas_[cursor_max_];
      }
      void insertMoneda(const Moneda moneda);
      bool borrarMoneda(const Moneda moneda);
      friend std::istream & operator>>(std::istream & stream, SistemaMonetario & sistema);
      friend std::ostream & operator<<(std::ostream & stream, const SistemaMonetario & sistema);
};
#endif

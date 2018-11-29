#include "Moneda.hpp"
std::ostream & operator<<(std::ostream & stream, const Moneda & moneda){
   stream << moneda.getValor();
   return stream;
}
bool Moneda::operator==(const Moneda &m) const{
   if(this->valor_==m.valor_){
      return true;
   }
   else{
      return false;
   }
}

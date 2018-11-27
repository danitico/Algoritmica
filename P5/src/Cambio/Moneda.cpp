#include "Moneda.hpp"
std::istream & operator>>(std::istream & stream, Moneda & moneda){
   string datos;
   while(getline(stream,datos,' ')){
      moneda.valor_=stoi(i);

      std::getline(stream,i,'\n');
      moneda.setTipo(i);
   }
   return stream;
}
friend std::ostream & operator<<(std::ostream & stream, const Moneda & moneda){
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

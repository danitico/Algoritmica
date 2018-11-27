#ifndef MONEDA_HPP
#define MONEDA_HPP
#include <iostream>
#include <string>
class Moneda{
   private:
      int valor_;
      std::string tipo_;
   public:
      void setValor(int valor){
         valor_=valor;
      }
      int getValor() const{
         return valor_;
      }
      void setTipo(string tipo){
         tipo_=tipo;
      }
      std::string getTipo() const{
         return tipo_;
      }
      friend std::istream & operator>>(std::istream & stream, Moneda & moneda);
      friend std::ostream & operator<<(std::ostream & stream, const Moneda & moneda);
      bool operator==(const Moneda &m) const;
};
#endif

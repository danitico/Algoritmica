#ifndef MONEDA_HPP
#define MONEDA_HPP
#include <iostream>
#include <string>
class Moneda{
   private:
      int valor_;
      std::string tipo_;
   public:
      Moneda(int valor=-1, std::string tipo=""){
         this->setValor(valor);
         this->setTipo(tipo);
      }
      void setValor(int valor){
         valor_=valor;
      }
      int getValor() const{
         return valor_;
      }
      void setTipo(std::string tipo){
         tipo_=tipo;
      }
      std::string getTipo() const{
         return tipo_;
      }
      friend std::ostream & operator<<(std::ostream & stream, const Moneda & moneda);
};
#endif

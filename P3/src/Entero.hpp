#ifndef ENTERO_HPP
#define ENTERO_HPP
#include <string>
#include <iostream>
class Entero{
   private:
      std::string numero_;
   public:
      inline Entero(std::string numero=""){
         this->setNumero(numero);
      }
      inline std::string getNumero() const{
         return this->numero_;
      }
      inline void setNumero(std::string numero){
         this->numero_=numero;
      }
      inline void setNumero(int i, int caracter){
         this->numero_[i]='0' + caracter;
      }
      void partirCadena(Entero & a, Entero & b);
      void agregarCerosFinal(int nCeros);
      void agregarCerosDelante(int nCeros);
      void quitarCerosNoSignificativos();
      Entero multiplicarPotencia10(int potencia);
      void operator=(const Entero & entero);
      friend std::ostream & operator<<(std::ostream & stream, const Entero & a);
      friend std::istream & operator>>(std::istream & stream, Entero & a);
      Entero operator+(const Entero & b);
      Entero operator*(const Entero & b);
      bool operator==(const Entero & b) const;
};
#endif

#ifndef ENTERO_HPP
#define ENTERO_HPP
#include <string>
class Entero{
   private:
      std::string numero_;
   public:
      inline Entero(std::string numero){
         this->setNumero(numero);
      }
      inline std::string getNumero() const{
         return this->numero_;
      }
      inline void setNumero(std::string numero){
         this->numero_=numero;
      }
      void partirCadena(std::string & c1, std::string & c2);
      void agregarCerosFinal(int nCeros);
      void agregarCerosDelante(int nCeros);
      void quitarCerosNoSignificativos();
      void multiplicarPotencia10(int potencia);
};
#endif

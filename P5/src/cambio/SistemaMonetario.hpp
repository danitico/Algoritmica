#ifndef SISTEMA_MONETARIO_HPP
#define SISTEMA_MONETARIO_HPP
#include <vector>
#include <string>
#include "Moneda.hpp"
class SistemaMonetario{
   private:
      std::vector<Moneda> monedas_;
      std::vector<Moneda> monedasNormalizado_;
      //Para mostrar los resultados, se pretende indicarlos en euros en vez de centimos, para aquellos
      //casos que la moneda tenga un valor >= que 100

      static inline bool ordenacionAscendente(Moneda i, Moneda j){
         return (i.getValor() <= j.getValor());
      }
      void sortMonedas();
      void cargarArchivo(std::string archivo);
      void normalizarMonedas();
   public:
      SistemaMonetario(std::string archivo="../src/cambio/txt/Euros.txt"){
         cargarArchivo(archivo);
         normalizarMonedas();
      }
      Moneda getSistemaMonetario(int indice) const{
         return monedas_[indice];
      }
      Moneda getSistemaMonetarioNormalizado(int indice) const{
         return monedasNormalizado_[indice];
      }
      int getTamagno() const{
         return monedas_.size();
      }
      void cambio(std::vector<std::vector<int> > & tabla, int N);
      void solucion(std::vector<std::vector<int> > & tabla, int N);
};
#endif

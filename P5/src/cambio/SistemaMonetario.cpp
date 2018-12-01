#include "SistemaMonetario.hpp"
#include "../macros.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
void SistemaMonetario::sortMonedas(){
   sort(monedas_.begin(), monedas_.end(), ordenacionAscendente);
}
void SistemaMonetario::cargarArchivo(std::string archivo){
   std::ifstream f(archivo.c_str());
   if(f.is_open()){
      std::string stream, tipo;
      int valor;

      while(getline(f, stream, ' ')){
         valor=atoi(stream.c_str());

         getline(f, stream, '\n');
         tipo=stream;

         monedas_.push_back(Moneda(valor, tipo));
      }
      f.close();
      sortMonedas();
   }
   else{
      monedas_.resize(0);
   }
}
void SistemaMonetario::normalizarMonedas(){
   std::vector<Moneda> monedas = this->getSistemaMonetario();

   for(int i=0; i<monedas.size(); i++){
      if(monedas[i].getValor()>=100){
         monedas[i].setValor(monedas[i].getValor()/100);
      }

      monedasNormalizado_.push_back(monedas[i]);
   }

}
void SistemaMonetario::cambio(std::vector<std::vector<int> > & tabla, int N){
	for(int i=1; i<=getSistemaMonetario().size(); i++){
      for(int j=1; j<N+1; j++){
         if(i==1 && j < getSistemaMonetario()[i-1].getValor()){
            tabla[i][j]=-1;
         }
         else{
            if(i==1){
               tabla[i][j]= 1 + tabla[i][j - getSistemaMonetario()[0].getValor()];
            }
            else{
               if(j - getSistemaMonetario()[i-1].getValor() < 0){
                  tabla[i][j]=tabla[i-1][j];
               }
               else{
                  tabla[i][j]=std::min(tabla[i-1][j], 1 + tabla[i][j-getSistemaMonetario()[i-1].getValor()]);
               }
            }
         }
      }
   }
}
void SistemaMonetario::solucion(std::vector<std::vector<int> > & tabla, int N){
   std::vector<Moneda> monedas = this->getSistemaMonetario();
   std::vector<Moneda> monedasNormalizadas = this->getSistemaMonetarioNormalizado();
   std::vector<int> contabilidad(monedas.size(), 0);
   int i = monedas.size();
   int j = N;

   while(j!=0){
      if(tabla[i][j]==tabla[i-1][j]){
         i--;
      }
      else{
         contabilidad[i-1]=contabilidad[i-1] + 1;
         j -= monedas[i-1].getValor();
      }
   }

   for(int i=monedas.size()-1; i>=0; i--){
      if(contabilidad[i]>0){
         if(contabilidad[i]==1){
            std::cout << BIRED << UNDERLINE << contabilidad[i] << RESET << BIBLUE << " " + monedasNormalizadas[i].getTipo();
         }
         else{
            std::cout << BIRED << UNDERLINE << contabilidad[i] << RESET << BIBLUE << " " + monedasNormalizadas[i].getTipo() + "s";
         }

         if(monedasNormalizadas[i].getTipo()=="Moneda"){
            if(monedasNormalizadas[i].getValor()==1 && monedas[i].getValor()==100){
               std::cout << " de " << RESET << monedasNormalizadas[i] << BIBLUE << " euro" << RESET << std::endl;
            }
            else if(monedasNormalizadas[i].getValor()==2 && monedas[i].getValor()==200){
               std::cout << " de " << RESET << monedasNormalizadas[i] << BIBLUE << " euros" << RESET << std::endl;
            }
            else if(monedasNormalizadas[i].getValor()==1 && monedas[i].getValor()==1){
               std::cout << " de " << RESET << monedasNormalizadas[i] << BIBLUE << " céntimo" << RESET << std::endl;
            }
            else{
               std::cout << " de " << RESET << monedasNormalizadas[i] << BIBLUE << " céntimos" << RESET << std::endl;
            }
         }
         else{
            std::cout << " de " << RESET << monedasNormalizadas[i] << BIBLUE << " euros" << RESET << std::endl;
         }
      }
   }
}

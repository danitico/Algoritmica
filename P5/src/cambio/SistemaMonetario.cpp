#include "SistemaMonetario.hpp"
#include <algorithm>
void SistemaMonetario::sortMonedas(){
   sort(monedas_.begin(), monedas_.end(), sortFunct);
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
   }
   else{
      monedas_.resize(0);
   }
}
bool SistemaMonetario::setMaximo(int k){
   cursor_max_=-1;
   int i=monedas_.size()-1;
   for( ; i>=0; i--){
      if(monedas_[i].getValor()<=k){
         cursor_max_=i;
         return true;
      }
   }
   return false;
}
bool SistemaMonetario::borrarMoneda(const Moneda moneda){
   for(int i=0; i<monedas_.size(); i++){
      if(moneda==monedas_[i]){
         monedas_.erase(monedas_.begin()+i);
         return true;
      }
   }
   return false;
}
void SistemaMonetario::cambio(std::vector<std::vector<int> > & tabla, int N){
	for(int i=1; i<=getSistemaMonetario().size(); i++){
      for(int j=1; j<=N+1; j++){
         if(i==1 && j < getSistemaMonetario()[i-1].getValor()){
            tabla[i][j]=-1;
         }
         else{
            if(i==1){
               tabla[i][j]= 1 + tabla[i][j - getSistemaMonetario()[0].getValor()];
            }
            else{
               if(j < getSistemaMonetario()[i-1].getValor()){
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
std::ostream & operator<<(std::ostream & stream, const SistemaMonetario & sistema){
   for(int i=0; i<sistema.monedas_.size(); i++){
      stream<<i<<": "<<sistema.monedas_[i]<<"\n";
   }
   return stream;
}

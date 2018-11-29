#include "SistemaMonetario"
#include <algorithm>
void SistemaMonetario::sortMonedas(){
   sort(monedas_.begin(), monedas_.end(), sortFunct);
}
bool SistemaMonetario::setMaximo(int k){
   cursor_max_=-1;
   int i=monedas_.size()-1
   for( ; i>=0; i--){
      if(monedas_[i].getValor()<=k){
         cursor_max_=i;
         return true;
      }
   }
   return false;
}
void SistemaMonetario::insertMoneda(const Moneda moneda){
   monedas_.push_back(moneda);
   sortMonedas();
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
void cambio(std::vector<std::vector<int> > & tabla, int N){
	for(int i=1; i<=getSistemaMonetario().size(); i++){
      for(int j=1; j<=N+1; j++){
         if(i==1 && j < getSistemaMonetario()[i-1]){
            tabla[i][j]=-1;
         }
         else{
            if(i==1){
               tabla[i][j]= 1 + tabla[i][j - getSistemaMonetario()[0]];
            }
            else{
               if(j < getSistemaMonetario()[i-1]){
                  tabla[i][j]=tabla[i-1][j];
               }
               else{
                  tabla[i][j]=std::min(tabla[i-1][j-getSistemaMonetario()[i-1]]);
               }
            }
         }
      }
   }
}
std::istream & operator>>(std::istream & stream, SistemaMonetario & sistema){
   Moneda moneda;
   while(stream>>moneda){
      sistema.insertMoneda(moneda);
   }
   return stream;
}
std::ostream & operator<<(std::ostream & stream, const SistemaMonetario & sistema){
   for(int i=0; i<sistema.monedas_.size(); i++){
      stream<<i<<": "<<sistema.monedas_[i]<<"\n";
   }
   return stream;
}

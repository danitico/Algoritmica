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
      sortMonedas();
   }
   else{
      monedas_.resize(0);
   }
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
void SistemaMonetario::solucion(std::vector<std::vector<int> > & tabla, int N){
   std::vector<Moneda> monedas= this->getSistemaMonetario();
   int i = monedas.size();
   int j = N;

   while(j!=0){
      if(tabla[i][j]==tabla[i-1][j]){
         i--;
      }
      else{
         // utilizados_.push_back(materiales[i-1]);
         std::cout << "Moneda de valor " << monedas[i-1].getValor() << std::endl;
         j -= monedas[i-1].getValor();
      }
   }
}
std::ostream & operator<<(std::ostream & stream, const SistemaMonetario & sistema){
   for(int i=0; i<sistema.monedas_.size(); i++){
      stream<<i<<": "<<sistema.monedas_[i]<<"\n";
   }
   return stream;
}

#include "funcionesAuxiliares.hpp"
unsigned long long int combinatorioConRecursividad(int n, int k) {
   if(n==k || k==0){
      return 1;
   }
   else{
      return combinatorioConRecursividad(n-1, k-1) + combinatorioConRecursividad(n-1, k);
   }
}
unsigned long long int combinatorioSinRecursividad(int n, int k){
   unsigned long long int numerador=1, denominador=1;
   if(k==0 || k==n){
      return 1;
   }
   else{
      if(n-k < k){
         for(int i=k+1; i<=n; i++){
            numerador*=i;
         }
         for(int j=1; j<= n-k; j++){
            denominador*=j;
         }
      }
      else{
         for(int i=n-k+1; i<=n; i++){
            numerador*=i;
         }
         for(int j=1; j<=k; j++){
            denominador*=j;
         }
      }
      return numerador/denominador;
   }
}
unsigned long long int combinatorioConRecursividadyTabla(int n, int k, std::vector<std::vector<unsigned long long int> > & datos){
   unsigned long long int combinatorio1=0, combinatorio2=0;
   if(n==k || k==0){
      return 1;
   }
   else{
      if(datos[n][k]==0){
         if(datos[n-1][k-1]==0){
            combinatorio1=combinatorioConRecursividadyTabla(n-1, k-1, datos);
            datos[n-1][k-1]=combinatorio1;
         }
         else{
            combinatorio1=datos[n-1][k-1];
         }

         if(datos[n-1][k]==0){
            combinatorio2=combinatorioConRecursividadyTabla(n-1, k, datos);
            datos[n-1][k]=combinatorio2;
         }
         else{
            combinatorio2=datos[n-1][k];
         }

         datos[n][k]=combinatorio1 + combinatorio2;
         return combinatorio1 + combinatorio2;
      }
      else{
         return datos[n][k];
      }
   }
}
void combinatorios(int n){

}

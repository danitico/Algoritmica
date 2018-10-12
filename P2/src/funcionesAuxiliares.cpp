#include "funcionesAuxiliares.hpp"
unsigned int combinatorioConRecursividad(int n, int k) {
   if(n==k || k==0){
      return 1;
   }
   else{
      return combinatorioConRecursividad(n-1, k-1) + combinatorioConRecursividad(n-1, k);
   }
}

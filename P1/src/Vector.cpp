#include "Vector.hpp"
#include <cstdlib>
#include <cassert>
#include <algorithm>
int Vector::partition(int primero, int ultimo){
   int pivote=v_[ultimo];
   int i=primero-1;

   for(int j=primero; j<=ultimo-1; j++){
      if(v_[j] <= pivote){
         i++;
         std::swap(v_[i], v_[j]);
      }
   }
   std::swap(v_[i+1], v_[ultimo]);
   return i+1;
}
void Vector::rellenarVector(){
   for(int i=0; i<v_.size(); i++){
      v_[i]=rand()%(10000);
   }
}
bool Vector::estaOrdenado() const{
   int i;
   for(i=0; i<v_.size() - 1; i++){
      if(v_[i] > v_[i+1]){
         return false;
      }
   }
   if(v_[i] > v_[i+1]){
      return false;
   }

   return true;
}
void Vector::ordenacionSacudida(){
   bool swapped=true;
   while(swapped){
      swapped=false;
      for(int i=0; i<v_.size()-1; i++){
         if(v_[i] > v_[i+1]){
            std::swap(v_[i], v_[i+1]);
            swapped=true;
         }
      }

      if(!swapped) break;

      swapped=false;
      for(int j=v_.size()-1; j>=0; j--){
         if(v_[j] > v_[j+1]){
            std::swap(v_[j], v_[j+1]);
            swapped=true;
         }
      }
   }

   assert(estaOrdenado());
}
void Vector::quicksort(int primero, int ultimo){
   if(primero < ultimo){
      int pivote=partition(primero, ultimo);

      quicksort(primero, pivote - 1);
      quicksort(pivote + 1, ultimo);
   }
}

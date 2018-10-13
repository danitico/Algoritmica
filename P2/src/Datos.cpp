#include "Datos.hpp"
#include <fstream>
#include <cmath>
double Datos::sumatorio(int a, int b){
   double sumatorio=0.0;
   for(int i=0; i<(this->n.size()); i++){
      sumatorio+=pow(this->n[i], a)*pow(this->t[i], b);
   }
   return sumatorio;
}
void Datos::guardarDatos(std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<(this->n.size()); i++){
         file<<this->n[i]<<" "<<this->t[i]<<" "<<this->estimado[i]<<std::endl;
      }
      file.close();
   }
}
double coeficienteDeterminacion(){
   double media1=media2=acumulado1=acumulado2=0.0;

   for(int i=0; i<(this->estimado.size()); i++){
      media1+=this->estimado[i];
   }
   for(int i=0; i<(this->t.size()); i++){
      media2+=this->t[i];
   }
   media1=media1/this->estimado.size();
   media2=media2/this->t.size();

   for(int j=0; j<(this->estimado.size()); j++){
      acumulado1+=pow((this->estimado[j]-media1), 2);
   }
   for(int j=0; j<(this->t.size()); j++){
      acumulado2+=pow((this->t[j]-media2), 2);
   }
   acumulado1=acumulado1/this->estimado.size();
   acumulado2=acumulado2/this->t.size();

   return acumulado1/acumulado2;
}

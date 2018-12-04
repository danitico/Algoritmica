#include "Estadistica.hpp"
#include "sistemaEcuaciones.hpp"
#include <fstream>
void Estadistica::guardarDatos(std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<(this->n.size()); i++){
         file<<this->n[i]<<" "<<this->t[i]<<" "<<this->estimado[i]<<std::endl;
      }
      file.close();
   }
}
double Estadistica::coeficienteDeterminacion(){
   double media1=0.0, media2=0.0, acumulado1=0.0, acumulado2=0.0;

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
double Estadistica::sumatorio(int a, int b){
   double sumatorio=0.0;
   for(int i=0; i<(this->n_modificado.size()); i++){
      sumatorio+=pow(this->n_modificado[i], a)*pow(this->t[i], b);
   }
   return sumatorio;
}
void Estadistica::calculoCoeficientes(std::vector<std::vector<double> > & X, int orden){
   std::vector<std::vector<double> > A(orden, std::vector<double>(orden,0));
   std::vector<std::vector<double> > B(orden, std::vector<double>(1,0));
   X.resize(orden, std::vector<double>(1, 0));

   for(int i=0; i<orden; i++){
      for(int j=0; j<orden; j++){
         if(i==0 && j==0){
            A[0][0]=this->t.size();
         }
         else{
            A[i][j]=sumatorio(i+j, 0);
         }
      }
   }

   for(int i=0; i<orden; i++){
      B[i][0]=sumatorio(i, 1);
   }

   resolverSistemaEcuaciones(A, B, orden, X);
}

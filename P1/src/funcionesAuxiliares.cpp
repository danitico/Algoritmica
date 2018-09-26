#include "funcionesAuxiliares.hpp"
#include "Vector.hpp"
#include "Tiempo.hpp"
#include "sistemaEcuaciones.hpp"
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
void obtenerDatosDeSacudida(){
   std::vector<double> n;
   std::vector<double> t;

   Vector a;
   Clock reloj;
   int minimo=0, maximo=0, incremento=0, repeticion=0;

   std::cout << "Introduzca el mínimo de numero de elementos: ";
   std::cin >> minimo;

   std::cout << "Introduzca el máximo de numero de elementos: ";
   std::cin >> maximo;

   std::cout << "Introduzca el incremento del valor del número de elementos: ";
   std::cin >> incremento;

   std::cout << "Introduzca el número de repeticiones: ";
   std::cin >> repeticion;

   if(minimo <= maximo){
      double sumatorio;
      for(int i=minimo; i<=maximo; i+=incremento){
         sumatorio=0;
         n.push_back(i);
         a.cambiarTamano(i);
         a.rellenarVector();
         for(int j=0; j<repeticion; j++){
            reloj.start();
            a.ordenacionSacudida();
            reloj.stop();
            assert(a.estaOrdenado());

            sumatorio+=reloj.elapsed();
            a.rellenarVector();
         }
         sumatorio=sumatorio/repeticion;
         t.push_back(sumatorio);
         a.borrarElementos();
      }
      std::cout << "Ordenación terminada" << '\n';
      ajusteDatosnoSofisticado(n, t);
}
   else{
      std::cout << "Se han introducido datos inconsistentes" << '\n';
   }
}
void obtenerDatosDeQuicksort(){
   std::vector<double> n;
   std::vector<double> t;

   Vector a;
   Clock reloj;
   int minimo=0, maximo=0, incremento=0, repeticion=0;

   std::cout << "Introduzca el mínimo de numero de elementos: ";
   std::cin >> minimo;

   std::cout << "Introduzca el máximo de numero de elementos: ";
   std::cin >> maximo;

   std::cout << "Introduzca el incremento del valor del número de elementos: ";
   std::cin >> incremento;

   std::cout << "Introduzca el número de repeticiones: ";
   std::cin >> repeticion;

   if(minimo <= maximo){
      double sumatorio;
      for(int i=minimo; i<=maximo; i+=incremento){
         sumatorio=0;
         n.push_back(i);
         a.cambiarTamano(i);
         a.rellenarVector();

         for(int j=0; j<repeticion; j++){
            reloj.start();
            a.quicksort(0, i);
            reloj.stop();
            assert(a.estaOrdenado());

            sumatorio+=reloj.elapsed();
            a.rellenarVector();
         }
         sumatorio=sumatorio/repeticion;
         t.push_back(sumatorio);
         a.borrarElementos();
      }
      std::cout << "ordenación terminada" << '\n';
      ajusteDatosSofisticado(n, t);
   }
   else{
      std::cout << "Se han introducido datos inconsistentes" << '\n';
   }
}
void ajusteDatosnoSofisticado(std::vector<double> n, std::vector<double> t){
   std::vector<std::vector<double> > A(3, std::vector<double>(3,0));

   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         if(i==0 && j==0){
            A[0][0]=t.size();
         }
         else{
            A[i][j]=sumatorio(n, t, i+j, 0);
         }
      }
   }

   std::vector<std::vector<double> > B(3, std::vector<double>(1,0));
   B[0][0]=sumatorio(n, t, 0, 1);
   B[1][0]=sumatorio(n, t, 1, 1);
   B[2][0]=sumatorio(n, t, 2, 1);

   std::vector<std::vector<double> > X(3, std::vector<double>(1,0));

   resolverSistemaEcuaciones(A, B, 3, X);

   double media1=0.0;
   double acumulado1=0.0;

   std::vector<double> tiempoestimado(n.size(), 0);
   for(int i=0; i<tiempoestimado.size(); i++){
      tiempoestimado[i]=X[0][0]+X[1][0]*n[i]+pow(n[i],2)*X[2][0];
      media1+=tiempoestimado[i];
   }
   media1=media1/(double)tiempoestimado.size();

   for(int j=0; j<tiempoestimado.size(); j++){
      acumulado1+=pow((tiempoestimado[j]-media1), 2);
   }
   acumulado1=acumulado1/(double)tiempoestimado.size();
   acumulado1=sqrt(acumulado1);

   double media2=0.0;
   double acumulado2=0.0;

   for(int k=0; k<t.size(); k++){
      media2+=t[k];
   }
   media2=media2/(double)t.size();

   for(int j=0; j<t.size(); j++){
      acumulado2+=pow((t[j]-media2), 2);
   }

   acumulado2=acumulado2/(double)t.size();
   acumulado2=sqrt(acumulado2);

   double coeficiente=((sumatorio(t, tiempoestimado, 1, 1)/n.size())-(media1*media2))/(acumulado1*acumulado2);
   coeficiente=pow(coeficiente, 2);

   guardarDatos(n, t, tiempoestimado, "sacudida.txt");
   verFunciones(X, coeficiente);
}
void ajusteDatosSofisticado(std::vector<double> n, std::vector<double> t){
   std::vector<std::vector<double> > A(2, std::vector<double>(2,0));

   for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
         if(i==0 && j==0){
            A[0][0]=t.size();
         }
         else{
            A[i][j]=sumatorio(n, t, i+j, 0);
         }
      }
   }

   std::vector<std::vector<double> > B(2, std::vector<double>(1,0));
   B[0][0]=sumatorio(n, t, 0, 1);
   B[1][0]=sumatorio(n, t, 1, 1);

   std::vector<std::vector<double> > X(2, std::vector<double>(1,0));

   resolverSistemaEcuaciones(A, B, 2, X);

   double media1=0.0;
   double acumulado1=0.0;

   std::vector<double> tiempoestimado(n.size(), 0);
   for(int i=0; i<tiempoestimado.size(); i++){
      tiempoestimado[i]=X[0][0] + (X[1][0]*n[i]*log10(n[i]));
      media1+=tiempoestimado[i];
   }
   media1=media1/tiempoestimado.size();

   for(int j=0; j<tiempoestimado.size(); j++){
      acumulado1+=pow((tiempoestimado[j]-media1), 2);
   }
   acumulado1=acumulado1/tiempoestimado.size();
   acumulado1=sqrt(acumulado1);

   double media2=0.0;
   double acumulado2=0.0;

   for(int k=0; k<t.size(); k++){
      media2+=t[k];
   }
   media2=media2/t.size();

   for(int j=0; j<t.size(); j++){
      acumulado2+=pow((t[j]-media2), 2);
   }
   acumulado2=acumulado2/t.size();
   acumulado2=sqrt(acumulado2);
   double coeficiente=((sumatorio(t, tiempoestimado, 1, 1)/n.size())-(media1*media2))/(acumulado1*acumulado2);
   coeficiente=pow(coeficiente,2);

   guardarDatos(n, t, tiempoestimado, "quicksort.txt");
   verFunciones(X, coeficiente);
}
void verFunciones(std::vector<std::vector<double> > & X, double & coeficiente){
   int elementos=-1;
   if(X.size()==2){
      std::cout << "La función es:" << '\n';
      std::cout << X[1][0] << "x+" << X[0][0] <<'\n';
   }
   else{
      std::cout << "La función es:" << '\n';
      std::cout << X[2][0] << "x²+" << X[1][0] << "x+" << X[0][0] <<'\n';
   }
   std::cout << "Su coeficiente determinacion: " << coeficiente << std::endl << std::endl;

   while(elementos!=0){
      std::cout << "Introduzca el numero de elementos para calcular el tiempo estimado: ";
      std::cin >> elementos;

      if(X.size()==2 && elementos!=0){
         std::cout << "Con un tamaño de " << elementos << " elementos quicksort tardará " << X[0][0] + (X[1][0]*elementos*log10(elementos)) << " microsegundos" << '\n';
      }
      else{
         if(elementos!=0)
            std::cout << "Con un tamaño de " << elementos << " elementos Sacudida tardará " << X[0][0]+X[1][0]*elementos+pow(elementos,2)*X[2][0] << " microsegundos" << '\n';
      }
   }
}
double sumatorio(std::vector<double> n, std::vector<double> t, int a, int b){
   double sumatorio=0.0;
   for(int i=0; i<n.size(); i++){
      sumatorio+=pow(n[i], a)*pow(t[i], b);
   }
   return sumatorio;
}
void guardarDatos(std::vector<double> const &n, std::vector<double> const &t, std::vector<double> const & tiempoestimado, std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<n.size(); i++){
         file<<n[i]<<" "<<t[i]<<" "<<tiempoestimado[i]<<std::endl;
      }
      file.close();
   }
}

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
      ajusteDatosnoSofisticado(n, t);
      std::cout << "Ordenación terminada" << '\n';
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
      ajusteDatosSofisticado(n, t);
      std::cout << "ordenación terminada" << '\n';
   }
   else{
      std::cout << "Se han introducido datos inconsistentes" << '\n';
   }
}
// void imprimirDatos(std::vector<int> const &n, std::vector<uint64_t> const &t){
//    std::cout << "Elementos\tTiempo" << '\n';
//    std::cout << "----------------------" << '\n';
//    for(int i=0; i<n.size(); i++){
//       std::cout << n[i] << "\t\t" << t[i] <<'\n';
//    }
// }
void guardarDatos(std::vector<double> const &n, std::vector<double> const &t, std::vector<double> const & tiempoestimado,std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<n.size(); i++){
         file<<n[i]<<" "<<t[i]<<" "<<tiempoestimado[i]<<std::endl;
      }
      file.close();
   }
}
void ajusteDatosnoSofisticado(std::vector<double> n, std::vector<double> t){
   std::vector<std::vector<double> > A(3, std::vector<double>(3,0));

   A[0][0]=t.size();
   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         if(i!=0 && j!=0){
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
   for(int i=0; i<3; i++){
      std::cout << X[i][0] << '\n';
   }
   double media1=0.0;
   std::vector<double> tiempoestimado(n.size(), 0);
   for(int i=0; i<tiempoestimado.size(); i++){
      tiempoestimado[i]=X[0][0]+X[1][0]*n[i]+pow(n[i],2)*X[2][0];
      media1+=tiempoestimado[i];
   }
   media1=media1/(double)tiempoestimado.size();
   double acumulado1=0.0;

   for(int j=0; j<tiempoestimado.size(); j++){
      acumulado1+=pow((tiempoestimado[j]-media1), 2);
   }
   acumulado1=acumulado1/(double)tiempoestimado.size();
   std::cout << "acumulado1: " << acumulado1 <<'\n';

   double media2=0.0;
   for(int k=0; k<t.size(); k++){
      media2+=t[k];
   }
   media2=media2/(double)t.size();
   double acumulado2=0.0;
   for(int j=0; j<t.size(); j++){
      acumulado2+=pow((t[j]-media2), 2);
   }
   acumulado2=acumulado2/(double)t.size();
   std::cout << "acumulado2: " << acumulado2 <<'\n';
   double coeficiente=acumulado1/acumulado2;
   std::cout << "coeficiente determinacion: " << coeficiente << '\n';

   guardarDatos(n, t, tiempoestimado, "sacudida.txt");
}
void ajusteDatosSofisticado(std::vector<double> n, std::vector<double> t){
   std::vector<std::vector<double> > A(2, std::vector<double>(2,0));

   A[0][0]=t.size();
   for(int i=0; i<2; i++){
      for(int j=0; j<2; j++){
         if(i!=0 && j!=0){
            A[i][j]=sumatorio(n, t, i+j, 0);
         }
      }
   }

   std::vector<std::vector<double> > B(2, std::vector<double>(1,0));
   B[0][0]=sumatorio(n, t, 0, 1);
   B[1][0]=sumatorio(n, t, 1, 1);

   std::vector<std::vector<double> > X(2, std::vector<double>(1,0));

   resolverSistemaEcuaciones(A, B, 2, X);
   for(int i=0; i<2; i++){
      std::cout << X[i][0] << '\n';
   }

   double media1=0.0;
   double acumulado1=0.0;

   std::vector<double> tiempoestimado(n.size(), 0);
   for(int i=0; i<tiempoestimado.size(); i++){
      tiempoestimado[i]=X[0][0] + (X[1][0]*n[i]*log(n[i]));
      std::cout << "pipo: " << tiempoestimado[i] <<'\n';
      media1+=tiempoestimado[i];
   }
   media1=media1/(double)tiempoestimado.size();

   for(int j=0; j<tiempoestimado.size(); j++){
      acumulado1+=pow((tiempoestimado[j]-media1), 2);
   }
   acumulado1=acumulado1/(double)tiempoestimado.size();
   std::cout << "acumulado1: " << acumulado1 <<'\n';

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
   std::cout << "acumulado2: " << acumulado2 <<'\n';
   double coeficiente=acumulado1/acumulado2;
   std::cout << "coeficiente determinacion: " << coeficiente << '\n';

   guardarDatos(n, t, tiempoestimado, "quicksort.txt");
}
double sumatorio(std::vector<double> n, std::vector<double> t, int a, int b){
   double sumatorio=0.0;
   for(int i=0; i<n.size(); i++){
      sumatorio+=pow(n[i], a)*pow(t[i], b);
   }
   return sumatorio;
}

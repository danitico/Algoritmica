#include "funcionesAuxiliares.hpp"
#include "Vector.hpp"
#include "Tiempo.hpp"
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
      guardarDatos(n, t, "sacudida.txt");
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
      guardarDatos(n, t, "quicksort.txt");
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
void guardarDatos(std::vector<double> const &n, std::vector<double> const &t, std::string fichero){
   std::ofstream file(fichero.c_str());
   if(file.is_open()){
      for(int i=0; i<n.size(); i++){
         file<<n[i]<<" "<<t[i]<<std::endl;
      }
      file.close();
   }
}
void ajusteDatosnoSofisticado(){
   std::vector<std::vector<double> > A;
   v.resize(3, 0);
   v[0].resize(3,0);
   v[1].resize(3,0);
   v[2].resize(3,0);

   for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
         
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

#include "funcionesAuxiliares.hpp"
#include "Vector.hpp"
#include "Tiempo.hpp"
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
void obtenerDatosDeSacudida(){
   std::vector<int> n;
   std::vector<uint64_t> t;

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

   uint64_t sumatorio;

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
   guardarDatos(n, t);
   // imprimirDatos(n, t);
}
void obtenerDatosDeQuicksort(){
   std::vector<int> n;
   std::vector<uint64_t> t;

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

   uint64_t sumatorio;

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
   guardarDatos(n, t);
   // imprimirDatos(n, t);
}
void imprimirDatos(std::vector<int> const &n, std::vector<uint64_t> const &t){
   std::cout << "Elementos\tTiempo" << '\n';
   std::cout << "----------------------" << '\n';
   for(int i=0; i<n.size(); i++){
      std::cout << n[i] << "\t\t" << t[i] <<'\n';
   }
}
void guardarDatos(std::vector<int> const &n, std::vector<uint64_t> const &t){
   std::ofstream file("Datos.txt");
   if(file.is_open()){
      for(int i=0; i<n.size(); i++){
         file<<n[i]<<" "<<t[i]<<std::endl;
      }
      file.close();
   }
}

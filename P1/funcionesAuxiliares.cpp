#include "funcionesAuxiliares.hpp"
#include "Vector.hpp"
#include "Tiempo.hpp"
#include <vector>
#include <iostream>
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
      // std::cout<<"i -> "<<i<<std::endl;
      // std::cout << "-------------" << '\n';
      for(int j=0; j<repeticion; j++){
         reloj.start();
         a.ordenacionSacudida();

         reloj.stop();
         std::cout << reloj.elapsed() << '\n';
         sumatorio+=reloj.elapsed();
         a.rellenarVector();
      }
      sumatorio=sumatorio/repeticion;
      std::cout << i << " -> " << sumatorio << '\n';
      a.borrarElementos();
   }
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
      // std::cout<<"i -> "<<i<<std::endl;
      // std::cout << "-------------" << '\n';
      for(int j=0; j<repeticion; j++){
         reloj.start();
         a.quicksort(0, i);

         reloj.stop();
         // std::cout << reloj.elapsed() << '\n';
         sumatorio+=reloj.elapsed();
         a.rellenarVector();
      }
      sumatorio=sumatorio/repeticion;
      std::cout << i << " -> " << sumatorio << '\n';
      a.borrarElementos();
   }
}

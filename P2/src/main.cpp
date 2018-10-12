#include <iostream>
#include "Tiempo.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   int opcion=0;
   do{
      std::cout << "\t  Menu" << '\n';
      std::cout << "------------------------" << '\n';
      std::cout << "1. Calcular el número combinatorio" << '\n';
      std::cout << "2. Calcular el número de movimientos de las torres de Hanoi" << '\n';
      std::cout << "3. Salir del programa" << '\n';
      std::cout << "Introduzca la opción deseada: ";
      std::cin >> opcion;

      switch (opcion) {
         case 1:
            std::cout << combinatorioConRecursividad(6, 4) << '\n';
            break;
         case 2:
            //opcion 2
         case 3:
            //salir
            break;
         default:
            std::cout << "Error" << '\n';
         break;
      }
   }while(opcion!=3);
}

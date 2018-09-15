#include "Vector.hpp"
#include "funcionesAuxiliares.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
int main(){
   srand(time(NULL));
   int opcion=0;
   do {
      std::cout << std::endl;
      std::cout << "\t Menu" << '\n';
      std::cout << "------------------------" << '\n';
      std::cout << "1. Método de la sacudida" << std::endl;
      std::cout << "2. Método Quicksort" << std::endl;
      std::cout << "3. Salir del programa" << std::endl << std::endl;
      std::cout << "Introduzca el método de ordenación que quiere utilizar: ";
      std::cin >> opcion;

      switch(opcion){
         case 1:
            obtenerDatosDeSacudida();
            break;
         case 2:
            obtenerDatosDeQuicksort();
         case 3:
            break;

         default:
            std::cout << "Error" << '\n';
            break;
      }
   } while(opcion!=3);
}

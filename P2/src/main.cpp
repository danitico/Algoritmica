#include <iostream>
#include "Tiempo.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   int opcion=0;
   int opcion1=0;
   int contador=0;
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
            while(opcion1!=4){
               std::cout << "1. Mediante recursividad" << '\n';
               std::cout << "2. Sin recursividad" << '\n';
               std::cout << "3. Mediante recursividad y tabla" << '\n';
               std::cout << "4. Salir del submenú" << '\n';
               std::cout << "Introduzca la opción deseada: ";
               std::cin >> opcion1;

               switch(opcion1){
                  case 1:
                     combinatorios1();
                     break;
                  case 2:
                     combinatorios2();
                     break;
                  case 3:
                     combinatorios3();
                     break;
                  case 4:
                     break;
                  default:
                     std::cout << "Error" << '\n';
                     break;
               }
            }
            break;
         case 2:
            datosHanoi();
            break;
         case 3:
            //salir
            break;
         default:
            std::cout << "Error" << '\n';
         break;
      }
   }while(opcion!=3);
}

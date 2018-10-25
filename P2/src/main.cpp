#include <iostream>
#include "Tiempo.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   int opcion=0;
   int opcion1=0;
   int contador=0;
   do{
      int posicion=2;
      std::cout << CLEAR_SCREEN;
      PLACE(1, 10);
      std::cout << BIBLUE << "Menu" << RESET;

      posicion++;
      PLACE(posicion++, 10);
      std::cout << "1. Calcular el número combinatorio";

      PLACE(posicion++, 10);
      std::cout << "2. Calcular el número de movimientos de las torres de Hanoi";

      PLACE(posicion++, 10);
      std::cout << "3. Salir del programa";

      posicion++;

      PLACE(posicion++, 10);
      std::cout << BIGREEN << "Introduzca la opción deseada: " << RESET;
      std::cin >> opcion;
      std::cin.ignore();
      std::cout << CLEAR_SCREEN;

      PLACE(3, 1);
      switch (opcion) {
         case 1:
            opcion1=0;
            while(opcion1!=4){
               posicion=2;
               std::cout << CLEAR_SCREEN;
               PLACE(1, 10);
               std::cout << BIBLUE << "Numeros Combinatorios" << RESET;

               posicion++;
               PLACE(posicion++, 10);
               std::cout << "1. Mediante recursividad";

               PLACE(posicion++, 10);
               std::cout << "2. Sin recursividad";

               PLACE(posicion++, 10);
               std::cout << "3. Mediante recursividad y tabla";

               PLACE(posicion++, 10);
               std::cout << "4. Salir del submenú";

               posicion++;
               PLACE(posicion++, 10);
               std::cout << BIGREEN << "Introduzca la opción deseada: " << RESET;
               std::cin >> opcion1;
               std::cin.ignore();
               std::cout << CLEAR_SCREEN;

               PLACE(3, 1);
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
                     std::cout << BIRED;
         				std::cout << "Opción incorrecta ";
         				std::cout << RESET;
         				std::cout << "--> ";
         				std::cout << ONIRED;
         				std::cout << opcion << std::endl;
         				std::cout << RESET;
                     break;
               }
               if(opcion1!=4){
                  std::cout << std::endl << std::endl;
                  std::cout << "Pulse ";
                  std::cout << BIGREEN;
                  std::cout << "ENTER";
                  std::cout << RESET;
                  std::cout << " para mostrar el ";
                  std::cout << INVERSE;
                  std::cout << "menú";
                  std::cout << RESET;
                  std::cin.ignore();
                  std::cout << CLEAR_SCREEN;
               }
            }
            break;
         case 2:
            datosHanoi();
            break;
         case 3:
            std::cout << INVERSE;
            std::cout << "Fin del programa" << std::endl;
            std::cout << RESET;
            break;
         default:
            std::cout << BIRED;
            std::cout << "Opción incorrecta ";
            std::cout << RESET;
            std::cout << "--> ";
            std::cout << ONIRED;
            std::cout << opcion << std::endl;
            std::cout << RESET;
            break;
      }
      if(opcion!=3){
         std::cout << std::endl << std::endl;
         std::cout << "Pulse ";
         std::cout << BIGREEN;
         std::cout << "ENTER";
         std::cout << RESET;
         std::cout << " para mostrar el ";
         std::cout << INVERSE;
         std::cout << "menú";
         std::cout << RESET;
         std::cin.ignore();
         std::cout << CLEAR_SCREEN;
      }
   }while(opcion!=3);
}

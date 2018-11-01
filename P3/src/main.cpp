#include <iostream>
#include "Entero.hpp"
#include "macros.hpp"
int main(){
   int opcion=0;
   do{
      Entero a, b, resultado;
      int posicion=2;
      std::cout << CLEAR_SCREEN;
      PLACE(1, 10);
      std::cout << BIBLUE << "Menu" << RESET;

      posicion++;
      PLACE(posicion++, 10);
      std::cout << "1. Sumar";

      PLACE(posicion++, 10);
      std::cout << "2. Multiplicar";

      PLACE(posicion++, 10);
      std::cout << "3. Salir del programa";

      posicion++;

      PLACE(posicion++, 10);
      std::cout << BIGREEN << "Introduzca la opción deseada: " << RESET;
      std::cin >> opcion;
      std::cin.ignore();
      std::cout << CLEAR_SCREEN;

      PLACE(3, 1);
      switch(opcion){
         case 1:
            std::cout << BIPURPLE << "Introduzca el primer operando: " << RESET;
            std::cin >> a;
            std::cout << BIPURPLE << "Introduzca el segundo operando: " << RESET;
            std::cin >> b;

            resultado=a+b;
            std::cout << BIBLUE << "El resultado es: " << RESET << resultado << std::endl;
            std::cin.ignore();
            break;
         case 2:
            std::cout << BIPURPLE << "Introduzca el primer operando: " << RESET;
            std::cin >> a;
            std::cout << BIPURPLE << "Introduzca el segundo operando: " << RESET;
            std::cin >> b;

            resultado=a*b;
            std::cout << BIBLUE << "El resultado es: " << RESET << resultado << std::endl;
            std::cin.ignore();
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

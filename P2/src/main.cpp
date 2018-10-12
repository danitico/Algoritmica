#include <iostream>
#include "Tiempo.hpp"
#include "funcionesAuxiliares.hpp"
int main(){
   int opcion=0;
   std::vector<std::vector<unsigned long long int> > datos(301, std::vector<unsigned long long int>(11, 0));
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
            // std::cout << "Recursividad: " << combinatorioConRecursividad(50, 10) << '\n';
            // std::cout << "Sin Recursividad: " << combinatorioSinRecursividad(50, 10) << '\n';
            for(int i=0; i<301; i++){
               for(int j=0; j<11; j++){
                  if(i==j || j==0){
                     datos[i][j]=1;
                  }
               }
            }
            std::cout << "Recursividad con tabla: " << combinatorioConRecursividadyTabla(300, 10, datos) << '\n';

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

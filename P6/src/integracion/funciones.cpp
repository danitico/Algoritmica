#include "funciones.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
double integracionNumerica(long long int simulaciones, long long int a, long long int b){
   double suma=0.0;
   long long int x=0;
   for(int i=0; i<simulaciones; i++){
      x=rand()%(b - a + 1) + a;
      suma += exp(pow(x, 2)*(-0.5)) / sqrt(2*M_PI);
   }

   return ((b-a)*suma) / simulaciones;
}
void problemaIntegracion(){
   long long int simulaciones, a, b;

   std::cout << BIBLUE << "Introduzca cuantas simulaciones quiere realizar: " << RESET;
   std::cin >> simulaciones;

   std::cout << BIBLUE << "Introduzca el límite inferior: " << RESET;
   std::cin >> a;

   std::cout << BIBLUE << "Introduzca el límite superior: " << RESET;
   std::cin >> b;

   std::cout << "El valor de la integral es " << integracionNumerica(simulaciones, a, b) << std::endl;
   std::cin.ignore();
}

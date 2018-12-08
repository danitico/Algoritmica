#include "funciones.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
double integracionNumerica(int simulaciones, int a, int b){
   double suma=0.0;
   int x=0;
   for(int i=0; i<simulaciones; i++){
      x=rand()%(b - a + 1) + a;
      suma += function(x);
   }

   return ((b-a)*suma) / simulaciones;
}
void problemaIntegracion(){
   int simulaciones, a, b, intervalos;

   std::cout << BIBLUE << "Introduzca cuantas simulaciones quiere realizar: " << RESET;
   std::cin >> simulaciones;

   std::cout << BIBLUE << "Introduzca intervalos: " << RESET;
   std::cin >> intervalos;

   std::cout << BIBLUE << "Introduzca el límite inferior: " << RESET;
   std::cin >> a;

   std::cout << BIBLUE << "Introduzca el límite superior: " << RESET;
   std::cin >> b;

   std::cout << BIPURPLE << "El valor de la integral es " << RESET
             << UNDERLINE << BIRED
             << integracionNumerica(simulaciones, a, b) << RESET << std::endl;

   std::cout << BIPURPLE << "El valor de la integral con trapecios es "
             << RESET << UNDERLINE << BIRED
             << metodoTrapecios(a, b, intervalos) << RESET << std::endl;

   std::cin.ignore();
}
double metodoTrapecios(int a, int b, int intervalos){
   double h = double(b-a) / double(intervalos);
   double suma=0.0;

   suma = function(a) + function(b);
   for(int i=1; i<=intervalos; i++){
      suma += 2.0 * function(a + h*i);
   }

   return (suma * h) / 2;
}
double function(double x){
   return exp(pow(x, 2)*(-0.5)) / sqrt(2*M_PI);
}

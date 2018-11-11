#include "funciones.hpp"
#include "Solucion.hpp"
#include "../macros.hpp"
void problemaMochila(){
   Solucion solucion;
   Datos datos;

   std::cin >> datos;

   if(datos.getMateriales().size()==0){
      std::cout << BIRED << "La lista de Materiales está vacía" << RESET << std::endl;
   }
   else{
      solucion.setDatos(datos);
      solucion.Mochila();

      std::cout << solucion;
   }
   std::cin.ignore();
}

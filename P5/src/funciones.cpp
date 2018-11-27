#include "funciones.hpp"
#include "Solucion.hpp"
#include "macros.hpp"
void problemaMochila(){
   Solucion solucion;
   Datos datos;

   std::cin >> datos;

   if(datos.getMateriales().size()==0){
      std::cout << BIRED << "La lista de Materiales está vacía" << RESET << std::endl;
   }
   else{
      solucion.setDatos(datos);
      std::vector<std::vector<float> > tabla(datos.getMateriales().size() + 1, std::vector<float>(datos.getVolumenMochila() + 1, 0.0));
      solucion.tablaMochila(tabla);
      solucion.solucionMochila(tabla);
      std::cout << solucion;
   }
   std::cin.ignore();
}

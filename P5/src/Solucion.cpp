#include "Solucion.hpp"
#include "macros.hpp"
#include <algorithm>
void Solucion::Mochila(std::vector<std::vector<int> > & tabla){
   std::vector<Material> materiales = this->getDatos().getMateriales();
   int volumenMochila=this->getDatos().getVolumenMochila();

   for(int i=0; i<volumenMochila; i++){
      tabla[0][i]=0;
   }

   for(int i=0; i<materiales.size(); i++){
      tabla[i][0];
   }

   for(int i=0; i<materiales.size(); i++){
      for(int j=0; j<volumenMochila; j++){
         if(j < materiales[i].getVolumen()){
            tabla[i][j]=tabla[i-1][j];
         }
         else{
            tabla[i][j]=std::max(tabla[i-1][j], materiales[i].getTotal() + tabla[i-1][j-materiales[i].getVolumen()]);
         }
      }
   }
}
std::ostream & operator<<(std::ostream & stream, const Solucion & a){
   if(a.getUtilizados().size() > 0){
      int precioTotal=0;
      stream << BIBLUE << "\t\tUTILIZADOS" << RESET << std::endl;
      stream << BIBLUE << "\t\t----------" << RESET << std::endl;
      for(int i=0; i<a.getUtilizados().size(); i++){
         precioTotal+=a.getUtilizados()[i].getTotal();
         stream << a.getUtilizados()[i] << std::endl;
      }
      stream << std::endl << BIBLUE << "Precio total de la mochila: " << RESET
             << BIRED << UNDERLINE << precioTotal  << RESET << std::endl;
   }
   else{
      stream << BIRED << "No se ha utilizado ninguno" << RESET << std::endl;
   }

   return stream;
}

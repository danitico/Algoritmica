#include "Solucion.hpp"
#include "macros.hpp"
#include <algorithm>
void Solucion::Mochila(std::vector<std::vector<float> > & tabla){
   std::vector<Material> materiales = this->getDatos().getMateriales();
   int volumenMochila=this->getDatos().getVolumenMochila();

   for(int i=1; i<volumenMochila + 1; i++){
      tabla[0][i]=0;
   }

   for(int i=0; i<materiales.size() + 1; i++){
      tabla[i][0]=0;
   }

   for(int i=0; i<materiales.size(); i++){
      for(int j=1; j<=volumenMochila; j++){
         if(materiales[i].getVolumen() > j){
            tabla[i][j]=tabla[i-1][j];
         }
         else{
            if(j - materiales[i].getVolumen() < 0){
               tabla[i][j]=tabla[i-1][j];
            }
            else{
               tabla[i][j]=std::max(tabla[i-1][j], materiales[i-1].getTotal() + tabla[i-1][j-materiales[i-1].getVolumen()]);
            }
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

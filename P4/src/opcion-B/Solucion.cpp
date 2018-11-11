#include "Solucion.hpp"
#include "../macros.hpp"
void Solucion::Mochila(){
   if(this->getDatos().getMateriales().size()!=0){
      int resto = this->getDatos().getVolumenMochila();
      std::vector<Material> materiales = this->getDatos().getMateriales();

      for(int i=0; i<materiales.size(); i++){
         if(materiales[i].getDisponible()){
            if(resto > materiales[i].getVolumen()){
               materiales[i].setDisponible(false);
               resto -= materiales[i].getVolumen();

               utilizados_.push_back(materiales[i]);
            }
            else if(resto == materiales[i].getVolumen()){
               materiales[i].setDisponible(false);
               utilizados_.push_back(materiales[i]);

               break;
            }
            else{
               Material a = materiales[i];
               a.setVolumen(resto);
               a.setDisponible(false);
               utilizados_.push_back(a);

               break;
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

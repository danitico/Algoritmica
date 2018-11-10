#include "Solucion.hpp"
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
      stream << "UTILIZADOS" << std::endl;
      stream << "----------" << std::endl;
      for(int i=0; i<a.getUtilizados().size(); i++){
         stream << a.getUtilizados()[i] << std::endl;
      }
   }
   else{
      stream << "No se ha utilizado ninguno" << std::endl;
   }

   return stream;
}

#include "Vertex.hpp"
bool Vertex::operator==(Vertex const & vertice) const{
   if(this->getNombre() == vertice.getNombre()){
      return true;
   }
   else{
      return false;
   }
}
bool Vertex::operator!=(Vertex const & vertice) const{
   if(!(this->getNombre() == vertice.getNombre())){
      return true;
   }
   else{
      return false;
   }
}
Vertex & Vertex::operator=(Vertex const &vertice){
   this->setNombre(vertice.getNombre());
   this->setLabel(vertice.getLabel());
   return *this;
}

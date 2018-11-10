#include "Material.hpp"
int Material::getTotal() const{
   return this->getVolumen() * this->getPrecio();
}
std::ostream & operator<<(std::ostream & stream, const Material & a){
   stream << "Etiqueta: " << a.getEtiqueta() \
             << " Volumen: " << a.getVolumen()  \
             << " Precio: "  << a.getPrecio()   \
             << " Total: "   << a.getTotal();
   return stream;
}
void Material::operator=(const Material & a){
   this->setEtiqueta(a.getEtiqueta());
   this->setVolumen(a.getVolumen());
   this->setPrecio(a.getPrecio());
   this->setDisponible(a.getDisponible());
}
bool Material::operator==(const Material & b) const{
   if(getEtiqueta() == b.getEtiqueta() && getVolumen() == b.getVolumen() &&
      getPrecio() == b.getPrecio() && getDisponible() == b.getDisponible()){
         return true;
   }
   else{
      return false;
   }
}

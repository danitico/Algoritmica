#include "Material.hpp"
#include "macros.hpp"
float Material::getTotal() const{
   return this->getVolumen() * this->getPrecio();
}
std::ostream & operator<<(std::ostream & stream, const Material & a){
   stream << BIBLUE << "Etiqueta: " << RESET << BIRED << UNDERLINE << a.getEtiqueta() << RESET \
          << BIBLUE << " Volumen: " << RESET << BIRED << UNDERLINE << a.getVolumen()  << RESET \
          << BIBLUE << " Precio: "  << RESET << BIRED << UNDERLINE << a.getPrecio()   << RESET \
          << BIBLUE << " Total: "   << RESET << BIRED << UNDERLINE << a.getTotal()    << RESET;
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

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

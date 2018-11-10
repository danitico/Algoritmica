#include "Material.hpp"
int Material::getTotal(){
   return this->getVolumen() * this->getPrecio();
}

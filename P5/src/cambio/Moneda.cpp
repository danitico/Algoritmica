#include "Moneda.hpp"
#include "../macros.hpp"
std::ostream & operator<<(std::ostream & stream, const Moneda & moneda){
   stream << BIRED << UNDERLINE << moneda.getValor() << RESET;
   return stream;
}

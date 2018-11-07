#include "funciones.hpp"
#include "macros.hpp"
void Suma(){
   Entero a, b, resultado;

   std::cout << BIPURPLE << "Introduzca el primer operando: " << RESET;
   std::cin >> a;
   std::cout << BIPURPLE << "Introduzca el segundo operando: " << RESET;
   std::cin >> b;

   resultado=a+b;
   std::cout << BIBLUE << "El resultado es: " << RESET << resultado << std::endl;
   std::cin.ignore();
}
void Multiplicacion(){
   Entero a, b, resultado;

   std::cout << BIPURPLE << "Introduzca el primer operando: " << RESET;
   std::cin >> a;
   std::cout << BIPURPLE << "Introduzca el segundo operando: " << RESET;
   std::cin >> b;

   resultado=a*b;
   std::cout << BIBLUE << "El resultado es: " << RESET << resultado << std::endl;
   std::cin.ignore();
}
Entero MultiplicacionNumerosGrandes(Entero u, Entero v, int n){
   int len_u=u.getNumero().length(), len_v=v.getNumero().length(), grande=0;

   (len_u > len_v) ? grande=len_u : grande=len_v;
   if(grande <= n){
      int res=stoi(u.getNumero()) * stoi(v.getNumero());
      return Entero(std::to_string(res));
   }
   else{
      Entero w, x, y, z;
      int s=grande/2;
      u.agregarCerosDelante(grande-len_u);
      v.agregarCerosDelante(grande-len_v);

      u.partirCadena(w, x);
      w.quitarCerosNoSignificativos();
      x.quitarCerosNoSignificativos();

      v.partirCadena(y, z);
      y.quitarCerosNoSignificativos();
      z.quitarCerosNoSignificativos();

      return MultiplicacionNumerosGrandes(w, y, n).multiplicarPotencia10(2*s) +
            (MultiplicacionNumerosGrandes(w, z, n) + MultiplicacionNumerosGrandes(x, y, n)).multiplicarPotencia10(s) +
            MultiplicacionNumerosGrandes(x, z, n);
   }
}

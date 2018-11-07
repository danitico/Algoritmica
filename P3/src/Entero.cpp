#include "Entero.hpp"
#include "macros.hpp"
#include "funciones.hpp"
void Entero::partirCadena(Entero & a, Entero & b){
	int n, n1, n2;
	std::string c1, c2;
	n=this->getNumero().length();

	if(n%2==0){//n es par
		n1=n/2;
		n2=n1;
	}
	else{
		n1=(n+1)/2;
		n2=n1-1;
	}

   c1=this->getNumero().substr(0, n1);
   c2=this->getNumero().substr(n1);

	a.setNumero(c1);
	b.setNumero(c2);
}
void Entero::agregarCerosFinal(int nCeros){
	int n, numeroCaracteres, i;
	std::string aux=this->getNumero();

	n=aux.length();
	numeroCaracteres=n+nCeros;

	for(i=n; i<numeroCaracteres; i++){//Se rellena con los ceros al final
      aux.push_back('0');
   }
	this->setNumero(aux);
}
void Entero::agregarCerosDelante(int nCeros){
	int n, i;
   std::string aux;

   for(int i=0; i<nCeros; i++){
   	aux.push_back('0');
   }

	aux.append(this->getNumero());
   this->setNumero(aux);
}
void Entero::quitarCerosNoSignificativos(){
	int l, i=0, numeroCeros=0;
	l=this->getNumero().length();

	while(this->getNumero()[i]=='0' && i<l-1){
		i++;
		numeroCeros++;
	}

   this->setNumero(this->getNumero().substr(numeroCeros));
}

Entero Entero::multiplicarPotencia10(int potencia){
	Entero aux(this->getNumero());

	aux.agregarCerosFinal(potencia);
	return aux;
}
void Entero::operator=(const Entero & entero){
	this->setNumero(entero.getNumero());
}
std::ostream & operator<<(std::ostream & stream, const Entero & a){
	stream << a.getNumero();
	return stream;
}
std::istream & operator>>(std::istream & stream, Entero & a){
	stream >> a.numero_;
	return stream;
}
Entero Entero::operator+(const Entero & b){
	Entero aux, aux1;
   Entero resultado;
   int x, y, acarreo=0, res=0, len_first=this->getNumero().length(), len_b=b.getNumero().length();

   if(len_first > len_b){
      aux=b;
      aux.agregarCerosDelante(len_first - len_b);
      aux1=(*this);
   }
   else{
      aux=(*this);
      aux.agregarCerosDelante(len_b - len_first);
      aux1=b;
   }

   int len_aux=aux.getNumero().length();
   resultado.agregarCerosFinal(len_aux+1);

   for(int i=len_aux-1; i>=0; i--){
      x = aux.getNumero()[i] - '0';
      y = aux1.getNumero()[i] - '0';

      res = x + y + acarreo;
      resultado.setNumero(i+1, res%10);

      if(res>9){
         acarreo=res/10;
      }
      else{
         acarreo=0;
      }
   }

	if(acarreo>0){
      resultado.setNumero(0, acarreo);
   }

   resultado.quitarCerosNoSignificativos();
	return resultado;
}
// Entero Entero::operator*(const Entero & b){
// 	Entero aux, aux1;
//    Entero resultado, parcial;
//    int x, y, acarreo=0, res=0, len_first=this->getNumero().length(), len_b=b.getNumero().length();
//
//    if(len_first > len_b){
//       aux=b;
//       aux1=(*this);
//    }
//    else{
//       aux=(*this);
//       aux1=b;
//    }
//
// 	if(aux.getNumero()=="0"){
// 		resultado.agregarCerosFinal(1);
// 		return resultado;
// 	}
//
// 	int len_aux=aux.getNumero().length();
//    resultado.agregarCerosFinal(len_first+len_b);
// 	parcial.agregarCerosFinal(aux1.getNumero().length()+1);
//
// 	int j=0;
// 	int repeticiones=0;
// 	for(int i=len_aux-1; i>=0; i--){
// 		repeticiones=aux.getNumero()[i] - '0';
// 		parcial=aux1;
// 		for(int k=1; k<repeticiones; k++){
// 			parcial = parcial + aux1;
// 		}
// 		parcial.agregarCerosFinal(j);
// 		resultado = resultado + parcial;
// 		j++;
// 	}
//
// 	resultado.quitarCerosNoSignificativos();
// 	return resultado;
// }
Entero Entero::operator*(const Entero & b){
	int n=0;
	std::cout << BIPURPLE << "Número máximo de dígitos para multiplicación directa: " << RESET;
	std::cin >> n;

	//Debido al limite de los enteros. Multiplicar por si mismo el numero mas grande con 4 cifras
	//no supera el límite. Pero con 5 cifras sí, por lo que se limita a 4
	if(n>4)
		n=4;

	return MultiplicacionNumerosGrandes(*this, b, n);
}
bool Entero::operator==(const Entero & b) const{
	if(getNumero()==b.getNumero()){
		return true;
	}
	else{
		return false;
	}
}

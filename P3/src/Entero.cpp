#include "Entero.hpp"
void Entero::partirCadena(std::string & c1, std::string & c2){
	int n, n1, n2, i;
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

	while(this->getNumero()[i]=='0' && i<l){
		i++;
		numeroCeros++;
	}

   this->setNumero(this->getNumero().substr(numeroCeros));
}

std::string Entero::multiplicarPotencia10(int potencia){
	Entero aux(this->getNumero());

	aux.agregarCerosFinal(potencia);
	return aux.getNumero();
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

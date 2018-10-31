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

	n=this->getNumero().length();
	numeroCaracteres=n+nCeros;

	for(i=n; i<numeroCaracteres; i++){//Se rellena con los ceros al final
      this->getNumero().push_back('0');
   }
}
void Entero::agregarCerosDelante(int nCeros){
	int n, numeroCaracteres, i;
   std::string aux;
	n=this->getNumero().length();

	numeroCaracteres=n+nCeros;

   for(int i=0; i<numeroCaracteres; i++){
      if(i<nCeros){
         aux.push_back('0');
      }
      else{
         aux.push_back(this->getNumero()[i]);
      }
   }
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

void Entero::multiplicarPotencia10(int potencia){
	this->agregarCerosFinal(potencia);
}

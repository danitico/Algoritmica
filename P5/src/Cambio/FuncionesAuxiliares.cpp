#include "FuncionesAuxiliares.hpp"
#include "macros.hpp"
#include "SistemaMonetario.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
void Cambio(){
	SistemaMonetario sistema;
	int n;
   std::string nombre="../Euros.txt";
	std::ifstream fichero(nombre.c_str());

	if(!fichero.good()){
		std::cout<<BIRED<<"No se pudo cargar el fichero de entrada"<<RESET<<std::endl;
		exit(-1);
	}

	fichero >> sistema;
	fichero.close();

	std::vector< std::vector <int> > solucion;

	std::cout<<"Introduce el numero a cambiar"<<std::endl;
	std::cin>>n;
	if(n<1){
		std::cout<<"Error"<<std::endl;
	}
	else{
		solucion.resize(n+1, std::vector<int>(sistema.size(),0));
		for(int i=0;i<solucion.size();i++){
			for(int j=0; j< n+1; j++){

			}
		}
	}
}

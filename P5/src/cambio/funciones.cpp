#include "funciones.hpp"
#include "../macros.hpp"
#include "SistemaMonetario.hpp"
#include <iostream>
#include <string>
void problemaCambio(){
	SistemaMonetario sistema;
	int cantidad=0;

	std::cout << "Introduzca la cantidad de dinero para cambiar: ";
	std::cin >> cantidad;
	std::cout << sistema.getSistemaMonetario().size() + 1 << std::endl;
	std::cout << cantidad + 1 << std::endl;
	std::vector<std::vector<int> > tabla(sistema.getSistemaMonetario().size()+1, std::vector<int>(cantidad+1, 0));// me da el fallo ahí

	sistema.cambio(tabla, cantidad);
	sistema.solucion(tabla, cantidad);
	// for(int i=0; i<tabla.size(); i++){
	// 	for(int j=0; j<tabla[0].size(); j++){
	// 		std::cout << tabla[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	std::cin.ignore();
}

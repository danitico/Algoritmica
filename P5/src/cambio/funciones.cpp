#include "funciones.hpp"
#include "../macros.hpp"
#include "SistemaMonetario.hpp"
void problemaCambio(){
	SistemaMonetario sistema;
	float cantidadFlotante=0.0;

	std::cout << BIPURPLE << "Introduzca la cantidad de dinero para cambiar: " << RESET;
	std::cin >> cantidadFlotante;

	int cantidadEntero = cantidadFlotante * 100;
	std::vector<std::vector<int> > tabla(sistema.getSistemaMonetario().size()+1, std::vector<int>(cantidadEntero+1, 0));

	sistema.cambio(tabla, cantidadEntero);
	sistema.solucion(tabla, cantidadEntero);
	std::cin.ignore();
}

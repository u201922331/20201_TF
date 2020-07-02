#pragma once
#include "Tabla.h"

void IngresarDatos(Tabla*& tabla) {
	int num_columnas;
	int num_filas;
	std::string nombre_columna;
	int tag_columna;
	std::string dato;

	std::cout << "Ingrese numero de columnas: "; std::cin >> num_columnas;
	std::cout << "Ingrese numero de filas: "; std::cin >> num_filas;

	for (int i = 0; i < num_columnas; i++) {
		std::cout << "\n**********************************\n";
		std::cout << "   Nombre de la columna " << i << ": "; std::cin >> nombre_columna;
		std::cout << "   Tag de la columna (0: Alfanumerico, 1: Caracter, 2: Numerico, 3: Decimal): "; std::cin >> tag_columna;

		tabla->AgregarColumna(new Columna(nombre_columna, tag_columna));
	}
	for (int i = 0; i < num_filas; i++) {
		std::cout << "\n**********************************\n";
		for (int j = 0; j < num_columnas; j++) {
			std::cout << "    " << tabla->getColumna(j)->getNombreColumna() << "[" << i << "]: "; std::cin >> dato;
			tabla->getColumna(j)->Agregar(dato);
		}
	}
}
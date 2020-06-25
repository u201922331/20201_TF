#pragma once
#ifndef __DATA_H__
#define __DATA_H__

#include <string>
#include "Arbol.h"
#include <vector>
#include <iostream>

#define ALFANUMERICO 0
#define CARACTER     1
#define NUMERICO     2
#define DECIMAL      3

typedef Arbol<std::string> strTree;
typedef Arbol<char> chrTree;
typedef Arbol<int> intTree;
typedef Arbol<float> flTree;

// Metodos de impresion de datos del arbol -----------------------------------------------------
auto print_string = [](std::string x) {std::cout << x << " "; };
auto print_char = [](char x) {std::cout << x << " "; };
auto print_int = [](int x) {std::cout << x << " "; };
auto print_float = [](float x) {std::cout << x << " "; };

class Columna {
	std::string nombre_columna;
	int tipo_dato;

	// Al final solo se usará uno de estos árboles dependiendo que tipo de dato sea el elegido
	strTree* datos_string;
	chrTree* datos_char;
	intTree* datos_int;
	flTree* datos_float;

public:
	Columna() {}
	Columna(std::string nombre, int tag) : nombre_columna(nombre), tipo_dato(tag) {
		switch (tag) {
		case ALFANUMERICO:
			datos_string = new strTree;
			break;
		case CARACTER:
			datos_char = new chrTree;
			break;
		case NUMERICO:
			datos_int = new intTree;
			break;
		case DECIMAL:
			datos_float = new flTree;
			break;
		}
	}
	~Columna() { delete datos_string, datos_char, datos_int, datos_float; }

	std::string getNombreColumna() { return nombre_columna; }
	void setNombreColumna(std::string nombre) { nombre_columna = nombre; }

	strTree* getArbol_String() { return datos_string; }
	chrTree* getArbol_Char() { return datos_char; }
	intTree* getArbol_Int() { return datos_int; }
	flTree* getArbol_Float() { return datos_float; }

	void Agregar(std::string elem) {
		switch (tipo_dato) {
		case ALFANUMERICO:
			datos_string->Agregar(elem);
			break;
		case CARACTER:
			Agregar(elem[0]);
			break;
		case NUMERICO:
			Agregar(std::stoi(elem));
			break;
		case DECIMAL:
			Agregar(std::stof(elem));
			break;
		}
	}
	void Agregar(char elem) { datos_char->Agregar(elem); }
	void Agregar(int elem) { datos_int->Agregar(elem); }
	void Agregar(float elem) { datos_float->Agregar(elem); }

	void Eliminar(std::string elem) {}
	void Eliminar(char elem) {}
	void Eliminar(int elem) {}
	void Eliminar(float elem) {}
};

class Tabla {
	Columna** columnas;
	int num_columnas;
public:
	Tabla() : num_columnas(0), columnas(new Columna*[0]) {}
	~Tabla() { delete[] columnas; }

	void AgregarColumna(Columna* nuevaColumna) {
		Columna** temp = new Columna*[num_columnas + 1];

		for (int i = 0; i < num_columnas; i++)
			temp[i] = columnas[i];
		temp[num_columnas] = nuevaColumna;

		++num_columnas;

		columnas = temp;
	}

	Columna* getColumna(int i) { return columnas[i]; }
	int getNumColumnas() { return num_columnas; }
};

#endif
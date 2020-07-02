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

typedef std::vector<std::string> strVec;
typedef std::vector<char> chrVec;
typedef std::vector<int> intVec;
typedef std::vector<float> flVec;

// Metodos de impresion de datos del arbol -----------------------------------------------------
auto print_string = [](std::string x) {std::cout << x << " "; };
auto print_char = [](char x) {std::cout << x << " "; };
auto print_int = [](int x) {std::cout << x << " "; };
auto print_float = [](float x) {std::cout << x << " "; };

class Columna {
	std::string nombre_columna;
	int tipo_dato;
	
	int num_filas = 0;

	// Al final solo se usará uno de estos árboles dependiendo que tipo de dato sea el elegido
	strTree* datos_string;
	chrTree* datos_char;
	intTree* datos_int;
	flTree* datos_float;

	// Vectores
	strVec* vec_string;
	chrVec* vec_char;
	intVec* vec_int;
	flVec* vec_float;

public:
	Columna() {}
	Columna(std::string nombre, int tag) : nombre_columna(nombre), tipo_dato(tag) {
		switch (tag) {
		case ALFANUMERICO:
			datos_string = new strTree;
			vec_string = new strVec;
			break;
		case CARACTER:
			datos_char = new chrTree;
			vec_char = new chrVec;
			break;
		case NUMERICO:
			datos_int = new intTree;
			vec_int = new intVec;
			break;
		case DECIMAL:
			datos_float = new flTree;
			vec_float = new flVec;
			break;
		}
	}
	~Columna() {
		delete datos_string, datos_char, datos_int, datos_float;
		delete vec_string, vec_char, vec_int, vec_float;
	}

	std::string getNombreColumna() { return nombre_columna; }
	void setNombreColumna(std::string nombre) { nombre_columna = nombre; }

	int getTagColumna() { return tipo_dato; }

	int getNumFilas() { return num_filas; }

	strTree* getArbol_String() { return datos_string; }
	chrTree* getArbol_Char() { return datos_char; }
	intTree* getArbol_Int() { return datos_int; }
	flTree* getArbol_Float() { return datos_float; }

	strVec* getVec_String() { return vec_string; }
	chrVec* getVec_Char() { return vec_char; }
	intVec* getVec_Int() { return vec_int; }
	flVec* getVec_Float() { return vec_float; }

	void Agregar(std::string elem) {
		switch (tipo_dato) {
		case ALFANUMERICO:
			++num_filas;
			datos_string->Agregar(elem);
			vec_string->push_back(elem);
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
	void Agregar(char elem) {
		++num_filas;
		datos_char->Agregar(elem);
		vec_char->push_back(elem);
	}
	void Agregar(int elem) {
		++num_filas;
		datos_int->Agregar(elem);
		vec_int->push_back(elem);
	}
	void Agregar(float elem) {
		++num_filas;
		datos_float->Agregar(elem);
		vec_float->push_back(elem);
	}

	void Eliminar(std::string elem) {
		switch (tipo_dato) {
		case ALFANUMERICO:
			datos_string->Remover(elem);
			break;
		case CARACTER:
			Eliminar(elem[0]);
			break;
		case NUMERICO:
			Eliminar(std::stoi(elem));
			break;
		case DECIMAL:
			Eliminar(std::stof(elem));
			break;
		}
	}
	void Eliminar(char elem) { datos_char->Remover(elem); }
	void Eliminar(int elem) { datos_int->Remover(elem); }
	void Eliminar(float elem) { datos_float->Remover(elem); }
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

	Columna* getColumna(std::string nombreColumna) {
		for (int i = 0; i < num_columnas; i++) {
			if (columnas[i]->getNombreColumna() == nombreColumna)
				return columnas[i];
		}
		return new Columna;
	}
	Columna* getColumna(int n) { return columnas[n]; }
	
	int getNumColumnas() { return num_columnas; }
};

#include "Archivos.h"
#include "Insercion.h"
#endif
#pragma once
#include "Tabla.h"
#include <fstream>

void Cargar_Archivo(Tabla*& tabla, std::string filename) {
	std::fstream archivo;
	archivo.open(filename.c_str(), std::ios::in);

	if (!archivo.fail()) {
		// Controlar la creacion de la tabla
		bool crear_columna = false;
		int i_columna = 0;

		// Tamaño de la tabla
		int num_columnas;
		int num_filas;

		// Lineas de texto
		int linea = 0;
		std::string texto;

		// Datos requeridos antes de crear la columna
		std::string nombre_columna;
		int tag_columna;

		// Lectura de archivo y asignacion de variables
		while (!archivo.eof()) {
			getline(archivo, texto);

			switch (linea) {
			case 0: num_columnas = std::stoi(texto); break;
			case 1: num_filas = std::stoi(texto); break;
			default:
				switch ((linea - 2) % (num_filas + 2)) {
				case 0:
					nombre_columna = texto;
					break;
				case 1:
					tag_columna = std::stoi(texto);
					crear_columna = true;
					break;
				default:
					tabla->getColumna(i_columna)->Agregar(texto);
					if ((linea - 2) % (num_filas + 2) == num_filas + 1) ++i_columna;
					break;
				}

				if (crear_columna) {
					tabla->AgregarColumna(new Columna(nombre_columna, tag_columna));
					crear_columna = false;
				}
				break;
			}
			++linea;
		}

		archivo.close();
	}
	else {
		// Cargar tabla predeterminada
		tabla->AgregarColumna(new Columna("Nombre", ALFANUMERICO));
		tabla->AgregarColumna(new Columna("Equipo", ALFANUMERICO));
		tabla->AgregarColumna(new Columna("Sexo", CARACTER));
		tabla->AgregarColumna(new Columna("Edad", NUMERICO));
		tabla->AgregarColumna(new Columna("DNI", NUMERICO));
		tabla->AgregarColumna(new Columna("Numero", NUMERICO));

		// Probando con agregar 4 filas **************************************
		// Fila 1
		tabla->getColumna("Nombre")->Agregar("Juan");
		tabla->getColumna("Equipo")->Agregar("MONTERRICO");
		tabla->getColumna("Sexo")->Agregar('M');
		tabla->getColumna("Edad")->Agregar(18);
		tabla->getColumna("DNI")->Agregar(12345678);
		tabla->getColumna("Numero")->Agregar(1);
		// Fila 2
		tabla->getColumna("Nombre")->Agregar("Ana");
		tabla->getColumna("Equipo")->Agregar("SAN ISIDRO");
		tabla->getColumna("Sexo")->Agregar('F');
		tabla->getColumna("Edad")->Agregar(16);
		tabla->getColumna("DNI")->Agregar(11223344);
		tabla->getColumna("Numero")->Agregar(2);
		// Fila 3
		tabla->getColumna("Nombre")->Agregar("Luis");
		tabla->getColumna("Equipo")->Agregar("MONTERRICO");
		tabla->getColumna("Sexo")->Agregar('M');
		tabla->getColumna("Edad")->Agregar(17);
		tabla->getColumna("DNI")->Agregar(98877766);
		tabla->getColumna("Numero")->Agregar(3);
		// Fila 4
		tabla->getColumna("Nombre")->Agregar("Andres");
		tabla->getColumna("Equipo")->Agregar("SAN ISIDRO");
		tabla->getColumna("Sexo")->Agregar('M');
		tabla->getColumna("Edad")->Agregar(18);
		tabla->getColumna("DNI")->Agregar(20192020);
		tabla->getColumna("Numero")->Agregar(4);
	}
}

void Guardar_Archivo(Tabla*& tabla, std::string filename) {
	std::fstream archivo;
	archivo.open(filename.c_str(), std::ios::out);

	archivo << tabla->getNumColumnas() << std::endl;
	archivo << tabla->getColumna(0)->getNumFilas() << std::endl;
	for (int i = 0; i < tabla->getNumColumnas(); i++) {
		archivo << tabla->getColumna(i)->getNombreColumna() << std::endl;
		archivo << tabla->getColumna(i)->getTagColumna() << std::endl;
		for (int j = 0; j < tabla->getColumna(0)->getNumFilas(); j++) {
			switch (tabla->getColumna(i)->getTagColumna()) {
			case ALFANUMERICO:
				archivo << tabla->getColumna(i)->getVec_String()->at(j);
				break;
			case CARACTER:
				archivo << tabla->getColumna(i)->getVec_Char()->at(j);
				break;
			case NUMERICO:
				archivo << tabla->getColumna(i)->getVec_Int()->at(j);
				break;
			case DECIMAL:
				archivo << tabla->getColumna(i)->getVec_Float()->at(j);
				break;
			}
			if (i + 1 < tabla->getNumColumnas() || j + 1 < tabla->getColumna(0)->getNumFilas()) archivo << std::endl;
		}
	}
	
	archivo.close();
}
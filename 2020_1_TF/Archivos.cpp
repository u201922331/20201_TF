//#include "stdafx.h"
#include "Tabla.h"
#include <fstream>

void Cargar_Archivo(Tabla& tabla) {
	std::fstream archivo;
	archivo.open("datos.txt", std::ios::out);

	if (archivo.fail()) {
		// Cargar tabla predeterminada
		tabla.AgregarColumna(new Columna("Nombre", ALFANUMERICO));  // 0
		tabla.AgregarColumna(new Columna("Equipo", ALFANUMERICO));  // 1
		tabla.AgregarColumna(new Columna("Sexo", CARACTER));        // 2
		tabla.AgregarColumna(new Columna("Edad", NUMERICO));        // 3
		tabla.AgregarColumna(new Columna("DNI", NUMERICO));         // 4
		tabla.AgregarColumna(new Columna("Numero", NUMERICO));      // 5
																			
		// Probando con agregar 4 filas **************************************
		// Fila 1
		tabla.getColumna("Nombre")->Agregar("Juan");
		tabla.getColumna("Equipo")->Agregar("MONTERRICO");
		tabla.getColumna("Sexo")->Agregar('M');
		tabla.getColumna("Edad")->Agregar(18);
		tabla.getColumna("DNI")->Agregar(12345678);
		tabla.getColumna("Numero")->Agregar(1);
		// Fila 2
		tabla.getColumna("Nombre")->Agregar("Ana");
		tabla.getColumna("Equipo")->Agregar("SAN ISIDRO");
		tabla.getColumna("Sexo")->Agregar('F');
		tabla.getColumna("Edad")->Agregar(16);
		tabla.getColumna("DNI")->Agregar(11223344);
		tabla.getColumna("Numero")->Agregar(2);
		// Fila 3
		tabla.getColumna("Nombre")->Agregar("Luis");
		tabla.getColumna("Equipo")->Agregar("MONTERRICO");
		tabla.getColumna("Sexo")->Agregar('M');
		tabla.getColumna("Edad")->Agregar(17);
		tabla.getColumna("DNI")->Agregar(98877766);
		tabla.getColumna("Numero")->Agregar(3);
		// Fila 4
		tabla.getColumna("Nombre")->Agregar("Andres");
		tabla.getColumna("Equipo")->Agregar("SAN ISIDRO");
		tabla.getColumna("Sexo")->Agregar('M');
		tabla.getColumna("Edad")->Agregar(18);
		tabla.getColumna("DNI")->Agregar(20192020);
		tabla.getColumna("Numero")->Agregar(4);
	}
	else {
		archivo.close();
	}
}

void Guardar_Archivo(Tabla& tabla) {

}
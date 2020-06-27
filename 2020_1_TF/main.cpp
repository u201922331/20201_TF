#include "stdafx.h"
#include "Tabla.h"
//#include "App.h"

#define BUSCAR 10

using namespace std;
//using namespace System::Windows::Forms;

int main() {
	int j = 0;
	int max = j;

	// Inicialización de la tabla
	cout << "Inicializando datos...\n\n";
	Tabla* tabla = new Tabla;

	Cargar_Archivo(*tabla);


	cout << "Inorden de " << tabla->getColumna("Nombre")->getNombreColumna() << ": "; tabla->getColumna("Nombre")->getArbol_String()->Inorden(print_string); cout << endl;
	cout << "Inorden de " << tabla->getColumna("Equipo")->getNombreColumna() << ": "; tabla->getColumna("Equipo")->getArbol_String()->Inorden(print_string); cout << endl;
	cout << "Inorden de " << tabla->getColumna("Sexo")->getNombreColumna() << ": "; tabla->getColumna("Sexo")->getArbol_Char()->Inorden(print_char); cout << endl;
	cout << "Inorden de " << tabla->getColumna("Edad")->getNombreColumna() << ": "; tabla->getColumna("Edad")->getArbol_Int()->Inorden(print_int); cout << endl;
	cout << "Inorden de " << tabla->getColumna("DNI")->getNombreColumna() << ": "; tabla->getColumna("DNI")->getArbol_Int()->Inorden(print_int); cout << endl;
	cout << "Inorden de " << tabla->getColumna("Numero")->getNombreColumna() << ": "; tabla->getColumna("Numero")->getArbol_Int()->Inorden(print_int); cout << endl;
	//cout << "Coincidencias de '" << BUSCAR << "': " << tabla->getColumna(3)->getArbol_Int()->Coincidencias(BUSCAR) << endl;

	/*
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew My20201_TF::App());
	*/


	system("pause");
	delete tabla;
}

// PENDIENTE **************************************
//    - Sistema de cargado de archivos
//    - Form para representar los datos creados/cargados
//    - Una vez terminado el programa sobreescribir el archivo de guardado con los datos existentes

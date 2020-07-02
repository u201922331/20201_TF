#include "stdafx.h"
#include "Tabla.h"
#include "App.h"
#include <conio.h>

// Definir nombre del archivo del que se cargará la tabla
#define CARGAR  "datos_test_0.txt"

// Definir nombre del archivo donde se guardará la tabla
#define GUARDAR "datos_1.txt"

using namespace std;
using namespace System::Windows::Forms;
using namespace System;

void Inicializar(Tabla*& tabla) {
	int opcion;

	_sleep(100);
	do {
		Console::Clear();
		cout << "Cargar archivo o introducir manualmente? (0: Cargar, 1: Ingresar): "; cin >> opcion;
	} while (opcion < 0 || 1 < opcion);

	Console::Clear();
	switch (opcion) {
	case 0:
		cout << "Cargando...\n";
		Cargar_Archivo(tabla, CARGAR);
		break;
	case 1:
		IngresarDatos(tabla);
		break;
	}
}

void Guardar(Tabla*& tabla) {
	char opc;

	cout << "\n******************************\n";
	cout << "Desea guardar la tabla? (1: Si, ???: No) ";

	if (_getch() == '1') {
		Console::Clear();
		cout << "Guardando...";
		Guardar_Archivo(tabla, GUARDAR);
	}
}

int main() {
	int opcion;

	// Inicialización de la tabla
	cout << "Inicializando datos...\n\n";
	Tabla* tabla = new Tabla;
	Inicializar(tabla);
	
	// Abrir Form
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew My2020_1_TF::App(tabla));

	//system("pause");

	Guardar(tabla);
	//Guardar_Archivo(tabla, GUARDAR);

	delete tabla;
}

// PENDIENTE **************************************
//    - Mejorar form para representar los datos cargados
//    - Arreglar el sistema de búsqueda de datos en la tabla
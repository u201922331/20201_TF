#include "stdafx.h"
#include "Tabla.h"
//#include "App.h"

#define BUSCAR 10
#define NOMBRE_ARCHIVO "datos_test_0.txt"

using namespace std;
//using namespace System::Windows::Forms;

int main() {
	int j = 0;
	int max = j;

	// Inicialización de la tabla
	cout << "Inicializando datos...\n\n";
	Tabla* tabla = new Tabla;

	Cargar_Archivo(tabla, NOMBRE_ARCHIVO);

	/*
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew My20201_TF::App());
	*/


	system("pause");

	Guardar_Archivo(tabla, NOMBRE_ARCHIVO);

	delete tabla;
}

// PENDIENTE **************************************
//    - Sistema de cargado de archivos
//    - Form para representar los datos creados/cargados
//    - Una vez terminado el programa sobreescribir el archivo de guardado con los datos existentes

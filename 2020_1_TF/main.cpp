#include "stdafx.h"
#include "Tabla.h"
#include "App.h"

#define BUSCAR 10
#define NOMBRE_ARCHIVO "datos_test_0.txt"

using namespace std;
using namespace System::Windows::Forms;

int main() {
	int j = 0;
	int max = j;

	// Inicialización de la tabla
	cout << "Inicializando datos...\n\n";
	Tabla* tabla = new Tabla;

	Cargar_Archivo(tabla, NOMBRE_ARCHIVO);
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew My2020_1_TF::App(tabla));

	//system("pause");

	Guardar_Archivo(tabla, NOMBRE_ARCHIVO);

	delete tabla;
}

// PENDIENTE **************************************
//    - Form para representar los datos cargados

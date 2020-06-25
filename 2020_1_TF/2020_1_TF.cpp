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
	// Importante: Usar macros definidos en el archivo "Tabla.h"
	tabla->AgregarColumna(new Columna("Nombre", ALFANUMERICO));  // 0
	tabla->AgregarColumna(new Columna("Equipo", ALFANUMERICO));  // 1
	tabla->AgregarColumna(new Columna("Sexo", CARACTER));      // 2
	tabla->AgregarColumna(new Columna("Edad", NUMERICO));      // 3
	tabla->AgregarColumna(new Columna("DNI", NUMERICO));       // 4
	tabla->AgregarColumna(new Columna("Numero", NUMERICO));    // 5

	cout << "---------------------------------------------\n";
	while (true) {
		bool detener = false;

		for (int i = 0; i < tabla->getNumColumnas(); i++) {
			string dato;
			cout << tabla->getColumna(i)->getNombreColumna() << "[" << j << "]: "; cin >> dato;

			if (dato == "-") {
				detener = true;

				if (i != tabla->getNumColumnas() - 1) {
					for (int k = 0; k < i; k++) {
						// Metodo para eliminar elementos de fila incompleta
					}
				}

				break;
			}

			tabla->getColumna(i)->Agregar(dato);
		}
		cout << "---------------------------------------------\n";
		if (detener) break;
		++j;
		++max;
	}

	cout << "Inorden de " << tabla->getColumna(0)->getNombreColumna() << ": "; tabla->getColumna(0)->getArbol_String()->Inorden(print_string); cout << endl;
	cout << "Inorden de " << tabla->getColumna(1)->getNombreColumna() << ": "; tabla->getColumna(1)->getArbol_String()->Inorden(print_string); cout << endl;
	cout << "Inorden de " << tabla->getColumna(2)->getNombreColumna() << ": "; tabla->getColumna(2)->getArbol_Char()->Inorden(print_char); cout << endl;
	cout << "Inorden de " << tabla->getColumna(3)->getNombreColumna() << ": "; tabla->getColumna(3)->getArbol_Int()->Inorden(print_int); cout << endl;
	cout << "Inorden de " << tabla->getColumna(4)->getNombreColumna() << ": "; tabla->getColumna(4)->getArbol_Int()->Inorden(print_int); cout << endl;
	cout << "Inorden de " << tabla->getColumna(5)->getNombreColumna() << ": "; tabla->getColumna(5)->getArbol_Int()->Inorden(print_int); cout << endl;
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

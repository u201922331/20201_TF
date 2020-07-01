#pragma once
#include "Tabla.h"
//#include <msclr\marshal_cppstd.h>

void MarshalString(System::String^ msrstr, std::string& stdstr) {
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(msrstr)).ToPointer();

	stdstr = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

namespace My2020_1_TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class App : public System::Windows::Forms::Form
	{
	public:
		App(Tabla* t) {
			InitializeComponent();
			table = t;
			int num_filas = t->getColumna(0)->getNumFilas();
			int num_columnas = t->getNumColumnas();

			float porcentaje_primera_fila = 10;

			this->tabla->RowCount = 0;
			this->tabla->RowStyles->Clear();
			this->tabla->ColumnCount = 0;
			this->tabla->ColumnStyles->Clear();

			this->tabla->RowCount = num_filas + 1;
			for (int i = 0; i < num_filas + 1; i++)
				if (i == 0)
					this->tabla->RowStyles->Add(gcnew RowStyle(SizeType::Percent, porcentaje_primera_fila));
				else
					this->tabla->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100 / num_filas + porcentaje_primera_fila));
			this->tabla->ColumnCount = num_columnas;
			for (int i = 0; i < num_columnas; i++)
					this->tabla->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100 / num_columnas + 10));
		}

	protected:
		~App() {
			if (components) delete components;
			
			delete tabla;
		}
	private: System::Windows::Forms::TableLayoutPanel^  tabla;
	private: System::Windows::Forms::Label^  lblTabla;
	private: System::Windows::Forms::TextBox^  txtbxBuscar;
	private: System::Windows::Forms::Label^  labelBuscar;
	private: System::Windows::Forms::ListBox^  listResultados;
	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  btnBuscar;


		Tabla* table;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(App::typeid));
			this->tabla = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lblTabla = (gcnew System::Windows::Forms::Label());
			this->txtbxBuscar = (gcnew System::Windows::Forms::TextBox());
			this->labelBuscar = (gcnew System::Windows::Forms::Label());
			this->listResultados = (gcnew System::Windows::Forms::ListBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tabla
			// 
			this->tabla->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::InsetDouble;
			this->tabla->ColumnCount = 1;
			this->tabla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 38.18182F)));
			this->tabla->Location = System::Drawing::Point(12, 55);
			this->tabla->Name = L"tabla";
			this->tabla->RowCount = 1;
			this->tabla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 66.66666F)));
			this->tabla->Size = System::Drawing::Size(502, 394);
			this->tabla->TabIndex = 0;
			// 
			// lblTabla
			// 
			this->lblTabla->AutoSize = true;
			this->lblTabla->BackColor = System::Drawing::Color::Transparent;
			this->lblTabla->Font = (gcnew System::Drawing::Font(L"Lucida Console", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTabla->ForeColor = System::Drawing::Color::Red;
			this->lblTabla->Location = System::Drawing::Point(12, 19);
			this->lblTabla->Name = L"lblTabla";
			this->lblTabla->Size = System::Drawing::Size(80, 21);
			this->lblTabla->TabIndex = 1;
			this->lblTabla->Text = L"Datos";
			// 
			// txtbxBuscar
			// 
			this->txtbxBuscar->Location = System::Drawing::Point(672, 98);
			this->txtbxBuscar->Name = L"txtbxBuscar";
			this->txtbxBuscar->Size = System::Drawing::Size(100, 20);
			this->txtbxBuscar->TabIndex = 2;
			// 
			// labelBuscar
			// 
			this->labelBuscar->AutoSize = true;
			this->labelBuscar->BackColor = System::Drawing::Color::Transparent;
			this->labelBuscar->Font = (gcnew System::Drawing::Font(L"Lucida Console", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelBuscar->ForeColor = System::Drawing::Color::Red;
			this->labelBuscar->Location = System::Drawing::Point(596, 102);
			this->labelBuscar->Name = L"labelBuscar";
			this->labelBuscar->Size = System::Drawing::Size(70, 13);
			this->labelBuscar->TabIndex = 3;
			this->labelBuscar->Text = L"Buscar:";
			// 
			// listResultados
			// 
			this->listResultados->FormattingEnabled = true;
			this->listResultados->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1", L"2", L"3" });
			this->listResultados->Location = System::Drawing::Point(599, 192);
			this->listResultados->Name = L"listResultados";
			this->listResultados->Size = System::Drawing::Size(173, 95);
			this->listResultados->TabIndex = 4;
			// 
			// btnBuscar
			// 
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::Black;
			this->btnBuscar->Location = System::Drawing::Point(733, 124);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(39, 23);
			this->btnBuscar->TabIndex = 5;
			this->btnBuscar->Text = L"->";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &App::btnBuscar_Click);
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(784, 461);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->listResultados);
			this->Controls->Add(this->labelBuscar);
			this->Controls->Add(this->txtbxBuscar);
			this->Controls->Add(this->lblTabla);
			this->Controls->Add(this->tabla);
			this->Name = L"App";
			this->Text = L"App";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
	this->listResultados->Items->Clear();

	std::string buscar;
	MarshalString(this->txtbxBuscar->Text, buscar);

	this->listResultados->Items->Add(this->txtbxBuscar->Text);
	/*
	for (int i = 0; i < table->getNumColumnas(); i++) {
	switch (table->getColumna(i)->getTagColumna()) {
	case ALFANUMERICO:
	if (table->getColumna(i)->getArbol_String()->Busqueda(buscar)) {
	this->listResultados->Items->Add("Encontrado alfanumerico");
	}
	break;
	case CARACTER:
	if (table->getColumna(i)->getArbol_Char()->Busqueda(buscar[0])) {
	this->listResultados->Items->Add("Encontrado caracter");
	}
	break;
	case NUMERICO:
	if (table->getColumna(i)->getArbol_Int()->Busqueda(std::stoi(buscar))) {
	this->listResultados->Items->Add("Encontrado numerico");
	}
	break;
	case DECIMAL:
	if (table->getColumna(i)->getArbol_Float()->Busqueda(std::stof(buscar))) {
	this->listResultados->Items->Add("Encontrado decimal");
	}
	break;
	}
	}
	*/
}
};
}

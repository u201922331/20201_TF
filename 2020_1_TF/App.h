#pragma once

namespace My2020_1_TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for App
	/// </summary>
	public ref class App : public System::Windows::Forms::Form
	{
	public:
		App(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~App()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblCuadro;
	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableDatos;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(App::typeid));
			this->lblCuadro = (gcnew System::Windows::Forms::Label());
			this->tableDatos = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->SuspendLayout();
			// 
			// lblCuadro
			// 
			this->lblCuadro->AutoSize = true;
			this->lblCuadro->BackColor = System::Drawing::Color::Transparent;
			this->lblCuadro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCuadro->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lblCuadro->Location = System::Drawing::Point(56, 64);
			this->lblCuadro->Name = L"lblCuadro";
			this->lblCuadro->Size = System::Drawing::Size(55, 17);
			this->lblCuadro->TabIndex = 0;
			this->lblCuadro->Text = L"Datos:";
			// 
			// tableDatos
			// 
			this->tableDatos->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableDatos->ColumnCount = 2;
			this->tableDatos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableDatos->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableDatos->Location = System::Drawing::Point(59, 96);
			this->tableDatos->Name = L"tableDatos";
			this->tableDatos->RowCount = 2;
			this->tableDatos->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableDatos->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableDatos->Size = System::Drawing::Size(360, 287);
			this->tableDatos->TabIndex = 1;
			// 
			// App
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(484, 461);
			this->Controls->Add(this->tableDatos);
			this->Controls->Add(this->lblCuadro);
			this->MaximizeBox = false;
			this->Name = L"App";
			this->ShowIcon = false;
			this->Text = L"App";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

#pragma once
#include <cliext/vector>
#include <cliext/list>
#include <cliext/algorithm>
#include "Estructuras.h"
#include "Arbol.h"

namespace ProgramaTFGv1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Estructuras;

	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void): operando1(nullptr), operando2 (nullptr)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private:
		/// <summary>
		System::Drawing::Bitmap^ Imagen;
		cli::array<unsigned char, 2>^ MatrizImagen;
		cli::array<unsigned char, 2>^ ImagenCo;
		cli::array<unsigned char, 2>^ Feature;	
		ProgramaTFGv1::VentanaImagen^ Ventana;
		cliext::vector<Estructuras::Clasificador^>^ etiqclasif;
		cliext::vector<int>^ etiquetas;
		cliext::list<Blob^>^ blobs;
		int raiz;

	public: int cantelemconec, cantelemsig, cantcont, cantexc, cantarea;
	private: cliext::vector<Estructuras::Probable^>^ probables;

	public: cli::array<unsigned char, 2>^ operando1;
	public: cli::array<unsigned char, 2>^ operando2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nuevoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarcomoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  imprimirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  vistapreviadeimpresiónToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deshacerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rehacerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  cortarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copiarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pegarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  seleccionartodoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  herramientasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  personalizarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  opcionesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  contenidoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  índiceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  buscarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  acercadeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ventanaToolStripMenuItem;
    private: System::Windows::Forms::ToolStrip^  toolStrip1;
    private: System::Windows::Forms::ToolStripButton^  nuevoToolStripButton;
    private: System::Windows::Forms::ToolStripButton^  abrirToolStripButton;
    private: System::Windows::Forms::ToolStripButton^  guardarToolStripButton;
    private: System::Windows::Forms::ToolStripButton^  imprimirToolStripButton;
    private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
    private: System::Windows::Forms::ToolStripButton^  cortarToolStripButton;
    private: System::Windows::Forms::ToolStripButton^  copiarToolStripButton;
    private: System::Windows::Forms::ToolStripButton^  pegarToolStripButton;
    private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
    private: System::Windows::Forms::ToolStripButton^  ayudaToolStripButton;
    private: System::Windows::Forms::ToolStrip^  toolStrip2;
    private: System::Windows::Forms::ToolStripButton^  BotonAGrises;
    private: System::Windows::Forms::ToolStripButton^  Sobel;
	private: System::Windows::Forms::ToolStripSplitButton^  Mascaras;
	private: System::Windows::Forms::ToolStripMenuItem^  laplacianoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  laplacianoDiagonalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  convolucionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elegirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elegirImagenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aplicarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^  correlacionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elegirFeatureToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  elegirImagenToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aplicarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripButton^  Op1;
	private: System::Windows::Forms::ToolStripButton^  Op2;
    private: System::Windows::Forms::ToolStripButton^  BotonDilation;
    private: System::Windows::Forms::ToolStripButton^  BotonErosion;
    private: System::Windows::Forms::ToolStripButton^  Resta;
    private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
    private: System::Windows::Forms::ToolStripButton^  Regiones;
    private: System::Windows::Forms::ToolStripMenuItem^  mexicanHatToolStripMenuItem;
    private: System::Windows::Forms::ToolStripDropDownButton^  Thresholding;
    private: System::Windows::Forms::ToolStripMenuItem^  thresholdToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  threshold2ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripButton^  Ecualizar;
    private: System::Windows::Forms::ToolStripButton^  RegSignificativas;
    private: System::Windows::Forms::ToolStripButton^  Contenedores;
    private: System::Windows::Forms::ToolStripButton^  Excentricidad;
    private: System::Windows::Forms::ToolStripButton^  Letras;
    private: System::Windows::Forms::ToolStripButton^  Areas;
    private: System::Windows::Forms::ToolStripButton^  RegionesFast;
    private: System::Windows::Forms::ToolStripButton^  AND;
    private: System::Windows::Forms::ToolStripDropDownButton^  Enhancements;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHatImagenThreshold2ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHatImagenThresholdToolStripMenuItem;
    private: System::Windows::Forms::ToolStripButton^  RegAB;
    private: System::Windows::Forms::ToolStripMenuItem^  adaptativoToolStripMenuItem;
    private: System::Windows::Forms::ToolStripButton^  Linking;
    private: System::Windows::Forms::ToolStripButton^  Linking2;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHatImagenchikiToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  thresToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHatImagenSauvolaToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHatImagenKittlerToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  mexHToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  mexicanColorToolStripMenuItem;

        /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuevoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->guardarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarcomoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->imprimirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vistapreviadeimpresiónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deshacerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rehacerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cortarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copiarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pegarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->seleccionartodoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->herramientasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->personalizarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opcionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ventanaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contenidoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->índiceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buscarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->acercadeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->nuevoToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->abrirToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->guardarToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->imprimirToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cortarToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->copiarToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->pegarToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ayudaToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->Op1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->Op2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->BotonDilation = (gcnew System::Windows::Forms::ToolStripButton());
			this->BotonErosion = (gcnew System::Windows::Forms::ToolStripButton());
			this->Resta = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->AND = (gcnew System::Windows::Forms::ToolStripButton());
			this->RegionesFast = (gcnew System::Windows::Forms::ToolStripButton());
			this->Enhancements = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->mexHatImagenThresholdToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexHatImagenThreshold2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexHatImagenchikiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexHatImagenSauvolaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexHatImagenKittlerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexHToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RegAB = (gcnew System::Windows::Forms::ToolStripButton());
			this->Linking = (gcnew System::Windows::Forms::ToolStripButton());
			this->Linking2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->BotonAGrises = (gcnew System::Windows::Forms::ToolStripButton());
			this->Sobel = (gcnew System::Windows::Forms::ToolStripButton());
			this->Mascaras = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->laplacianoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->laplacianoDiagonalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->convolucionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elegirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elegirImagenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aplicarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->correlacionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elegirFeatureToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->elegirImagenToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aplicarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mexicanHatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ecualizar = (gcnew System::Windows::Forms::ToolStripButton());
			this->Thresholding = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->thresholdToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->threshold2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adaptativoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Regiones = (gcnew System::Windows::Forms::ToolStripButton());
			this->RegSignificativas = (gcnew System::Windows::Forms::ToolStripButton());
			this->Contenedores = (gcnew System::Windows::Forms::ToolStripButton());
			this->Excentricidad = (gcnew System::Windows::Forms::ToolStripButton());
			this->Areas = (gcnew System::Windows::Forms::ToolStripButton());
			this->Letras = (gcnew System::Windows::Forms::ToolStripButton());
			this->mexicanColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->toolStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 544);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(792, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(109, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->archivoToolStripMenuItem, 
				this->editarToolStripMenuItem, this->herramientasToolStripMenuItem, this->ventanaToolStripMenuItem, this->ayudaToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MdiWindowListItem = this->ventanaToolStripMenuItem;
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->nuevoToolStripMenuItem, 
				this->abrirToolStripMenuItem, this->toolStripSeparator, this->guardarToolStripMenuItem, this->guardarcomoToolStripMenuItem, this->toolStripSeparator1, 
				this->imprimirToolStripMenuItem, this->vistapreviadeimpresiónToolStripMenuItem, this->toolStripSeparator2, this->salirToolStripMenuItem});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(55, 20);
			this->archivoToolStripMenuItem->Text = L"&Archivo";
			// 
			// nuevoToolStripMenuItem
			// 
			this->nuevoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"nuevoToolStripMenuItem.Image")));
			this->nuevoToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->nuevoToolStripMenuItem->Name = L"nuevoToolStripMenuItem";
			this->nuevoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->nuevoToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->nuevoToolStripMenuItem->Text = L"&Nuevo";
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"abrirToolStripMenuItem.Image")));
			this->abrirToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->abrirToolStripMenuItem->Text = L"&Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::abrirToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(201, 6);
			// 
			// guardarToolStripMenuItem
			// 
			this->guardarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guardarToolStripMenuItem.Image")));
			this->guardarToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->guardarToolStripMenuItem->Name = L"guardarToolStripMenuItem";
			this->guardarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->guardarToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->guardarToolStripMenuItem->Text = L"&Guardar";
			this->guardarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::guardarToolStripMenuItem_Click);
			// 
			// guardarcomoToolStripMenuItem
			// 
			this->guardarcomoToolStripMenuItem->Name = L"guardarcomoToolStripMenuItem";
			this->guardarcomoToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->guardarcomoToolStripMenuItem->Text = L"G&uardar como";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(201, 6);
			// 
			// imprimirToolStripMenuItem
			// 
			this->imprimirToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imprimirToolStripMenuItem.Image")));
			this->imprimirToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->imprimirToolStripMenuItem->Name = L"imprimirToolStripMenuItem";
			this->imprimirToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->imprimirToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->imprimirToolStripMenuItem->Text = L"&Imprimir";
			// 
			// vistapreviadeimpresiónToolStripMenuItem
			// 
			this->vistapreviadeimpresiónToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"vistapreviadeimpresiónToolStripMenuItem.Image")));
			this->vistapreviadeimpresiónToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->vistapreviadeimpresiónToolStripMenuItem->Name = L"vistapreviadeimpresiónToolStripMenuItem";
			this->vistapreviadeimpresiónToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->vistapreviadeimpresiónToolStripMenuItem->Text = L"&Vista previa de impresión";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(201, 6);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(204, 22);
			this->salirToolStripMenuItem->Text = L"&Salir";
			// 
			// editarToolStripMenuItem
			// 
			this->editarToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->deshacerToolStripMenuItem, 
				this->rehacerToolStripMenuItem, this->toolStripSeparator3, this->cortarToolStripMenuItem, this->copiarToolStripMenuItem, this->pegarToolStripMenuItem, 
				this->toolStripSeparator4, this->seleccionartodoToolStripMenuItem});
			this->editarToolStripMenuItem->Name = L"editarToolStripMenuItem";
			this->editarToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->editarToolStripMenuItem->Text = L"&Editar";
			// 
			// deshacerToolStripMenuItem
			// 
			this->deshacerToolStripMenuItem->Name = L"deshacerToolStripMenuItem";
			this->deshacerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->deshacerToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->deshacerToolStripMenuItem->Text = L"&Deshacer";
			// 
			// rehacerToolStripMenuItem
			// 
			this->rehacerToolStripMenuItem->Name = L"rehacerToolStripMenuItem";
			this->rehacerToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
			this->rehacerToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->rehacerToolStripMenuItem->Text = L"&Rehacer";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(165, 6);
			// 
			// cortarToolStripMenuItem
			// 
			this->cortarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cortarToolStripMenuItem.Image")));
			this->cortarToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cortarToolStripMenuItem->Name = L"cortarToolStripMenuItem";
			this->cortarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->cortarToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->cortarToolStripMenuItem->Text = L"Cor&tar";
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copiarToolStripMenuItem.Image")));
			this->copiarToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->copiarToolStripMenuItem->Text = L"&Copiar";
			// 
			// pegarToolStripMenuItem
			// 
			this->pegarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pegarToolStripMenuItem.Image")));
			this->pegarToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pegarToolStripMenuItem->Name = L"pegarToolStripMenuItem";
			this->pegarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pegarToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->pegarToolStripMenuItem->Text = L"&Pegar";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(165, 6);
			// 
			// seleccionartodoToolStripMenuItem
			// 
			this->seleccionartodoToolStripMenuItem->Name = L"seleccionartodoToolStripMenuItem";
			this->seleccionartodoToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->seleccionartodoToolStripMenuItem->Text = L"&Seleccionar todo";
			// 
			// herramientasToolStripMenuItem
			// 
			this->herramientasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->personalizarToolStripMenuItem, 
				this->opcionesToolStripMenuItem});
			this->herramientasToolStripMenuItem->Name = L"herramientasToolStripMenuItem";
			this->herramientasToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->herramientasToolStripMenuItem->Text = L"&Herramientas";
			// 
			// personalizarToolStripMenuItem
			// 
			this->personalizarToolStripMenuItem->Name = L"personalizarToolStripMenuItem";
			this->personalizarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->personalizarToolStripMenuItem->Text = L"&Personalizar";
			// 
			// opcionesToolStripMenuItem
			// 
			this->opcionesToolStripMenuItem->Name = L"opcionesToolStripMenuItem";
			this->opcionesToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->opcionesToolStripMenuItem->Text = L"&Opciones";
			// 
			// ventanaToolStripMenuItem
			// 
			this->ventanaToolStripMenuItem->Name = L"ventanaToolStripMenuItem";
			this->ventanaToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->ventanaToolStripMenuItem->Text = L"&Ventana";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->contenidoToolStripMenuItem, 
				this->índiceToolStripMenuItem, this->buscarToolStripMenuItem, this->toolStripSeparator5, this->acercadeToolStripMenuItem});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ayudaToolStripMenuItem->Text = L"Ay&uda";
			// 
			// contenidoToolStripMenuItem
			// 
			this->contenidoToolStripMenuItem->Name = L"contenidoToolStripMenuItem";
			this->contenidoToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->contenidoToolStripMenuItem->Text = L"&Contenido";
			// 
			// índiceToolStripMenuItem
			// 
			this->índiceToolStripMenuItem->Name = L"índiceToolStripMenuItem";
			this->índiceToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->índiceToolStripMenuItem->Text = L"Índic&e";
			// 
			// buscarToolStripMenuItem
			// 
			this->buscarToolStripMenuItem->Name = L"buscarToolStripMenuItem";
			this->buscarToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->buscarToolStripMenuItem->Text = L"&Buscar";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(149, 6);
			// 
			// acercadeToolStripMenuItem
			// 
			this->acercadeToolStripMenuItem->Name = L"acercadeToolStripMenuItem";
			this->acercadeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->acercadeToolStripMenuItem->Text = L"&Acerca de...";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(22) {this->nuevoToolStripButton, 
				this->abrirToolStripButton, this->guardarToolStripButton, this->imprimirToolStripButton, this->toolStripSeparator6, this->cortarToolStripButton, 
				this->copiarToolStripButton, this->pegarToolStripButton, this->toolStripSeparator7, this->ayudaToolStripButton, this->Op1, this->Op2, 
				this->BotonDilation, this->BotonErosion, this->Resta, this->toolStripButton1, this->AND, this->RegionesFast, this->Enhancements, 
				this->RegAB, this->Linking, this->Linking2});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(792, 25);
			this->toolStrip1->TabIndex = 6;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// nuevoToolStripButton
			// 
			this->nuevoToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->nuevoToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"nuevoToolStripButton.Image")));
			this->nuevoToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->nuevoToolStripButton->Name = L"nuevoToolStripButton";
			this->nuevoToolStripButton->Size = System::Drawing::Size(23, 22);
			this->nuevoToolStripButton->Text = L"&Nuevo";
			// 
			// abrirToolStripButton
			// 
			this->abrirToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->abrirToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"abrirToolStripButton.Image")));
			this->abrirToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->abrirToolStripButton->Name = L"abrirToolStripButton";
			this->abrirToolStripButton->Size = System::Drawing::Size(23, 22);
			this->abrirToolStripButton->Text = L"&Abrir";
			this->abrirToolStripButton->Click += gcnew System::EventHandler(this, &Form1::abrirToolStripButton_Click);
			// 
			// guardarToolStripButton
			// 
			this->guardarToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->guardarToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"guardarToolStripButton.Image")));
			this->guardarToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->guardarToolStripButton->Name = L"guardarToolStripButton";
			this->guardarToolStripButton->Size = System::Drawing::Size(23, 22);
			this->guardarToolStripButton->Text = L"&Guardar";
			this->guardarToolStripButton->Click += gcnew System::EventHandler(this, &Form1::guardarToolStripMenuItem_Click);
			// 
			// imprimirToolStripButton
			// 
			this->imprimirToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->imprimirToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imprimirToolStripButton.Image")));
			this->imprimirToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->imprimirToolStripButton->Name = L"imprimirToolStripButton";
			this->imprimirToolStripButton->Size = System::Drawing::Size(23, 22);
			this->imprimirToolStripButton->Text = L"&Imprimir";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
			// 
			// cortarToolStripButton
			// 
			this->cortarToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->cortarToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cortarToolStripButton.Image")));
			this->cortarToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->cortarToolStripButton->Name = L"cortarToolStripButton";
			this->cortarToolStripButton->Size = System::Drawing::Size(23, 22);
			this->cortarToolStripButton->Text = L"Cort&ar";
			// 
			// copiarToolStripButton
			// 
			this->copiarToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->copiarToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copiarToolStripButton.Image")));
			this->copiarToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->copiarToolStripButton->Name = L"copiarToolStripButton";
			this->copiarToolStripButton->Size = System::Drawing::Size(23, 22);
			this->copiarToolStripButton->Text = L"&Copiar";
			// 
			// pegarToolStripButton
			// 
			this->pegarToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->pegarToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pegarToolStripButton.Image")));
			this->pegarToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->pegarToolStripButton->Name = L"pegarToolStripButton";
			this->pegarToolStripButton->Size = System::Drawing::Size(23, 22);
			this->pegarToolStripButton->Text = L"&Pegar";
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
			// 
			// ayudaToolStripButton
			// 
			this->ayudaToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ayudaToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ayudaToolStripButton.Image")));
			this->ayudaToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ayudaToolStripButton->Name = L"ayudaToolStripButton";
			this->ayudaToolStripButton->Size = System::Drawing::Size(23, 22);
			this->ayudaToolStripButton->Text = L"Ay&uda";
			// 
			// Op1
			// 
			this->Op1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Op1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Op1.Image")));
			this->Op1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Op1->Name = L"Op1";
			this->Op1->Size = System::Drawing::Size(31, 22);
			this->Op1->Text = L"Op1";
			this->Op1->ToolTipText = L"Operando1";
			this->Op1->Click += gcnew System::EventHandler(this, &Form1::Op1_Click);
			// 
			// Op2
			// 
			this->Op2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Op2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Op2.Image")));
			this->Op2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Op2->Name = L"Op2";
			this->Op2->Size = System::Drawing::Size(31, 22);
			this->Op2->Text = L"Op2";
			this->Op2->ToolTipText = L"Operando2";
			this->Op2->Click += gcnew System::EventHandler(this, &Form1::Op2_Click);
			// 
			// BotonDilation
			// 
			this->BotonDilation->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->BotonDilation->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BotonDilation.Image")));
			this->BotonDilation->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->BotonDilation->Name = L"BotonDilation";
			this->BotonDilation->Size = System::Drawing::Size(23, 22);
			this->BotonDilation->Text = L"BotonDilation";
			this->BotonDilation->Click += gcnew System::EventHandler(this, &Form1::BotonDilation_Click);
			// 
			// BotonErosion
			// 
			this->BotonErosion->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->BotonErosion->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BotonErosion.Image")));
			this->BotonErosion->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->BotonErosion->Name = L"BotonErosion";
			this->BotonErosion->Size = System::Drawing::Size(23, 22);
			this->BotonErosion->Text = L"BotonErosion";
			this->BotonErosion->Click += gcnew System::EventHandler(this, &Form1::BotonErosion_Click);
			// 
			// Resta
			// 
			this->Resta->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->Resta->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Resta.Image")));
			this->Resta->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->Resta->Name = L"Resta";
			this->Resta->Size = System::Drawing::Size(23, 22);
			this->Resta->Text = L"Resta";
			this->Resta->Click += gcnew System::EventHandler(this, &Form1::Resta_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Transparent;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// AND
			// 
			this->AND->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->AND->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"AND.Image")));
			this->AND->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->AND->Name = L"AND";
			this->AND->Size = System::Drawing::Size(32, 22);
			this->AND->Text = L"AND";
			this->AND->Click += gcnew System::EventHandler(this, &Form1::AND_Click);
			// 
			// RegionesFast
			// 
			this->RegionesFast->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->RegionesFast->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"RegionesFast.Image")));
			this->RegionesFast->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->RegionesFast->Name = L"RegionesFast";
			this->RegionesFast->Size = System::Drawing::Size(76, 22);
			this->RegionesFast->Text = L"RegionesFast";
			this->RegionesFast->Click += gcnew System::EventHandler(this, &Form1::RegionesFast_Click);
			// 
			// Enhancements
			// 
			this->Enhancements->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Enhancements->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->mexHatImagenThresholdToolStripMenuItem, 
				this->mexHatImagenThreshold2ToolStripMenuItem, this->mexHatImagenchikiToolStripMenuItem, this->mexHatImagenSauvolaToolStripMenuItem, 
				this->mexHatImagenKittlerToolStripMenuItem, this->mexHToolStripMenuItem});
			this->Enhancements->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Enhancements.Image")));
			this->Enhancements->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Enhancements->Name = L"Enhancements";
			this->Enhancements->Size = System::Drawing::Size(84, 22);
			this->Enhancements->Text = L"Enhacements";
			// 
			// mexHatImagenThresholdToolStripMenuItem
			// 
			this->mexHatImagenThresholdToolStripMenuItem->Name = L"mexHatImagenThresholdToolStripMenuItem";
			this->mexHatImagenThresholdToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHatImagenThresholdToolStripMenuItem->Text = L"MexHat+Imagen+Threshold";
			this->mexHatImagenThresholdToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHatImagenThresholdToolStripMenuItem_Click);
			// 
			// mexHatImagenThreshold2ToolStripMenuItem
			// 
			this->mexHatImagenThreshold2ToolStripMenuItem->Name = L"mexHatImagenThreshold2ToolStripMenuItem";
			this->mexHatImagenThreshold2ToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHatImagenThreshold2ToolStripMenuItem->Text = L"MexHat+Imagen+Threshold2";
			this->mexHatImagenThreshold2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHatImagenThreshold2ToolStripMenuItem_Click);
			// 
			// mexHatImagenchikiToolStripMenuItem
			// 
			this->mexHatImagenchikiToolStripMenuItem->Name = L"mexHatImagenchikiToolStripMenuItem";
			this->mexHatImagenchikiToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHatImagenchikiToolStripMenuItem->Text = L"MexHat+Imagen+chiki";
			this->mexHatImagenchikiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHatImagenchikiToolStripMenuItem_Click);
			// 
			// mexHatImagenSauvolaToolStripMenuItem
			// 
			this->mexHatImagenSauvolaToolStripMenuItem->Name = L"mexHatImagenSauvolaToolStripMenuItem";
			this->mexHatImagenSauvolaToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHatImagenSauvolaToolStripMenuItem->Text = L"MexHat+Imagen+Sauvola";
			this->mexHatImagenSauvolaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHatImagenSauvolaToolStripMenuItem_Click);
			// 
			// mexHatImagenKittlerToolStripMenuItem
			// 
			this->mexHatImagenKittlerToolStripMenuItem->Name = L"mexHatImagenKittlerToolStripMenuItem";
			this->mexHatImagenKittlerToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHatImagenKittlerToolStripMenuItem->Text = L"MexHat+Imagen+Kittler";
			this->mexHatImagenKittlerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHatImagenKittlerToolStripMenuItem_Click);
			// 
			// mexHToolStripMenuItem
			// 
			this->mexHToolStripMenuItem->Name = L"mexHToolStripMenuItem";
			this->mexHToolStripMenuItem->Size = System::Drawing::Size(227, 22);
			this->mexHToolStripMenuItem->Text = L"MexHat+Imagen+KittlerPro";
			this->mexHToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexHToolStripMenuItem_Click);
			// 
			// RegAB
			// 
			this->RegAB->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->RegAB->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"RegAB.Image")));
			this->RegAB->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->RegAB->Name = L"RegAB";
			this->RegAB->Size = System::Drawing::Size(43, 22);
			this->RegAB->Text = L"RegAB";
			this->RegAB->Click += gcnew System::EventHandler(this, &Form1::RegAB_Click);
			// 
			// Linking
			// 
			this->Linking->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Linking->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Linking.Image")));
			this->Linking->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Linking->Name = L"Linking";
			this->Linking->Size = System::Drawing::Size(43, 22);
			this->Linking->Text = L"Linking";
			this->Linking->ToolTipText = L"Edge Linking";
			this->Linking->Click += gcnew System::EventHandler(this, &Form1::Linking_Click);
			// 
			// Linking2
			// 
			this->Linking2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Linking2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Linking2.Image")));
			this->Linking2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Linking2->Name = L"Linking2";
			this->Linking2->Size = System::Drawing::Size(49, 22);
			this->Linking2->Text = L"Linking2";
			this->Linking2->Click += gcnew System::EventHandler(this, &Form1::Linking2_Click);
			// 
			// toolStrip2
			// 
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->BotonAGrises, this->Sobel, 
				this->Mascaras, this->Ecualizar, this->Thresholding, this->Regiones, this->RegSignificativas, this->Contenedores, this->Excentricidad, 
				this->Areas, this->Letras});
			this->toolStrip2->Location = System::Drawing::Point(0, 49);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(792, 25);
			this->toolStrip2->TabIndex = 8;
			this->toolStrip2->Text = L"toolStrip2";
			// 
			// BotonAGrises
			// 
			this->BotonAGrises->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->BotonAGrises->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"BotonAGrises.Image")));
			this->BotonAGrises->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->BotonAGrises->Name = L"BotonAGrises";
			this->BotonAGrises->Size = System::Drawing::Size(98, 22);
			this->BotonAGrises->Text = L"A Escala de Grises";
			this->BotonAGrises->Click += gcnew System::EventHandler(this, &Form1::BotonAGrises_Click);
			// 
			// Sobel
			// 
			this->Sobel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Sobel->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Sobel->Name = L"Sobel";
			this->Sobel->Size = System::Drawing::Size(37, 22);
			this->Sobel->Text = L"Sobel";
			this->Sobel->Click += gcnew System::EventHandler(this, &Form1::Sobel_Click);
			// 
			// Mascaras
			// 
			this->Mascaras->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Mascaras->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->laplacianoToolStripMenuItem, 
				this->laplacianoDiagonalToolStripMenuItem, this->convolucionToolStripMenuItem, this->correlacionToolStripMenuItem, this->mexicanHatToolStripMenuItem, 
				this->mexicanColorToolStripMenuItem});
			this->Mascaras->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Mascaras.Image")));
			this->Mascaras->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Mascaras->Name = L"Mascaras";
			this->Mascaras->Size = System::Drawing::Size(68, 22);
			this->Mascaras->Text = L"Mascaras";
			// 
			// laplacianoToolStripMenuItem
			// 
			this->laplacianoToolStripMenuItem->Name = L"laplacianoToolStripMenuItem";
			this->laplacianoToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->laplacianoToolStripMenuItem->Text = L"Laplaciano";
			this->laplacianoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::laplacianoToolStripMenuItem_Click);
			// 
			// laplacianoDiagonalToolStripMenuItem
			// 
			this->laplacianoDiagonalToolStripMenuItem->Name = L"laplacianoDiagonalToolStripMenuItem";
			this->laplacianoDiagonalToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->laplacianoDiagonalToolStripMenuItem->Text = L"Laplaciano diagonal";
			this->laplacianoDiagonalToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::laplacianoDiagonalToolStripMenuItem_Click);
			// 
			// convolucionToolStripMenuItem
			// 
			this->convolucionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->elegirToolStripMenuItem, 
				this->elegirImagenToolStripMenuItem, this->aplicarToolStripMenuItem});
			this->convolucionToolStripMenuItem->Name = L"convolucionToolStripMenuItem";
			this->convolucionToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->convolucionToolStripMenuItem->Text = L"Convolucion";
			// 
			// elegirToolStripMenuItem
			// 
			this->elegirToolStripMenuItem->Name = L"elegirToolStripMenuItem";
			this->elegirToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->elegirToolStripMenuItem->Text = L"Elegir feature";
			this->elegirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::elegirToolStripMenuItem_Click);
			// 
			// elegirImagenToolStripMenuItem
			// 
			this->elegirImagenToolStripMenuItem->Name = L"elegirImagenToolStripMenuItem";
			this->elegirImagenToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->elegirImagenToolStripMenuItem->Text = L"Elegir imagen";
			this->elegirImagenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::elegirImagenToolStripMenuItem_Click);
			// 
			// aplicarToolStripMenuItem
			// 
			this->aplicarToolStripMenuItem->Name = L"aplicarToolStripMenuItem";
			this->aplicarToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->aplicarToolStripMenuItem->Text = L"Aplicar";
			this->aplicarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aplicarToolStripMenuItem_Click);
			// 
			// correlacionToolStripMenuItem
			// 
			this->correlacionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->elegirFeatureToolStripMenuItem, 
				this->elegirImagenToolStripMenuItem1, this->aplicarToolStripMenuItem1});
			this->correlacionToolStripMenuItem->Name = L"correlacionToolStripMenuItem";
			this->correlacionToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->correlacionToolStripMenuItem->Text = L"Correlacion";
			// 
			// elegirFeatureToolStripMenuItem
			// 
			this->elegirFeatureToolStripMenuItem->Name = L"elegirFeatureToolStripMenuItem";
			this->elegirFeatureToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->elegirFeatureToolStripMenuItem->Text = L"Elegir feature";
			this->elegirFeatureToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::elegirFeatureToolStripMenuItem_Click);
			// 
			// elegirImagenToolStripMenuItem1
			// 
			this->elegirImagenToolStripMenuItem1->Name = L"elegirImagenToolStripMenuItem1";
			this->elegirImagenToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->elegirImagenToolStripMenuItem1->Text = L"Elegir imagen";
			this->elegirImagenToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::elegirImagenToolStripMenuItem_Click);
			// 
			// aplicarToolStripMenuItem1
			// 
			this->aplicarToolStripMenuItem1->Name = L"aplicarToolStripMenuItem1";
			this->aplicarToolStripMenuItem1->Size = System::Drawing::Size(150, 22);
			this->aplicarToolStripMenuItem1->Text = L"Aplicar";
			this->aplicarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::aplicarToolStripMenuItem_Click);
			// 
			// mexicanHatToolStripMenuItem
			// 
			this->mexicanHatToolStripMenuItem->Name = L"mexicanHatToolStripMenuItem";
			this->mexicanHatToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->mexicanHatToolStripMenuItem->Text = L"Mexican Hat";
			this->mexicanHatToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexicanHatToolStripMenuItem_Click);
			// 
			// Ecualizar
			// 
			this->Ecualizar->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Ecualizar->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Ecualizar.Image")));
			this->Ecualizar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Ecualizar->Name = L"Ecualizar";
			this->Ecualizar->Size = System::Drawing::Size(53, 22);
			this->Ecualizar->Text = L"Ecualizar";
			this->Ecualizar->ToolTipText = L"Ecualizacion de histograma";
			this->Ecualizar->Click += gcnew System::EventHandler(this, &Form1::Ecualizar_Click);
			// 
			// Thresholding
			// 
			this->Thresholding->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Thresholding->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->thresholdToolStripMenuItem, 
				this->threshold2ToolStripMenuItem, this->adaptativoToolStripMenuItem, this->thresToolStripMenuItem});
			this->Thresholding->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Thresholding.Image")));
			this->Thresholding->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Thresholding->Name = L"Thresholding";
			this->Thresholding->Size = System::Drawing::Size(81, 22);
			this->Thresholding->Text = L"Thresholding";
			// 
			// thresholdToolStripMenuItem
			// 
			this->thresholdToolStripMenuItem->Name = L"thresholdToolStripMenuItem";
			this->thresholdToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->thresholdToolStripMenuItem->Text = L"Threshold";
			this->thresholdToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::thresholdToolStripMenuItem_Click);
			// 
			// threshold2ToolStripMenuItem
			// 
			this->threshold2ToolStripMenuItem->Name = L"threshold2ToolStripMenuItem";
			this->threshold2ToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->threshold2ToolStripMenuItem->Text = L"Threshold2";
			this->threshold2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::threshold2ToolStripMenuItem_Click);
			// 
			// adaptativoToolStripMenuItem
			// 
			this->adaptativoToolStripMenuItem->Name = L"adaptativoToolStripMenuItem";
			this->adaptativoToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->adaptativoToolStripMenuItem->Text = L"Adaptativo";
			this->adaptativoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::adaptativoToolStripMenuItem_Click);
			// 
			// thresToolStripMenuItem
			// 
			this->thresToolStripMenuItem->Name = L"thresToolStripMenuItem";
			this->thresToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->thresToolStripMenuItem->Text = L"Sauvola";
			this->thresToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::thresToolStripMenuItem_Click);
			// 
			// Regiones
			// 
			this->Regiones->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Regiones->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Regiones.Image")));
			this->Regiones->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Regiones->Name = L"Regiones";
			this->Regiones->Size = System::Drawing::Size(55, 22);
			this->Regiones->Text = L"Regiones";
			this->Regiones->ToolTipText = L"Extrae los elementos conectados";
			this->Regiones->Click += gcnew System::EventHandler(this, &Form1::Regiones_Click);
			// 
			// RegSignificativas
			// 
			this->RegSignificativas->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->RegSignificativas->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"RegSignificativas.Image")));
			this->RegSignificativas->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->RegSignificativas->Name = L"RegSignificativas";
			this->RegSignificativas->Size = System::Drawing::Size(92, 22);
			this->RegSignificativas->Text = L"RegSignificativas";
			this->RegSignificativas->ToolTipText = L"Regiones Significativas";
			this->RegSignificativas->Click += gcnew System::EventHandler(this, &Form1::RegSignificativas_Click);
			// 
			// Contenedores
			// 
			this->Contenedores->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Contenedores->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Contenedores.Image")));
			this->Contenedores->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Contenedores->Name = L"Contenedores";
			this->Contenedores->Size = System::Drawing::Size(79, 22);
			this->Contenedores->Text = L"Contenedores";
			this->Contenedores->ToolTipText = L"Contenedores de rectangulos";
			this->Contenedores->Click += gcnew System::EventHandler(this, &Form1::Contenedores_Click);
			// 
			// Excentricidad
			// 
			this->Excentricidad->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Excentricidad->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Excentricidad.Image")));
			this->Excentricidad->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Excentricidad->Name = L"Excentricidad";
			this->Excentricidad->Size = System::Drawing::Size(75, 22);
			this->Excentricidad->Text = L"Excentricidad";
			this->Excentricidad->Click += gcnew System::EventHandler(this, &Form1::Excentricidad_Click);
			// 
			// Areas
			// 
			this->Areas->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Areas->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Areas.Image")));
			this->Areas->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Areas->Name = L"Areas";
			this->Areas->Size = System::Drawing::Size(39, 22);
			this->Areas->Text = L"Areas";
			this->Areas->Click += gcnew System::EventHandler(this, &Form1::Areas_Click);
			// 
			// Letras
			// 
			this->Letras->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Letras->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Letras.Image")));
			this->Letras->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->Letras->Name = L"Letras";
			this->Letras->Size = System::Drawing::Size(41, 22);
			this->Letras->Text = L"Letras";
			this->Letras->ToolTipText = L"Busca Letras";
			this->Letras->Click += gcnew System::EventHandler(this, &Form1::Letras_Click);
			// 
			// mexicanColorToolStripMenuItem
			// 
			this->mexicanColorToolStripMenuItem->Name = L"mexicanColorToolStripMenuItem";
			this->mexicanColorToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->mexicanColorToolStripMenuItem->Text = L"MexicanColor";
			this->mexicanColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::mexicanColorToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 566);
			this->Controls->Add(this->toolStrip2);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"ProgramaTFGv1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void abrir (void){
				 this->openFileDialog1->ShowDialog();
				 this->Imagen = gcnew Bitmap(this->openFileDialog1->FileName);
				 this->Ventana = gcnew ProgramaTFGv1::VentanaImagen();
				 this->Ventana->establecerImagen(this->Imagen);
				 this->Ventana->aColores = true;
				 this->Ventana->Size::set(this->Imagen->Size::get());
				 this->Ventana->MdiParent = this;
				 this->Ventana->Show();
			 }

	private: array<unsigned char, 2>^ aGrises (System::Drawing::Bitmap^ Imagen)
			{
				int x, y;
				double r, g, b;
				array<unsigned char, 2>^ Matriz = gcnew array<unsigned char, 2>(Imagen->Width, Imagen->Height);
				for (y=0;y<Imagen->Height;y++)
				{
					for (x=0;x<Imagen->Width;x++)
					{
						r = safe_cast<double> (Imagen->GetPixel(x,y).R);
						g = safe_cast<double> (Imagen->GetPixel(x,y).G);
						b = safe_cast<double> (Imagen->GetPixel(x,y).B);
						Matriz [x,y] = safe_cast<unsigned char>(0.21*r + 0.71*g + 0.08*b);
					}
				}
				return Matriz;
			}

	public: System::Drawing::Bitmap^ MatrizAImagen (array<unsigned char, 2>^ Matriz){
				int x, y;
				System::Drawing::Color c;
				System::Drawing::Bitmap^ Imagen = gcnew System::Drawing::Bitmap(Matriz->GetLength(0), Matriz->GetLength(1));
				for (y=0;y<Imagen->Height;y++)
				{
					for (x=0;x<Imagen->Width;x++)
					{
						c = c.FromArgb(Matriz[x,y], Matriz[x,y], Matriz[x,y]);
						Imagen->SetPixel(x, y, c);
					}
				}
				return Imagen;
			 }

	private: System::Void abrirToolStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->abrir();
			 }

	private: System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {			
				 this->abrir();
			 }

	private: System::Void BotonAGrises_Click(System::Object^  sender, System::EventArgs^  e) {
				 VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
				 if(V!=nullptr)
				 {
					ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					Vnueva->MatrizImagen = this->aGrises(V->Imagen);
					Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					Vnueva->aColores = false;
					Vnueva->Size::set(Vnueva->Imagen->Size::get());
					Vnueva->MdiParent = this;
					Vnueva->Show();
				 }
			}

	private: cli::array<unsigned char, 2>^ AplicarMedia (cli::array<unsigned char, 2> ^ ImArray){
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 int m = 3; // (m, n) Tamano de la mascara para el calculo de la media
			 int n = 3;
			 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=0.0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 AuxArray[x,y]+=safe_cast<double>((1.0/safe_cast<double>(m*n))*safe_cast<double>(ImArray[a,b]));
						 }
					 }
				 }
			 }
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=safe_cast<unsigned char>(AuxArray[x,y]);
				 }
			 }
			 return NewImArray;
		 }

	private: cli::array<unsigned char, 2>^ AplicarCo (cli::array<unsigned char, 2> ^ ImArray, cli::array<unsigned char, 2> ^ MaskArray){
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 AuxArray[x,y]+=safe_cast<double>(MaskArray[i,j]*ImArray[a,b]/((M-(m-1))*(N-(n-1))));
						 }
					 }
				 }
			 }
			 double auxmax = AuxArray[0,0];
			 double auxmin = AuxArray[0,0];
			 for each(double aux in AuxArray){
				 if(aux > auxmax)
					 auxmax = aux;
				 if(aux < auxmin)
					 auxmin = aux;
			 }
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=safe_cast<unsigned char>((AuxArray[x,y]-auxmin)/(auxmax-auxmin)*255.0);
				 }
			 }
			 return NewImArray;
		 }

	private: cli::array<int, 2>^ AplicarMascaraINT (cli::array<unsigned char, 2> ^ ImArray, cli::array<double, 2> ^ MaskArray){
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 cli::array<int, 2>^ NewImArray = gcnew cli::array<int, 2>(M,N);
			 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 AuxArray[x,y]+=MaskArray[i,j]*safe_cast<double>(ImArray[a,b])/(m*n);
						 }
					 }
				 }
			 }
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=safe_cast<double>(ImArray[x,y])+AuxArray[x,y];
                     NewImArray[x,y]=safe_cast<int>(AuxArray[x,y]);
				 }
			 }
			 return NewImArray;
		}

	private: cli::array<unsigned char, 2>^ AplicarMascara (cli::array<unsigned char, 2> ^ ImArray, cli::array<double, 2> ^ MaskArray){
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 AuxArray[x,y]+=safe_cast<double>(MaskArray[i,j]*ImArray[a,b]);
						 }
					 }
				 }
			 }
			 double auxmax = AuxArray[0,0];
			 double auxmin = AuxArray[0,0];
			 for each(double aux in AuxArray){
				 if(aux > auxmax)
					 auxmax = aux;
				 if(aux < auxmin)
					 auxmin = aux;
			 }
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=safe_cast<unsigned char>((AuxArray[x,y]-auxmin)/(auxmax-auxmin)*255.0);
				 }
			 }
			 return NewImArray;
		 }

	private: System::Void Sobel_Click(System::Object^  sender, System::EventArgs^  e) {
			 VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
			 cli::array<double, 2>^ SobelMaskArray = gcnew cli::array<double, 2>(3,3);
			 if(V!=nullptr && !V->aColores)
				 {
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 SobelMaskArray[0,0]= -1.0; SobelMaskArray[1,0]= -2.0; SobelMaskArray[2,0]= -1.0;
					 SobelMaskArray[0,1]= 0; SobelMaskArray[1,1]= 0; SobelMaskArray[2,1]= 0;
					 SobelMaskArray[0,2]= 1.0; SobelMaskArray[1,2]= 2.0; SobelMaskArray[2,2]= 1.0;
					 int M = V->MatrizImagen->GetLength(0);
					 int N = V->MatrizImagen->GetLength(1);
					 int m = SobelMaskArray->GetLength(0);
					 int n = SobelMaskArray->GetLength(1);
					 cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(M,N);
					 cli::array<double, 2>^ AuxArray1 = gcnew cli::array<double, 2>(M,N);
					 cli::array<double, 2>^ AuxArray2 = gcnew cli::array<double, 2>(M,N);
					 int x, y, i, j, a ,b;
					 double auxmax = 0.0;
					 double auxmin;
					 for(y=0; y<N; y++){
						 for(x=0; x<M; x++){
							 AuxArray1[x,y]=0;
							 for(j=0; j<n; j++){
								 for(i=0; i<m; i++){
									 a=x+i-(m-1)/2;
									 b=y+j-(n-1)/2;
									 if((a>=0 && a<M) && (b>=0 && b<N))
									 AuxArray1[x,y]+=safe_cast<double>(SobelMaskArray[i,j]*safe_cast<double>(V->MatrizImagen[a,b]));
								 }
							 }
						 }
					 }
					 SobelMaskArray[0,0]= -1.0; SobelMaskArray[1,0]= 0; SobelMaskArray[2,0]= 1.0;
					 SobelMaskArray[0,1]= -2.0; SobelMaskArray[1,1]= 0; SobelMaskArray[2,1]= 2;
					 SobelMaskArray[0,2]= -1.0; SobelMaskArray[1,2]= 0; SobelMaskArray[2,2]= 1.0;
					 for(y=0; y<N; y++){
						 for(x=0; x<M; x++){
							 AuxArray2[x,y]=0;
							 for(j=0; j<n; j++){
								 for(i=0; i<m; i++){
									 a=x+i-(m-1)/2;
									 b=y+j-(n-1)/2;
									 if((a>=0 && a<M) && (b>=0 && b<N))
									 AuxArray2[x,y]+=safe_cast<double>(SobelMaskArray[i,j]*safe_cast<double>(V->MatrizImagen[a,b]));
								 }
							 }
						 }
					 }
					 for(j=0;j<V->MatrizImagen->GetLength(1);j++){
						 for(i=0;i<V->MatrizImagen->GetLength(0);i++){
							 AuxArray1[i,j]=safe_cast<double>((System::Math::Abs(safe_cast<float>(AuxArray1[i,j]))+System::Math::Abs(safe_cast<float>(AuxArray2[i,j]))));
						 }
					 }
					 for each(double aux in AuxArray1){
						 if(aux > auxmax)
							 auxmax = aux;
					 }
					 auxmin = auxmax;
					 for each(double aux in AuxArray1){
						 if(aux < auxmin)
							 auxmin = aux;
					 }
					 for(y=0; y<N; y++){
						 for(x=0; x<M; x++){
							 NewArray[x,y]=safe_cast<unsigned char>((AuxArray1[x,y]-auxmin)/(auxmax-auxmin)*255.0);
						 }
					 }
					 Vnueva->MatrizImagen = NewArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
				 }
		 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

    private: System::Void laplacianoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 	 VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
			 cli::array<double, 2>^ MaskArray = gcnew cli::array<double, 2>(3,3);
			 if(V!=nullptr && !V->aColores)
				 {
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 MaskArray[0,0]= 0.0; MaskArray[1,0]= -1.0; MaskArray[2,0]= 0.0;
					 MaskArray[0,1]= -1.0; MaskArray[1,1]= 4.0; MaskArray[2,1]= -1.0;
					 MaskArray[0,2]= 0.0; MaskArray[1,2]= -1.0; MaskArray[2,2]= 0.0;
					 Vnueva->MatrizImagen = this->AplicarMascara(V->MatrizImagen, MaskArray);
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
				 }
		 }

    private: System::Void laplacianoDiagonalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 	 VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
			 cli::array<double, 2>^ MaskArray = gcnew cli::array<double, 2>(3,3);
			 if(V!=nullptr && !V->aColores)
				 {
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 MaskArray[0,0]= -1.0; MaskArray[1,0]= -1.0; MaskArray[2,0]= -1.0;
					 MaskArray[0,1]= -1.0; MaskArray[1,1]= 8.0; MaskArray[2,1]= -1.0;
					 MaskArray[0,2]= -1.0; MaskArray[1,2]= -1.0; MaskArray[2,2]= -1.0;
					 Vnueva->MatrizImagen = this->AplicarMascara(V->MatrizImagen, MaskArray);
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
				 }
		 }

    private: System::Void elegirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if(V!=nullptr && !V->aColores)
			 {
				 int x,y;
				 Feature = gcnew cli::array<unsigned char, 2> (V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
				 for (y=0;y<Feature->GetLength(1)-1;y++) 
				 {
					 for (x=0;x<Feature->GetLength(0)-1;x++)
					 {
						 Feature[x,y]= V->MatrizImagen[Feature->GetLength(0)-1-x,Feature->GetLength(1)-1-y];
					 }
				 }

			 }
		 }

    private: System::Void elegirImagenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if(V!=nullptr && !V->aColores)
			 {
				 int x, y;
				 ImagenCo = gcnew cli::array<unsigned char, 2> (V->MatrizImagen->GetLength(0)+(Feature->GetLength(0)-1),V->MatrizImagen->GetLength(1)+(Feature->GetLength(1)-1));
				 for(y=0; y<(V->MatrizImagen->GetLength(1)+(Feature->GetLength(1)-1)); y++){
					 for(x=0; x<(V->MatrizImagen->GetLength(0)+(Feature->GetLength(0)-1)); x++){
						 if (x>=(Feature->GetLength(0)-1)/2 && x<(V->MatrizImagen->GetLength(0)-(Feature->GetLength(0)-1)/2) && y>=(Feature->GetLength(1)-1)/2 && y<(V->MatrizImagen->GetLength(1)-(Feature->GetLength(1)-1)/2))
						 ImagenCo[x,y]=V->MatrizImagen[x,y];
						 else
						 ImagenCo[x,y]=0;
					 }
				 }
			 }
		 }

    private: System::Void aplicarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = this->AplicarCo(ImagenCo, Feature);
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();
					 int x, y;
					 int i, j;
					 unsigned char aux = Vnueva->MatrizImagen[0,0];
					 i = j =0;

					 for (y=0;y<Vnueva->MatrizImagen->GetLength(1)-1;y++) 
					 {
						 for (x=0;x<Vnueva->MatrizImagen->GetLength(0)-1;x++)
						 {
							 if ((x!=0 || y!=0) && Vnueva->MatrizImagen[x,y]>aux)
							 {
								 aux=Vnueva->MatrizImagen[x,y];
								 i = x;
								 j = y;
							 }
						 }
					 }
					 this->toolStripStatusLabel1->Text = L"x = "+i+L"   y = "+j;
		 }

    private: System::Void elegirFeatureToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if(V!=nullptr && !V->aColores)
			 {
				 int x, y;
				 Feature = gcnew cli::array<unsigned char, 2> (V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
				 for (y=0;y<Feature->GetLength(1)-1;y++) 
				 {
					 for (x=0;x<Feature->GetLength(0)-1;x++)
					 {
						 Feature[x,y]= V->MatrizImagen[x,y];
					 }
				 }

			 }
		 }

    private: Void Brink (void)
        {
            ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
            if(V!=nullptr && !V->aColores)
            {
                int M = V->MatrizImagen->GetLength(0);
                int N = V->MatrizImagen->GetLength(1);
                int x, y, i, j, T, S;
                double count;
                cli::array<double, 2>^ p = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ P0 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ P1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ H0 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ H1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ minH0H1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<unsigned char, 2>^ medias = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0), V->MatrizImagen->GetLength(1));
                cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0), V->MatrizImagen->GetLength(1));

                medias = this->AplicarMedia(V->MatrizImagen);
                for (i=0; i<256; i++)
                {
                    for (j=0; j<256; j++)
                    {
                        p[i,j] = 0.0;
                        count = 0;
                        for (y=0; y<N; y++)
                        {
                            for (x=0; x<M; x++)
                            {
                                if (V->MatrizImagen[x,y] == i && medias[x,y] == j)
                                    count++;
                            }
                        }
                        p[i,j] = count/M*N;
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        P0[T,S] = 0.0;
                        for (j=0; j<=S; j++)
                            for (i=0; i<=T; i++)
                                P0[T,S] += p[i,j];
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        P1[T,S] = 0.0;
                        for (j=S+1; j<256; j++)
                            for (i=T+1; i<256; i++)
                                P1[T,S] += p[i,j];
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        H0[T,S] = 0.0;
                        for (j=0; j<=S; j++)
                            for (i=0; i<=T; i++)
                            {
                                if (p[i,j] != 0.0)
                                    H0[T,S] -= (p[i,j]/P0[T,S])*System::Math::Log10(p[i,j]/P0[T,S]);
                            }
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        H1[T,S] = 0.0;
                        for (j=S+1; j<256; j++)
                            for (i=T+1; i<256; i++)
                            {
                                if (p[i,j] != 0.0)
                                    H1[T,S] -= (p[i,j]/P1[T,S])*System::Math::Log10(p[i,j]/P1[T,S]);
                            }
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        if (H0[S,T]<=H1[S,T])
                            minH0H1[S,T] = H0[S,T];
                        else
                            minH0H1[S,T] = H1[S,T];
                    }
                }
                unsigned char mejorS, mejorT;
                double aux = minH0H1[0,0];
                mejorS = mejorT = 0;
                i = j = 0;
                for (y=0;y<256;y++)
                {
                    for (x=0;x<256;x++)
                    {
                        if ((x!=0 || y!=0) && minH0H1[x,y]>aux)
                        {
                            aux=minH0H1[x,y];
                            i = x;
                            j = y;
                        }
                    }
                }
                mejorT = safe_cast<unsigned char>(i);
                mejorS = safe_cast<unsigned char>(j);
                for (y=0; y<N; y++)
                {
                    for (x=0; x<M; x++)
                    {
                        if (V->MatrizImagen[x,y] <= mejorT && medias[x,y] <= mejorS)
                        {
                            NewArray[x,y]=0;
                        }
                        else
                        {
                            if (V->MatrizImagen[x,y] > mejorT && medias[x,y] > mejorS)
                            {
                                NewArray[x,y]=255;
                            }
                            else
                            {
                                NewArray[x,y]=0;
                            }
                        }
                    }
                }
                ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
                Vnueva->MatrizImagen = NewArray;
                Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
                Vnueva->aColores = false;
                Vnueva->Size::set(Vnueva->Imagen->Size::get());
                Vnueva->MdiParent = this;
                Vnueva->Show();
            }
        }

    private: Void Brink2 (void)
        {
            ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
            if(V!=nullptr && !V->aColores)
            {
                int M = V->MatrizImagen->GetLength(0);
                int N = V->MatrizImagen->GetLength(1);
                int x, y, i, j;
                int T = 0;
                int S = 0;
                double count;
                cli::array<double, 2>^ p = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ P0 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ P1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ H0 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ H1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<double, 2>^ minH0H1 = gcnew cli::array<double, 2>(256, 256);
                cli::array<unsigned char, 2>^ medias = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0), V->MatrizImagen->GetLength(1));
                cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0), V->MatrizImagen->GetLength(1));
                medias = this->AplicarMedia(V->MatrizImagen);
                for (i=0; i<256; i++)
                {
                    for (j=0; j<256; j++)
                    {
                        p[i,j] = 0.0;
                        count = 0;
                        for (y=0; y<N; y++)
                        {
                            for (x=0; x<M; x++)
                            {
                                if (V->MatrizImagen[x,y] == i && medias[x,y] == j)
                                    count++;
                            }
                        }
                        p[i,j] = count/safe_cast<double>(M*N);
                        P0[i,j] = 0.0;
                        H0[i,j] = 0.0;
                        for (S=0; S<=j; S++)
                        {
                            for (T=0; T<=i; T++)
                            {
                                P0[i,j] += p[T,S];
                                if (p[i,j] != 0.0)
                                    H0[i,j] -= (p[T,S]/P0[i,j])*System::Math::Log10(p[T,S]/P0[i,j]);
                            }
                        }
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        P1[T,S] = 0.0;
                        H1[T,S] = 0.0;
                        for (j=S+1; j<256; j++)
                        {
                            for (i=T+1; i<256; i++)
                            {
                                P1[T,S] += p[i,j];
                                if (p[i,j] != 0.0)
                                    H1[T,S] -= (p[i,j]/P1[T,S])*System::Math::Log10(p[i,j]/P1[T,S]);
                            }
                        }
                    }
                }
                for (T=0; T<256; T++)
                {
                    for (S=0; S<256; S++)
                    {
                        if (H0[S,T]<=H1[S,T])
                            minH0H1[S,T] = H0[S,T];
                        else
                            minH0H1[S,T] = H1[S,T];
                    }
                }
                unsigned char mejorS, mejorT;
                double aux = minH0H1[0,0];
                mejorS = mejorT = 0;
                i = j = 0;
                for (y=0;y<256;y++)
                {
                    for (x=0;x<256;x++)
                    {
                        if ((x!=0 || y!=0) && minH0H1[x,y]>aux)
                        {
                            aux=minH0H1[x,y];
                            i = x;
                            j = y;
                        }
                    }
                }
                mejorT = safe_cast<unsigned char>(i);
                mejorS = safe_cast<unsigned char>(j);
                for (y=0; y<N; y++)
                {
                    for (x=0; x<M; x++)
                    {
                        if (V->MatrizImagen[x,y] <= mejorT && medias[x,y] <= mejorS)
                        {
                            NewArray[x,y]=0;
                        }
                        else
                        {
                            if (V->MatrizImagen[x,y] > mejorT && medias[x,y] > mejorS)
                            {
                                NewArray[x,y]=255;
                            }
                            else
                            {
                                NewArray[x,y]=0;
                            }
                        }
                    }
                }
                ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
                Vnueva->MatrizImagen = NewArray;
                Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
                Vnueva->aColores = false;
                Vnueva->Size::set(Vnueva->Imagen->Size::get());
                Vnueva->MdiParent = this;
                Vnueva->Show();
            }
        }

    private: cli::array<unsigned char, 2>^ Threshold (cli::array<unsigned char, 2>^ Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int m = 33; // tiene que ser impar
            int n = 33; // idem
            int T = 150;// 150 funciona bien
            int t =0;
            int x, y;
            int i, j;
            int a, b;
            int cont;
            int u1, u2;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            for(y=0; y<N; y++)
            {
                for (x=0; x<M; x++)
                {
                    while(T!=t)
                    {
                        t=T;
                        cont=0;
                        u1 = u2 = 0;
                        for (j=0; j<n; j++)
                        {
                            for(i=0; i<m; i++)
                            {
                                a=x+i-(m-1)/2;
                                b=y+j-(n-1)/2;
                                if (a>=0 && a<=M && b>=0 && b<= N)
                                {
                                    if (Imagen[a,b]>t)
                                    {
                                        u1+=Imagen[a,b];
                                        cont++;
                                    }
                                    else
                                        u2+=Imagen[a,b];
                                }
                            }
                        }
                        if (cont>0)
                            if(cont<m*n)
                                T=(u1/cont+u2/(m*n-cont))/2;
                            else
                                T=u1/(2*cont);
                        else
                            T=u2/(2*m*n);
                    }
                    if (Imagen[x,y]>T)
                        AuxArray[x,y] = 255;
                    else
                        AuxArray[x,y] = 0;
                }
            }
            return AuxArray;
        }

    private: cli::array<unsigned char, 2>^ ThresholdINT (cli::array<int, 2>^ Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int m = 33; // tiene que ser impar
            int n = 33; // idem
            int T = 150; // 150 funciona bien
            int t =0;
            int x, y;
            int i, j;
            int a, b;
            int cont;
            int u1, u2;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            for(y=0; y<N; y++)
            {
                for (x=0; x<M; x++)
                {
                    while(T!=t)
                    {
                        t=T;
                        cont=0;
                        u1 = u2 = 0;
                        for (j=0; j<n; j++)
                        {
                            for(i=0; i<m; i++)
                            {
                                a=x+i-(m-1)/2;
                                b=y+j-(n-1)/2;
                                if (a>=0 && a<=M && b>=0 && b<= N)
                                {
                                    if (Imagen[a,b]>t)
                                    {
                                        u1+=Imagen[a,b];
                                        cont++;
                                    }
                                    else
                                        u2+=Imagen[a,b];
                                }
                            }
                        }
                        if (cont>0)
                            if(cont<m*n)
                                T=(u1/cont+u2/(m*n-cont))/2;
                            else
                                T=u1/(2*cont);
                        else
                            T=u2/(2*m*n);
                    }
                    if (Imagen[x,y]>T)
                        AuxArray[x,y] = 255;
                    else
                        AuxArray[x,y] = 0;
                }
            }
            return AuxArray;
        }

    private: cli::array<unsigned char, 2>^ ThresholdINTChico(cli::array<int, 2>^Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int m = 19; // tiene que ser impar
            int n = 19; // idem
            int T = 150; // 150 funciona bien
            int t =0;
            int x, y;
            int i, j;
            int a, b;
            int cont;
            int u1, u2;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            for(y=0; y<N; y++)
            {
                for (x=0; x<M; x++)
                {
                    while(T!=t)
                    {
                        t=T;
                        cont=0;
                        u1 = u2 = 0;
                        for (j=0; j<n; j++)
                        {
                            for(i=0; i<m; i++)
                            {
                                a=x+i-(m-1)/2;
                                b=y+j-(n-1)/2;
                                if (a>=0 && a<=M && b>=0 && b<= N)
                                {
                                    if (Imagen[a,b]>t)
                                    {
                                        u1+=Imagen[a,b];
                                        cont++;
                                    }
                                    else
                                        u2+=Imagen[a,b];
                                }
                            }
                        }
                        if (cont>0)
                            if(cont<m*n)
                                T=(u1/cont+u2/(m*n-cont))/2;
                            else
                                T=u1/(2*cont);
                        else
                            T=u2/(2*m*n);
                    }
                    if (Imagen[x,y]>T)
                        AuxArray[x,y] = 255;
                    else
                        AuxArray[x,y] = 0;
                }
            }
            return AuxArray;
        }

    private: cli::array<unsigned char, 2>^ Threshold2 (cli::array<unsigned char, 2>^ Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int m = 32; // tiene que ser multiplo de 640x480
            int n = 32; // idem
            int T;// = 150;
            int t =0;
            int x, y;
            int i, j;
            int a, b;
            int cont;
            int u1, u2;
            int max, min;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            for(y=0; y<=(N-n); y+=n)
            {
                for (x=0; x<=(M-m); x+=m)
                {
                    max=Imagen[x,y];
                    min=Imagen[x,y];
                    for (j=0; j<n; j++)
                    {
                        for(i=0; i<m; i++)
                        {
                            a=x+i;
                            b=y+j;
                            if (Imagen[a,b]>max)
                                max=Imagen[a,b];
                            if (Imagen[a,b]<min)
                                min=Imagen[a,b];
                        }
                    }
                    T=max-min;
                    while(T!=t)
                    {
                        t=T;
                        cont=0;
                        u1 = u2 = 0;
                        for (j=0; j<n; j++)
                        {
                            for(i=0; i<m; i++)
                            {
                                a=x+i;
                                b=y+j;
                                if (Imagen[a,b]>t)
                                {
                                    u1+=Imagen[a,b];
                                    cont++;
                                }
                                else
                                    u2+=Imagen[a,b];
                            }
                        }
                        if (cont>0)
                            if(cont<m*n)
                                T=(u1/cont+u2/(m*n-cont))/2;
                            else
                                T=u1/(2*cont);
                        else
                            T=u2/(2*m*n);
                    }
                    for (j=0; j<n; j++)
                    {
                        for(i=0; i<m; i++)
                        {
                            a=x+i;
                            b=y+j;
                            if (Imagen[a,b]>T)
                                AuxArray[a,b] = 255;
                            else
                                AuxArray[a,b] = 0;
                        }
                    }

                }
            }
            return AuxArray;
        }

    private: cli::array<unsigned char, 2>^ Threshold2INT (cli::array<int, 2>^ Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int m = 32; // tiene que ser multiplo de 640x480 por ejemplo.
            int n = 32; // idem
            int T;
            int t =0;
            int x, y;
            int i, j;
            int a, b;
            int cont;
            int u1, u2;
            int max, min;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            for(y=0; y<=(N-n); y+=n)
            {
                for (x=0; x<=(M-m); x+=m)
                {
                    max=Imagen[x,y];
                    min=Imagen[x,y];
                    for (j=0; j<n; j++)
                    {
                        for(i=0; i<m; i++)
                        {
                            a=x+i;
                            b=y+j;
                            if (Imagen[a,b]>max)
                                max=Imagen[a,b];
                            if (Imagen[a,b]<min)
                                min=Imagen[a,b];
                        }
                    }
                    T=(max-min)/2;
                    while(T!=t)
                    {
                        t=T;
                        cont=0;
                        u1 = u2 = 0;
                        for (j=0; j<n; j++)
                        {
                            for(i=0; i<m; i++)
                            {
                                a=x+i;
                                b=y+j;
                                if (Imagen[a,b]>t)
                                {
                                    u1+=Imagen[a,b];
                                    cont++;
                                }
                                else
                                    u2+=Imagen[a,b];
                            }
                        }
                        if (cont>0)
                            if(cont<m*n)
                                T=(u1/cont+u2/(m*n-cont))/2;
                            else
                                T=u1/(2*cont);
                        else
                            T=u2/(2*m*n);
                    }
                    for (j=0; j<n; j++)
                    {
                        for(i=0; i<m; i++)
                        {
                            a=x+i;
                            b=y+j;
                            if (Imagen[a,b]>T)
                                AuxArray[a,b] = 255;
                            else
                                AuxArray[a,b] = 0;
                        }
                    }

                }
            }
            return AuxArray;
        }

    private: cli::array<unsigned char, 2>^ Ecualizacion (cli::array<unsigned char, 2>^ Imagen)
        {
            int M = Imagen->GetLength(0);
            int N = Imagen->GetLength(1);
            int x, y, k;
            cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
            cliext::vector<int>^ nj = gcnew cliext::vector<int>(256);
            cliext::fill(nj->begin(),nj->end(),0);

            for(y=0; y<N; y++)
                for (x=0; x<M; x++)
                    nj[safe_cast<int>(Imagen[x,y])]++;

            for(k=1;k<256;k++)
                nj[k]+=nj[k-1];

            for (y=0; y<N; y++)
                for (x=0; x<M; x++)
                    AuxArray[x,y] = safe_cast<unsigned char>(255*nj[safe_cast<int>(Imagen[x,y])]/(M*N));

            return AuxArray;
        }

	private: cli::array<unsigned char, 2>^ Dilation (cli::array<unsigned char, 2>^ MatrizImagen)
		{
			cli::array<unsigned char, 2>^ structuringElement = {
					{120,120,120,120,120},
					{120,120,120,120,120},
					{120,120,120,120,120}

			};
			int M = MatrizImagen->GetLength(0);
			int N = MatrizImagen->GetLength(1);
			int m = structuringElement->GetLength(0);
			int n = structuringElement->GetLength(1);
			cli::array<double, 2>^ ImagenDilation = gcnew cli::array<double, 2>(M,N);
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			int x, y, i, j, a ,b, max;
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					max = 0;
					for(i=0; i<m; i++){
						for(j=0; j<n; j++){
							a=x+j-(n-1)/2;
							b=y+i-(m-1)/2;
							if((a>=0 && a<M) && (b>=0 && b<N) && max < safe_cast<int>(structuringElement[m-1-i,n-1-j]+MatrizImagen[a,b]))
							{
								ImagenDilation[x,y] = safe_cast<double>(structuringElement[m-1-i,n-1-j]+MatrizImagen[a,b]);
								max = safe_cast<int>(structuringElement[m-1-i,n-1-j]+MatrizImagen[a,b]);
							}
						}
					}
				}
			}
			double auxmax = ImagenDilation[0,0];
			double auxmin = ImagenDilation[0,0];
			for each(double aux in ImagenDilation){
				if(aux > auxmax)
					auxmax = aux;
				if(aux < auxmin)
					auxmin = aux;
			}
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					NewImArray[x,y]=safe_cast<unsigned char>((ImagenDilation[x,y]-auxmin)/(auxmax-auxmin)*255.0);
				}
			}
			return NewImArray;
		}

	private: cli::array<unsigned char, 2>^ DilationBinaria (cli::array<unsigned char, 2>^ Imagen)
		{
			cli::array<unsigned char, 2>^ structuringElement = {
					{255,255,255},
					{255,255,255},
					{255,255,255}																		};
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			int m = structuringElement->GetLength(0); // filas
			int n = structuringElement->GetLength(1); // columnas
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			int x, y, i, j, a ,b;
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					NewImArray[x,y]=0;
					i=0;
					while(i<m && NewImArray[x,y]==0){
						j=0;
						while(j<n && NewImArray[x,y]==0){
							a=x+j-(n-1)/2;
							b=y+i-(m-1)/2;
							if((a>=0 && a<M) && (b>=0 && b<N))
								if (structuringElement[i,j]==255)
									if (Imagen[a,b]==255)
										NewImArray[x,y]=255;
							j++;
						}
						i++;
					}
				}
			}
			return NewImArray;
		}

	private: cli::array<unsigned char, 2>^ Erosion (cli::array<unsigned char, 2>^ MatrizImagen)
		{
			cli::array<unsigned char, 2>^ structuringElement = {
					{120,120,120,120,120},
					{120,120,120,120,120},
					{120,120,120,120,120}
			};
			int M = MatrizImagen->GetLength(0);
			int N = MatrizImagen->GetLength(1);
			int m = structuringElement->GetLength(0);
			int n = structuringElement->GetLength(1);
			cli::array<double, 2>^ ImagenErosion = gcnew cli::array<double, 2>(M,N);
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			int x, y, i, j, a ,b, min;
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					min = 255;
					for(i=0; i<m; i++){
						for(j=0; j<n; j++){
							a=x+j-(n-1)/2;
							b=y+i-(m-1)/2;
							if((a>=0 && a<M) && (b>=0 && b<N) && min > safe_cast<int>(MatrizImagen[a,b]-structuringElement[i,j]))
							{
								ImagenErosion[x,y] = safe_cast<double>(MatrizImagen[a,b]-structuringElement[i,j]);
								min = safe_cast<int>(MatrizImagen[a,b]-structuringElement[i,j]);
							}
						}
					}
				}
			}
			double auxmax = ImagenErosion[0,0];
			double auxmin = ImagenErosion[0,0];
			for each(double aux in ImagenErosion){
				if(aux > auxmax)
					auxmax = aux;
				if(aux < auxmin)
					auxmin = aux;
			}
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					NewImArray[x,y]=safe_cast<unsigned char>((ImagenErosion[x,y]-auxmin)/(auxmax-auxmin)*255.0);
				}
			}
			return NewImArray;
		}

	private: cli::array<unsigned char, 2>^ ErosionBinaria (cli::array<unsigned char, 2>^ Imagen)
		{
			cli::array<unsigned char, 2>^ structuringElement = {
					{255,255,255},
					{255,255,255},
					{255,255,255}
			};
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			int m = structuringElement->GetLength(0); // filas
			int n = structuringElement->GetLength(1); // columnas
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			int x, y, i, j, a ,b;
			for(y=0; y<N; y++){
				for(x=0; x<M; x++){
					NewImArray[x,y]=255;
					i=0;
					while(i<m && NewImArray[x,y]==255){
						j=0;
						while(j<n && NewImArray[x,y]==255){
							a=x+j-(n-1)/2;
							b=y+i-(m-1)/2;
							if((a>=0 && a<M) && (b>=0 && b<N))
								if (structuringElement[i,j]==255)
									if (Imagen[a,b]==0)
										NewImArray[x,y]=0;
							j++;
						}
						i++;
					}
				}
			}
			return NewImArray;
		}

	private: void Unir (cliext::vector<int>^ etiquetas, int padre1, int padre2)
		{
			int i=0;
			for each (int aux in etiquetas)
			{
				if (padre1<padre2 && aux==padre2)
					etiquetas[i] = padre1;
				if (padre2<padre1 && aux==padre1)
					etiquetas[i] = padre2;
				i++;
			}
		}

	private: cli::array<unsigned char, 2>^ ExtraerRegionesD4 (cli::array<unsigned char, 2>^ Imagen)
		{
			int x, y;
			int i=0;
			int etiq = 0;
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);
			cliext::vector<int>^ etiquetas = gcnew cliext::vector<int>(M*N);
			cliext::fill(etiquetas->begin(), etiquetas->end(), 0);
			if (Imagen[0,0]==255)
			{
				etiq++;
				etiquetas[i]=etiq;
			}
			i++;
			for (x=1; x<M; x++)
			{
				if (Imagen[x,0]==255)
				{

					if(Imagen[x,0]==Imagen[x-1,0])
					{
						etiquetas[i]=etiquetas[i-1];
					}
					else
					{
						etiq++;
						etiquetas[i]=etiq;
					}
				}
				i++;
			}
			for (y=1; y<N; y++)
			{
				for (x=0; x<M; x++)
				{
					if (Imagen[x,y]==255)
					{
						if (x==0)
						{
							if (Imagen[x,y-1]==255)
							{
								etiquetas[i]=etiquetas[i-M];
							}
						}
						else
						{
							if (Imagen[x-1,y]==255)
							{
								etiquetas[i]=etiquetas[i-1];
							}
							if (Imagen[x,y-1]==255)
							{
								if (Imagen[x-1,y]==255 && etiquetas[i]!=etiquetas[(y-1)*M+x])
								{
									Unir(etiquetas, etiquetas[(y-1)*M+x], etiquetas[i]);
								}
								else
								{
									etiquetas[i]=etiquetas[i-M];
								}
							}
							if (Imagen[x-1,y]==0 && Imagen[x,y-1]==0)
							{
								etiq++;
								etiquetas[i]=etiq;
							}
						}
					}
					i++;
				}
			}
			cliext::vector<Estructuras::Clasificador^>^ etiqclasif = gcnew cliext::vector<Estructuras::Clasificador^>();
			int j=0;
			int k;
			int c;
			for each (int aux in etiquetas)
			{
				if(aux!=0)
				{
					if (j>0)
					{
						c=0;
						for (k=0; k<j; k++)
						{
							if (aux!=etiqclasif[k]->a)
								c++;
							else
								etiqclasif[k]->b++;
							if (c==j)
							{
								Estructuras::Clasificador^ elemento = gcnew Estructuras::Clasificador();
								elemento->a=aux;
								elemento->b++;
								etiqclasif->push_back(elemento);
								j++;
							}
						}
					}
					if(j==0)
					{
						Estructuras::Clasificador^ elemento = gcnew Estructuras::Clasificador();
						elemento->a=aux;
						elemento->b++;
						etiqclasif->push_back(elemento);
						j++;
					}
				}
			}
			int m=0;
			for each (Estructuras::Clasificador^ elemento in etiqclasif)
			{
				if (elemento->b < 50 || elemento->b > 5000)
				{
					m++;
					for(x=0; x<M*N; x++)
					{
						if (etiquetas[x]==elemento->a)
						{
							etiquetas[x]=0;
						}
					}
				}
			}
			this->toolStripStatusLabel1->Text = L"Cantidad de elementos conectados = "+j+L"   Cantidad de elementos significativos = "+(j-m);
			if ((j-m)>0)
			{
				for (y=0; y<N; y++)
					for (x=0; x<M; x++)
						AuxArray[x,y] = safe_cast<unsigned char>(255/(j-m)*etiquetas[x+y*M]);
			}
			return AuxArray;
		}

	private: cli::array<unsigned char, 2>^ ExtraerRegionesD8 (cli::array<unsigned char, 2>^ Imagen)
		{
			int x, y;
			int i=0;
			int etiq = 0;
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);
			etiquetas = gcnew cliext::vector<int>(M*N);
			cliext::fill(etiquetas->begin(), etiquetas->end(), 0);
			if (Imagen[0,0]==255)
			{
				etiq++;
				etiquetas[i]=etiq;
			}
			i++;
			for (x=1; x<M; x++)
			{
				if (Imagen[x,0]==255)
				{

					if(Imagen[x,0]==Imagen[x-1,0])
					{
						etiquetas[i]=etiquetas[i-1];
					}
					else
					{
						etiq++;
						etiquetas[i]=etiq;
					}
				}
				i++;
			}
			for (y=1; y<N; y++)
			{
				for (x=0; x<M; x++)
				{
					if (Imagen[x,y]==255)
					{
						if (x==0)
						{
							if (Imagen[x,y-1]==255)
							{
								etiquetas[i]=etiquetas[i-M];
							}
						}
						else
						{
							if (Imagen[x-1,y]==255)
							{
								etiquetas[i]=etiquetas[i-1];
							}
							if (Imagen[x,y-1]==255)
							{
								if (Imagen[x-1,y]==255 && etiquetas[i]!=etiquetas[(y-1)*M+x])
								{
									Unir(etiquetas, etiquetas[(y-1)*M+x], etiquetas[i]);
								}
								else
								{
									etiquetas[i]=etiquetas[i-M];
								}
							}
							if (Imagen[x-1,y]==0 && Imagen[x,y-1]==0)
							{
								if (Imagen[x-1,y-1]==255)
								{
									etiquetas[i] = etiquetas[(y-1)*M+x-1];
								}
								else
								{
								etiq++;
								etiquetas[i]=etiq;
								}
							}
						}
					}
					else
					{
						if(x!=0)
						{
							if (Imagen[x-1,y]==255 && Imagen[x,y-1] == 255)
							{
								Unir(etiquetas, etiquetas[(y-1)*M+x], etiquetas[i-1]);
							}
						}
					}
					i++;
				}
			}
			etiqclasif = gcnew cliext::vector<Estructuras::Clasificador^>();
			int j=0;
			int k;
			int c;
			int q;
			for (q=0; q<M*N; q++)
			{
				if(etiquetas[q]!=0)
				{
					if (j>0)
					{
						c=0;
						for (k=0; k<j; k++)
						{
							if (etiquetas[q]!=etiqclasif[k]->a)
								c++;
							else
							{
								etiqclasif[k]->b++;
								etiqclasif[k]->ymax=(q-q%M)/M; etiqclasif[k]->Xymax=q%M;
								if (q%M<etiqclasif[k]->xmin)
								{
									etiqclasif[k]->xmin=q%M; etiqclasif[k]->Yxmin=(q-q%M)/M;
								}
								if (q%M>etiqclasif[k]->xmax)
								{
									etiqclasif[k]->xmax=q%M; etiqclasif[k]->Yxmax=(q-q%M)/M;
								}
							}

							if (c==j)
							{
								Estructuras::Clasificador^ elemento = gcnew Estructuras::Clasificador();
								elemento->a=etiquetas[q];
								elemento->b++;
								elemento->ymin=(q-q%M)/M; elemento->Xymin=q%M;
								elemento->xmin=q%M;
								elemento->xmax=q%M;
								etiqclasif->push_back(elemento);
								j++;
							}
						}
					}
					else
					{
						Estructuras::Clasificador^ elemento = gcnew Estructuras::Clasificador();
						elemento->a=etiquetas[q];
						elemento->b++;
						elemento->ymin=(q-q%M)/M;
						elemento->xmin=q%M;
						elemento->xmax=q%M;
						etiqclasif->push_back(elemento);
						j++;
					}
				}
			}
			this->toolStripStatusLabel1->Text = L"Cantidad de elementos conectados = "+j;//+L"   Cantidad de elementos significativos = "+(j-m);
			cantelemconec=j;
			for (y=0; y<N; y++)
				for (x=0; x<M; x++)
					if(etiquetas[x+y*M]>0)
						AuxArray[x,y] = 255;
			return AuxArray;
		}

	private: System::Void Op1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
				 operando1 = V->MatrizImagen;
			 }
		}

	private: System::Void Op2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
				 operando2 = V->MatrizImagen;
			 }
		}
	private: System::Void BotonDilation_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			if (V != nullptr && V->aColores == false && V->tienetresholding == false)
			{
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = Dilation(V->MatrizImagen);
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
			}
			if (V != nullptr && V->tienetresholding == true)
			{
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = DilationBinaria(V->MatrizImagen);
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->tienetresholding=true;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
			}
		}

	private: System::Void BotonErosion_Click(System::Object^  sender, System::EventArgs^  e) {
			ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			if (V != nullptr && V->aColores == false && V->tienetresholding == false)
			{
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = Erosion(V->MatrizImagen);
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
			}
			if (V != nullptr && V->tienetresholding == true)
			{
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = ErosionBinaria(V->MatrizImagen);
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->tienetresholding=true;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
			}
		}

	private: System::Void Resta_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (operando1 != nullptr && operando2 != nullptr)
			{
				 int x, y;
				 int M = operando1->GetLength(0);
				 int N = operando1->GetLength(1);
				 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(operando1->GetLength(0),operando1->GetLength(1));
				 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(operando1->GetLength(0),operando1->GetLength(1));
				 for (x=0;x<M;x++)
				 {
					 for (y=0;y<N;y++)
					 {
						 AuxArray[x,y] = safe_cast<double>(operando1[x,y] - operando2[x,y]);
					 }
				 }
				 double auxmax = AuxArray[0,0];
				 double auxmin = AuxArray[0,0];
				 for each(double aux in AuxArray){
					 if(aux > auxmax)
						 auxmax = aux;
					 if(aux < auxmin)
						 auxmin = aux;
				 }
				 for(y=0; y<N; y++){
					 for(x=0; x<M; x++){
						 NewImArray[x,y]=safe_cast<unsigned char>((AuxArray[x,y]-auxmin)/(auxmax-auxmin)*255.0);
					 }
				 }
		 		 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();	
			}
		}

	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 if (operando1 != nullptr && operando2 != nullptr)
			 {
				 int x, y;
				 int M = operando1->GetLength(0);
				 int N = operando1->GetLength(1);
				 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(operando1->GetLength(0),operando1->GetLength(1));
				 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(operando1->GetLength(0),operando1->GetLength(1));
				 for (x=0;x<M;x++)
				 {
					 for (y=0;y<N;y++)
					 {
						 AuxArray[x,y] = safe_cast<double>(operando1[x,y] + operando2[x,y]);
					 }
				 }
				 double auxmax = AuxArray[0,0];
				 double auxmin = AuxArray[0,0];
				 for each(double aux in AuxArray){
					 if(aux > auxmax)
						 auxmax = aux;
					 if(aux < auxmin)
						 auxmin = aux;
				 }
				 for(y=0; y<N; y++){
					 for(x=0; x<M; x++){
						 NewImArray[x,y]=safe_cast<unsigned char>((AuxArray[x,y]-auxmin)/(auxmax-auxmin)*255.0);
					 }
				 }
		 		 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();
			 }
		}

	private: System::Void Regiones_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = ExtraerRegionesD8(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: cli::array<int, 2>^ AplicarMexicanINT (cli::array<unsigned char, 2> ^ ImArray)
		{
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 cli::array<int, 2>^ MaskArray = { 
				 {0,0,-1,0,0},
				 {0,-1,-2,-1,0},
				 {-1,-2,19,-2,-1},
				 {0,-1,-2,-1,0},
				 {0,0,-1,0,0} };
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 cli::array<int, 2>^ NewImArray = gcnew cli::array<int, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 NewImArray[x,y]+=safe_cast<int>(ImArray[a,b])*MaskArray[i,j];
						 }
					 }
				 }
			 }
			 return NewImArray;
		}


	private: cli::array<unsigned char, 2>^ AplicarMexican (cli::array<unsigned char, 2> ^ ImArray)
		{
			 int M = ImArray->GetLength(0);
			 int N = ImArray->GetLength(1);
			 cli::array<double, 2>^ MaskArray = { 
				 {0.0,0.0,-1.0,0.0,0.0},
				 {0.0,-1.0,-2.0,-1.0,0.0},
				 {-1.0,-2.0,16.0,-2.0,-1.0},
				 {0.0,-1.0,-2.0,-1.0,0.0},
				 {0.0,0.0,-1.0,0.0,0.0} };
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			 cli::array<double, 2>^ AuxArray = gcnew cli::array<double, 2>(M,N);
			 int x, y, i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 AuxArray[x,y]=0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 AuxArray[x,y]+=safe_cast<double>(MaskArray[i,j]*ImArray[a,b]);
						 }
					 }
				 }
			 }
			 double auxmax = AuxArray[0,0];
			 double auxmin = AuxArray[0,0];
			 for each(double aux in AuxArray){
				 if(aux > auxmax)
					 auxmax = aux;
				 if(aux < auxmin)
					 auxmin = aux;
			 }
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=safe_cast<unsigned char>((AuxArray[x,y]-auxmin)/(auxmax-auxmin)*255.0);
				 }
			 }
			 return NewImArray;
		}

	private: System::Void mexicanHatToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = AplicarMexican(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: System::Void thresholdToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = Threshold(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: System::Void threshold2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = Threshold2(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->tienetresholding=true;		
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: System::Void Ecualizar_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = Ecualizacion(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		 }

	private: System::Void guardarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 System::Windows::Forms::SaveFileDialog^ save = gcnew System::Windows::Forms::SaveFileDialog();
			 VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
			 if(V!=nullptr)
			 {
				try{
					save->ShowDialog();
					V->Imagen->Save(save->FileName);
			 	}
				catch(System::Exception ^ex){}
			 }
		}

	private: System::Void RegSignificativas_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
				int M = V->MatrizImagen->GetLength(0);
				int N = V->MatrizImagen->GetLength(1);


				cliext::vector<int>^ raices = gcnew cliext::vector<int>();
				cliext::vector<int>^ sumadepixeles = gcnew cliext::vector<int>();
				for each (Blob^ blob in blobs)
				{
					raices->push_back(blob->parent);
					sumadepixeles->push_back(blob->pixeles);
				}
				raiz--;
				int i, r;
				for (i=raiz; i>=0; i--)
				{
					r=i;
					while(raices[r]!=r)
						r = raices[r];
					if(r!=i)
						sumadepixeles[r]+=sumadepixeles[i];
					raices[i]=r;
				}
				for (i=0; i<=raiz; i++)
				{
					if (raices[i]==i)
					{
						if (sumadepixeles[i]<50 || sumadepixeles[i]>5000)
						{
							sumadepixeles[i]=0;
						}
					}
				}
				cliext::vector<cliext::list<Estructuras::Run^>^>^ significativos = gcnew cliext::vector<cliext::list<Estructuras::Run^>^>();
				cliext::vector<cli::array<int>^>^ correspondencias = gcnew cliext::vector<cli::array<int>^>();
				i=0;
				int indice=0;
				int ind;
				bool existecorrespondencia;
				for each (Blob^ blob in blobs)
				{
					int raizactual = raices[i];
					if(sumadepixeles[raizactual]!=0)
					{
						existecorrespondencia=false;
						for each (cli::array<int>^ correspondencia in correspondencias)
						{
							if (correspondencia[0]==raizactual)
							{
								ind=correspondencia[1];
								existecorrespondencia=true;
								break;
							}
						}
						if(existecorrespondencia)
						{
							significativos[ind]->insert(significativos[ind]->end(),blob->listaderuns->begin(), blob->listaderuns->end());
						}
						else
						{
							significativos->push_back(blob->listaderuns);
							cli::array<int>^ correspondencia = {raizactual, indice, sumadepixeles[raizactual]};
							correspondencias->push_back(correspondencia);
							indice++;
						}
					}
					i++;
				}
				int x;
				int l=0;
				probables = gcnew cliext::vector<Estructuras::Probable^>();
				for each (cliext::list<Run^>^ listaderuns in significativos)
				{
					cliext::list<Run^>::iterator iter = listaderuns->begin();
					Estructuras::Probable^ probable = gcnew Estructuras::Probable();
					probable->xmin=iter->c1;
					probable->Yxmin=iter->r;
					probable->ymin=iter->r;
					probable->Xymin=iter->c1;
					probable->xmax=iter->c2;
					probable->Yxmax=iter->r;
					probable->ymax=iter->r;
					probable->Xymax=iter->c1;
					probable->largo=iter->c2-iter->c1+1;
					probable->ancho=1;
					for(iter=listaderuns->begin(); iter!=listaderuns->end(); iter++)
					{
						if (iter->r>probable->ymax)
						{
							probable->ymax=iter->r;
							probable->Xymax=iter->c1;
							probable->ancho=iter->r-probable->ymin+1;
						}
						if (iter->r<probable->ymin)
						{
							probable->ymin=iter->r;
							probable->Xymin=iter->c1;
							probable->ancho=iter->r-probable->ymin+1;
						}
						if (iter->c2>probable->xmax)
						{
							probable->xmax=iter->c2;
							probable->Yxmax=iter->r;
							probable->largo=iter->c2-probable->xmin+1;
						}
						if (iter->c1<probable->xmin)
						{
							probable->xmin=iter->c1;
							probable->Yxmin=iter->r;
							probable->largo=probable->xmax-iter->c1+1;
						}
					}
					probable->x0=probable->xmax-probable->largo+1;
					probable->y0=probable->ymax-probable->ancho+1;
					probable->area=correspondencias[l][2];
					l++;
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(probable->largo, probable->ancho);
					for each (Estructuras::Run^ run in listaderuns)
						for(x=run->c1;x<=run->c2;x++)
							regionaux[x-probable->xmin,run->r-probable->y0]=255;
					probable->region = regionaux;
					probables->push_back(probable);
				}
				// Lo siguiente es solo para visualizar los resultados parciales
				cantelemsig=indice;
				cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
				for each (cliext::list<Run^>^ listaderuns in significativos)
					for each (Estructuras::Run^ run in listaderuns)
						for(x=run->c1;x<=run->c2;x++)
							NewImArray[x,run->r]=255;
				 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->tienetresholding=true;
				 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos significativos = " + cantelemsig;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();
			}
		}

	private: System::Void Contenedores_Click(System::Object^  sender, System::EventArgs^  e)
		{
 			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
				 	int M = V->MatrizImagen->GetLength(0);
					int N = V->MatrizImagen->GetLength(1);
					int m=0;
					int n=cantelemsig;
					int indice=0;
					double ratiochapa=2.0;
					double inversaratiochapa=1.0/ratiochapa;
					while (n!=0)
					{
						if ((probables[indice]->ancho)==1 || (probables[indice]->largo)==1)
							{
								m++;
								probables->erase(probables->begin()+indice);
								indice--;

							}
							else
							{
								double ratioaux=safe_cast<double>(probables[indice]->largo)/safe_cast<double>(probables[indice]->ancho);
								if (ratioaux<0.8*inversaratiochapa || ratioaux>1.2*ratiochapa)
								{
									m++;
									probables->erase(probables->begin()+indice);
									indice--;
								}
							}
							indice++;
							n--;
					}
					cantcont=cantelemsig-m;
					// lo sgte es sola para visualizar
					int x, y;
					cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
					for each (Estructuras::Probable^ probable in probables)
						for (y=probable->y0; y<=probable->ymax; y++)
							for (x=probable->x0; x<=probable->xmax; x++)
								NewImArray[x,y]+=probable->region[x-probable->x0,y-probable->y0];
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de contenedores = " + cantcont;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: System::Void Excentricidad_Click(System::Object^  sender, System::EventArgs^  e)
		{
 			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
					int M = V->MatrizImagen->GetLength(0);
					int N = V->MatrizImagen->GetLength(1);					

					int m=0;
					int n=cantcont;
					int indice=0;
					double ratiochapa=2.0;
					double inversaratiochapa=1.0/ratiochapa;
					while (n!=0)
					{
						double ratioaux=safe_cast<double>(probables[indice]->largo)/safe_cast<double>(probables[indice]->ancho);
						if (ratioaux<1.7734375 && ratioaux>0.5625)
						{
							double lado1=safe_cast<double>((probables[indice]->ymin-probables[indice]->Yxmax)*(probables[indice]->ymin-probables[indice]->Yxmax)+(probables[indice]->xmax-probables[indice]->Xymin)*(probables[indice]->xmax-probables[indice]->Xymin));
							double lado2=safe_cast<double>((probables[indice]->Yxmax-probables[indice]->ymax)*(probables[indice]->Yxmax-probables[indice]->ymax)+(probables[indice]->xmax-probables[indice]->Xymax)*(probables[indice]->xmax-probables[indice]->Xymax));
							double lado3=safe_cast<double>((probables[indice]->Xymax-probables[indice]->xmin)*(probables[indice]->Xymax-probables[indice]->xmin)+(probables[indice]->ymax-probables[indice]->Yxmin)*(probables[indice]->ymax-probables[indice]->Yxmin));
							double lado4=safe_cast<double>((probables[indice]->Yxmin-probables[indice]->ymin)*(probables[indice]->Yxmin-probables[indice]->ymin)+(probables[indice]->Xymin-probables[indice]->xmin)*(probables[indice]->Xymin-probables[indice]->xmin));
							double relacion13=lado1/lado3;
							double relacion24=lado2/lado4; 
							double excentricidad;
							if (lado1>lado2)
								excentricidad=System::Math::Sqrt(lado1/lado2);
							else
								excentricidad=System::Math::Sqrt(lado2/lado1);

							if (excentricidad<0.8*ratiochapa || excentricidad>1.2*ratiochapa || relacion13>1.21 || relacion13<0.81 || relacion24>1.21 || relacion24<0.81)
							{
								m++;
								probables->erase(probables->begin()+indice);
								indice--;
							}
						}												
						indice++;
						n--;
					}
					cantexc=cantcont-m;
				     // lo sgte es sola para visualizar
					int x, y;
					cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					for each (Estructuras::Probable^ probable in probables)
						for (y=probable->y0; y<=probable->ymax; y++)
							for (x=probable->x0; x<=probable->xmax; x++)
								NewImArray[x,y]+=probable->region[x-probable->x0,y-probable->y0];
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->toolStripStatusLabel1->Text = L"Cantidad con excentricidad = " + cantexc;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
		}

	private: System::Void Letras_Click(System::Object^  sender, System::EventArgs^  e)
		{
			for each (Probable^ probable in probables)
			{
				int x,y;
				int bandera=0;
				raiz=0;
				int nroblob, raiznueva;
				int M = probable->region->GetLength(0);
				int N = probable->region->GetLength(1);
				blobs = gcnew cliext::list<Blob^>();

				 int principio, fin;
				 for (y=0; y<N; y++)
				 {
					 principio = fin = 0;
					 x=0;
					 while (x<M)
					 {
						 if (probable->region[x,y]==255)
						 {
							 principio=x;
							 break;
						 }
						 x++;
					 }
					 x=M;
					 while (x!=0)
					 {
						 if (probable->region[x-1,y]==255)
						 {
							 fin=x-1;
							 break;
						 }
						 x--;
					 }
					 for (x=principio; x<=fin; x++)
					 {
						 if (probable->region[x,y]==0)
							 probable->region[x,y]=255;
						 else
							 probable->region[x,y]=0;
					 }
				 }
				y=0;
				while (y<N && bandera==0)
				{
					x=0;
					while(x<M)
					{
						if (probable->region[x,y]==255)
						{
							Estructuras::Run^ run = gcnew Estructuras::Run();
							run->r=y;
							run->c1=x;
							if(x<M-1)
							{
								while(probable->region[x+1,y]==255)
								{
									x++;
									if(x==M-1)
										break;
								}
							}
							run->c2=x;
							x++;
							Blob^ blob = gcnew Blob();
							blob->parent = raiz;
							raiz++;
							blob->pixeles=run->c2-run->c1+1;
							blob->listaderuns = gcnew cliext::list<Run^>();
							blob->listaderuns->push_back(run);
							blobs->push_back(blob);
							bandera=1;
						}
						x++;
					}
					y++;
				}
				if(y<=N-1)
				{
					while (y<N)
					{
						x=0;
						while(x<M)
						{
							if (probable->region[x,y]==255)
							{
								Estructuras::Run^ run = gcnew Estructuras::Run();
								run->r=y;
								run->c1=x;
								if(x<M-1)
								{
									while(probable->region[x+1,y]==255)
									{
										x++;
										if(x==M-1)
											break;
									}
								}
								run->c2=x;
								x++;
								bandera=0;
								nroblob=0;
								for each (Blob^ blob in blobs)
								{
									cliext::list<Estructuras::Run^>::iterator iter = blob->listaderuns->end();
									iter--;
									while (iter->r>=(y-1))
									{
										if ((run->c1<iter->c1 && (run->c2+1)>=iter->c1) || (run->c1>=iter->c1 && (run->c1-1)<=iter->c2)) // D8
										{
											if (bandera==0)
											{
												blob->listaderuns->push_back(run);
												blob->pixeles+=run->c2-run->c1+1;
												raiznueva=blob->parent;
												bandera=1;
											}
											if (bandera==1)
											{
												blob->parent=raiznueva;
											}
										}
										if(iter!=blob->listaderuns->begin())
										iter--;
										else
											break;
									}
									nroblob++;
								}
								if (bandera==0)
								{
									Blob^ blobnuevo = gcnew Blob();
									blobnuevo->parent = raiz;
									raiz++;
									blobnuevo->pixeles=run->c2-run->c1+1;
									blobnuevo->listaderuns = gcnew cliext::list<Run^>();
									blobnuevo->listaderuns->push_back(run);
									blobs->push_back(blobnuevo);
								}
							}
							x++;
						}
						y++;
					}
				}
				cliext::vector<int>^ raices = gcnew cliext::vector<int>();
				cliext::vector<int>^ sumadepixeles = gcnew cliext::vector<int>();
				for each (Blob^ blob in blobs)
				{
					raices->push_back(blob->parent);
					sumadepixeles->push_back(blob->pixeles);
				}
				raiz--;
				int i, r;
				for (i=raiz; i>=0; i--)
				{
					r=i;
					while(raices[r]!=r)
						r = raices[r];
					if(r!=i)
						sumadepixeles[r]+=sumadepixeles[i];
					raices[i]=r;
				}
				for (i=0; i<=raiz; i++)
				{
					if (raices[i]==i)
					{
						if (sumadepixeles[i]<safe_cast<int>(0.9*0.016*safe_cast<double>(probable->area)) || sumadepixeles[i]>safe_cast<int>(1.2*0.032*2*safe_cast<double>(probable->area)))
						{
							sumadepixeles[i]=0;
						}
					}
				}
				cliext::vector<cliext::list<Estructuras::Run^>^>^ significativos = gcnew cliext::vector<cliext::list<Estructuras::Run^>^>();
				cliext::vector<cli::array<int>^>^ correspondencias = gcnew cliext::vector<cli::array<int>^>();
				i=0;
				int indice=0;
				int ind;
				bool existecorrespondencia;
				for each (Blob^ blob in blobs)
				{
					int raizactual = raices[i];
					if(sumadepixeles[raizactual]!=0)
					{
						existecorrespondencia=false;
						for each (cli::array<int>^ correspondencia in correspondencias)
						{
							if (correspondencia[0]==raizactual)
							{
								ind=correspondencia[1];
								existecorrespondencia=true;
								break;
							}
						}
						if(existecorrespondencia)
						{
							significativos[ind]->insert(significativos[ind]->end(),blob->listaderuns->begin(), blob->listaderuns->end());
						}
						else
						{
							significativos->push_back(blob->listaderuns);
							cli::array<int>^ correspondencia = {raizactual, indice, sumadepixeles[raizactual]};
							correspondencias->push_back(correspondencia);
							indice++;
						}
					}
					i++;
				}
				int l=0;
				cliext::vector<Estructuras::Letras^>^ lasletrasaux = gcnew cliext::vector<Estructuras::Letras^>();
				probable->lasletras = lasletrasaux;
				for each (cliext::list<Run^>^ listaderuns in significativos)
				{
					cliext::list<Run^>::iterator iter = listaderuns->begin();
					Estructuras::Letras^ letra = gcnew Estructuras::Letras();
					letra->xmin=iter->c1;
					letra->ymin=iter->r;
					letra->xmax=iter->c2;
					letra->ymax=iter->r;
					letra->largo=iter->c2-iter->c1+1;
					letra->ancho=1;
					for(iter=listaderuns->begin(); iter!=listaderuns->end(); iter++)
					{
						if (iter->r>letra->ymax)
						{
							letra->ymax=iter->r;
							letra->ancho=iter->r-letra->ymin+1;
						}
						if (iter->r<letra->ymin)
						{
							letra->ymin=iter->r;
							letra->ancho=iter->r-letra->ymin+1;
						}
						if (iter->c2>letra->xmax)
						{
							letra->xmax=iter->c2;
							letra->largo=iter->c2-letra->xmin+1;
						}
						if (iter->c1<letra->xmin)
						{
							letra->xmin=iter->c1;
							letra->largo=letra->xmax-iter->c1+1;
						}
					}
					letra->x0=letra->xmax-letra->largo+1;
					letra->y0=letra->ymax-letra->ancho+1;
					letra->area=correspondencias[l][2];
					l++;
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(letra->largo, letra->ancho);
					for each (Estructuras::Run^ run in listaderuns)
						for(x=run->c1;x<=run->c2;x++)
							regionaux[x-letra->xmin,run->r-letra->y0]=255;
					letra->region = regionaux;
					probable->lasletras->push_back(letra);
				}
			}
			for each (Probable^ probable in probables)
			{
				double ratiochapa=2.0;
				double invratiochapa=1.0/ratiochapa;
				double ratioaux=safe_cast<double>(probable->largo)/safe_cast<double>(probable->ancho);
				if (ratioaux<1.875 && ratioaux>0.5625)
				{
					double tetha=System::Math::Atan(invratiochapa*safe_cast<double>(probable->largo)/safe_cast<double>(probable->ancho)-1.0)/(invratiochapa-safe_cast<double>(probable->largo)/safe_cast<double>(probable->ancho));
					for each (Estructuras::Letras^ letra in probable->lasletras)
					{
						double ratioletramin = 1.2;
						double ratioletramax = 19.0;
						double msobren = safe_cast<double>(letra->largo)/safe_cast<double>(letra->ancho);
						double bsobrea = System::Math::Abs((1.0-msobren*System::Math::Tan(tetha))/(msobren-System::Math::Tan(tetha)));
						if (bsobrea>ratioletramin*0.8 && bsobrea<ratioletramax*1.2 && letra->area)
						{
							probable->nroletras++;
						}
					}
				}
				if (ratioaux>=1.875)
				{
					for each (Estructuras::Letras^ letra in probable->lasletras)
					{
						double ratioletramin = 1.2;
						double ratioletramax = 19.0;
						double msobren = safe_cast<double>(letra->ancho)/safe_cast<double>(letra->largo);
						if (msobren>ratioletramin*0.8 && msobren<ratioletramax*1.2&& letra->y0>=safe_cast<int>(0.8*0.4*probable->ancho) && letra->y0<=safe_cast<int>(1.2*0.4*probable->ancho))
						{
							probable->nroletras++;
						}
					}
				}
				if (ratioaux<=0.5625)
				{
					for each (Estructuras::Letras^ letra in probable->lasletras)
					{
						double ratioletramin = 1.2;
						double ratioletramax = 19.0;
						double msobren = safe_cast<double>(letra->largo)/safe_cast<double>(letra->ancho);
						if (msobren>ratioletramin*0.8 && msobren<ratioletramax*1.2 && letra->x0>=safe_cast<int>(0.8*0.4*probable->largo) && letra->x0<=safe_cast<int>(1.2*0.4*probable->largo))
						{
							probable->nroletras++;
						}
					}
				}

				if(probable->nroletras>2 && probable->nroletras<9)
				{
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = probable->region;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de letras = " + probable->nroletras;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();
				}
			}
		}

	private: System::Void Areas_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {

				 for each (Estructuras::Probable^ probable in probables)
				 {
					 int x, y;
					 int principio, fin;
					 int relleno=0;
					 int M = probable->region->GetLength(0);
					 int N = probable->region->GetLength(1);
					 for (y=0; y<N; y++)
					 {
						 principio = fin = 0;
						 x=0;
						 while (x<M)
						 {
							 if (probable->region[x,y]==255)
							 {
								 principio=x;
								 break;
							 }
							 x++;
						 }
						 x=M;
						 while (x!=0)
						 {
							 if (probable->region[x-1,y]==255)
							 {
								 fin=x-1;
								 break;
							 }
							 x--;
						 }
						 if (fin>(principio+1))
						 {
							 for (x=principio+1; x<fin; x++)
							 {
								 if (probable->region[x,y]==0)
									 relleno++;
							 }
						 }
					 }
					 probable->area+=relleno;
				 }
				int m=0;
				int n=cantexc;
				int indice=0;
				while (n!=0)
				{
					int M = probables[indice]->region->GetLength(0);
					int N = probables[indice]->region->GetLength(1);
					double ratioaux=safe_cast<double>(probables[indice]->largo)/safe_cast<double>(probables[indice]->ancho);
					if (ratioaux<1.875 && ratioaux>0.5625)
					{
						int areatotal = probables[indice]->area
										+(probables[indice]->ymax-probables[indice]->Yxmax)*(probables[indice]->xmax-probables[indice]->Xymax)
										+(probables[indice]->ymax-probables[indice]->Yxmin)*(probables[indice]->Xymax-probables[indice]->xmin);
							if (areatotal<0.8*M*N || areatotal>1.2*M*N)
							{
								m++;
								probables->erase(probables->begin()+indice);
								indice--;
							}
					}
					else
					{
							int areatotal = probables[indice]->area;
							if (areatotal<0.8*M*N || areatotal>1.2*M*N)
							{
								m++;
								probables->erase(probables->begin()+indice);
								indice--;
							}
					}
					indice++;
					n--;
				}

				cantarea=cantexc-m;
				// lo sgte es sola para visualizar
				int x, y;
				cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
				for each (Estructuras::Probable^ probable in probables)
					for (y=probable->y0; y<=probable->ymax; y++)
						for (x=probable->x0; x<=probable->xmax; x++)
							NewImArray[x,y]+=probable->region[x-probable->x0,y-probable->y0];
				 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->tienetresholding=true;
				 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de areas = " + cantarea;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();
			 }
		}

	private: cli::array<unsigned char, 2>^ ExtraccionRapida(cli::array<unsigned char, 2>^Imagen)
		{
			int x,y;
			int bandera=0;
			raiz=0;
			int nroblob, raiznueva;
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			blobs = gcnew cliext::list<Blob^>();
			y=0;
			while (y<N && bandera==0)
			{
				x=0;
				while(x<M)
				{
					if (Imagen[x,y]==255)
					{
						Estructuras::Run^ run = gcnew Estructuras::Run();
						run->r=y;
						run->c1=x;
						if(x<M-1)
						{
							while(Imagen[x+1,y]==255)
							{
								x++;
								if(x==M-1)
									break;
							}
						}
						run->c2=x;
						x++;
						Blob^ blob = gcnew Blob();
						blob->parent = raiz;
						raiz++;
						blob->pixeles=run->c2-run->c1+1;
						blob->listaderuns = gcnew cliext::list<Run^>();
						blob->listaderuns->push_back(run);
						blobs->push_back(blob);
						bandera=1;
					}
					x++;
				}
				y++;
			}
			if(y<=N-1)
			{
				while (y<N)
				{
					x=0;
					while(x<M)
					{
						if (Imagen[x,y]==255)
						{
							Estructuras::Run^ run = gcnew Estructuras::Run();
							run->r=y;
							run->c1=x;
							if(x<M-1)
							{
								while(Imagen[x+1,y]==255)
								{
									x++;
									if(x==M-1)
										break;
								}
							}
							run->c2=x;
							x++;
							bandera=0;
							nroblob=0;
							for each (Blob^ blob in blobs)
							{
								cliext::list<Estructuras::Run^>::iterator iter = blob->listaderuns->end();
								iter--;
								while (iter->r>=(y-1))
								{
									if ((run->c1<iter->c1 && (run->c2+1)>=iter->c1) || (run->c1>=iter->c1 && (run->c1-1)<=iter->c2)) // D8
									{
										if (bandera==0)
										{
											blob->listaderuns->push_back(run);
											blob->pixeles+=run->c2-run->c1+1;
											raiznueva=blob->parent;
											bandera=1;
										}
										if (bandera==1)
										{
											blob->parent=raiznueva;
										}
									}
									if(iter!=blob->listaderuns->begin())
									iter--;
									else
										break;
								}
								nroblob++;
							}
							if (bandera==0)
							{
								Blob^ blobnuevo = gcnew Blob();
								blobnuevo->parent = raiz;
								raiz++;
								blobnuevo->pixeles=run->c2-run->c1+1;
								blobnuevo->listaderuns = gcnew cliext::list<Run^>();
								blobnuevo->listaderuns->push_back(run);
								blobs->push_back(blobnuevo);
							}
						}
						x++;
					}
					y++;
				}
			}
			// Lo sgte es solo para visualizar
			cliext::vector<int>^ raices = gcnew cliext::vector<int>();
			cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(M,N);
			nroblob=0;
			for each (Blob^ blob in blobs)
			{
				int r=nroblob;
				raices->push_back(blob->parent);
				while(raices[r]!=r)
					r = raices[r];
				for each (Estructuras::Run^ run in blob->listaderuns)
				{
					for(x=run->c1;x<=run->c2;x++)
						NewArray[x,run->r]=safe_cast<unsigned char>(20*(r+1));
				}
				nroblob++;
			}
			// para saber el numero de elementos conectados
			nroblob=0;
			cantelemconec=0;
			for each(int aux in raices)
			{
				if(aux==nroblob)
					cantelemconec++;
				nroblob++;
			}
			return NewArray;
		}

	private: cli::array<unsigned char, 2>^ ExtraccionRapidaBooleana(cli::array<unsigned char, 2>^Imagen2)
		{
			int x,y;
			int bandera=0;
			raiz=0;
			int nroblob, raiznueva;
			int M = Imagen2->GetLength(0);
			int N = Imagen2->GetLength(1);
			blobs = gcnew cliext::list<Blob^>();

					  cli::array<bool, 2>^ Imagen = gcnew cli::array<bool, 2>(M, N);
					  for(y=0; y<N; y++)
						  for (x=0; x<M; x++)
							  if(Imagen2[x,y]==255)
								  Imagen[x,y]=true;

			y=0;
			while (y<N && bandera==0)
			{
				x=0;
				while(x<M)
				{
					if (Imagen[x,y]==true)
					{
						Estructuras::Run^ run = gcnew Estructuras::Run();
						run->r=y;
						run->c1=x;
						if(x<M-1)
						{
							while(Imagen[x+1,y]==true)
							{
								x++;
								if(x==M-1)
									break;
							}
						}
						run->c2=x;
						x++;
						Blob^ blob = gcnew Blob();
						blob->parent = raiz;
						raiz++;
						blob->pixeles=run->c2-run->c1+1;
						blob->listaderuns = gcnew cliext::list<Run^>();
						blob->listaderuns->push_back(run);
						blobs->push_back(blob);
						bandera=1;
					}
					x++;
				}
				y++;
			}
			if(y<=N-1)
			{
				while (y<N)
				{
					x=0;
					while(x<M)
					{
						if (Imagen[x,y]==true)
						{
							Estructuras::Run^ run = gcnew Estructuras::Run();
							run->r=y;
							run->c1=x;
							if(x<M-1)
							{
								while(Imagen[x+1,y]==true)
								{
									x++;
									if(x==M-1)
										break;
								}
							}
							run->c2=x;
							x++;
							bandera=0;
							nroblob=0;
							for each (Blob^ blob in blobs)
							{
								cliext::list<Estructuras::Run^>::iterator iter = blob->listaderuns->end();
								iter--;
								while (iter->r>=(y-1))
								{
									if ((run->c1<iter->c1 && (run->c2+1)>=iter->c1) || (run->c1>=iter->c1 && (run->c1-1)<=iter->c2)) // D8
									{
										if (bandera==0)
										{
											blob->listaderuns->push_back(run);
											blob->pixeles+=run->c2-run->c1+1;
											raiznueva=blob->parent;
											bandera=1;
										}
										if (bandera==1)
										{
											blob->parent=raiznueva;
										}
									}
									if(iter!=blob->listaderuns->begin())
									iter--;
									else
										break;
								}
								nroblob++;
							}
							if (bandera==0)
							{
								Blob^ blobnuevo = gcnew Blob();
								blobnuevo->parent = raiz;
								raiz++;
								blobnuevo->pixeles=run->c2-run->c1+1;
								blobnuevo->listaderuns = gcnew cliext::list<Run^>();
								blobnuevo->listaderuns->push_back(run);
								blobs->push_back(blobnuevo);
							}
						}
						x++;
					}
					y++;
				}
			}
			// Lo sgte es solo para visualizar
			cliext::vector<int>^ raices = gcnew cliext::vector<int>();
			cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(M,N);
			nroblob=0;
			for each (Blob^ blob in blobs)
			{
				int r=nroblob;
				raices->push_back(blob->parent);
				while(raices[r]!=r)
					r = raices[r];
				for each (Estructuras::Run^ run in blob->listaderuns)
				{
					for(x=run->c1;x<=run->c2;x++)
						NewArray[x,run->r]=safe_cast<unsigned char>(20*(r+1));
				}
				nroblob++;
			}
			// para saber el numero de elementos conectados
			nroblob=0;
			cantelemconec=0;
			for each(int aux in raices)
			{
				if(aux==nroblob)
					cantelemconec++;
				nroblob++;
			}
			return NewArray;
		}

	private: System::Void RegionesFast_Click(System::Object^  sender, System::EventArgs^  e)
		{
		 	 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
					 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(V->MatrizImagen->GetLength(0),V->MatrizImagen->GetLength(1));
					 NewImArray = Extraccionrapida(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos conectados = "+cantelemconec;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }
			 if (V != nullptr && V->aColores == true)
			 {
				 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(Imagen->Width,Imagen->Height);
					 NewImArray = ExtraccionHSI();
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos conectados = "+cantelemconec;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }

		}

	private: System::Void AND_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 if (operando1 != nullptr && operando2 != nullptr)
			 {
				 int x, y;
				 int M = operando1->GetLength(0);
				 int N = operando1->GetLength(1);
				 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(operando1->GetLength(0),operando1->GetLength(1));
				 for (x=0;x<M;x++)
				 {
					 for (y=0;y<N;y++)
					 {
						 if(operando1[x,y]==0 && operando2[x,y]==0)
						 NewImArray[x,y]=0;
						 if(operando1[x,y]==0 && operando2[x,y]==255)
						 NewImArray[x,y]=255;
						 if(operando1[x,y]==255 && operando2[x,y]==0)
						 NewImArray[x,y]=255;
						 if(operando1[x,y]==255 && operando2[x,y]==255)
						 NewImArray[x,y]=0;
						 //AuxArray[x,y] = safe_cast<double>(operando1[x,y] - operando2[x,y]);
					 }
				 }
		 		 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();	
			 }
		}
	
	private: cli::array<unsigned char, 2>^ PasaraUnsignedChar (cli::array<int,2>^ Arreglo)
		{
			 int M = Arreglo->GetLength(0);
			 int N = Arreglo->GetLength(1);
			 cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
			 double auxmax = Arreglo[0,0];
			 double auxmin = Arreglo[0,0];
			 for each(int aux in Arreglo){
				 if(aux > auxmax)
					 auxmax = aux;
				 if(aux < auxmin)
					 auxmin = aux;
			 }
			 int x, y;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 NewImArray[x,y]=safe_cast<unsigned char>(safe_cast<double>(Arreglo[x,y]-auxmin)/safe_cast<double>(auxmax-auxmin)*255.0);
				 }
			 }
			 return NewImArray;
		}

	private: System::Void mexHatImagenThreshold2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray;
					 NewImArray = PasaraUnsignedChar(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
					 cli::array<unsigned char, 2>^ NewImArray2;
					 NewImArray2 = Threshold2INT(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva2->MatrizImagen = NewImArray2;
					 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
					 Vnueva2->aColores = false;
					 Vnueva2->tienetresholding = true;
					 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
					 Vnueva2->MdiParent = this;
					 Vnueva2->Show();			
			 }		 
		}

	private: System::Void mexHatImagenThresholdToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray;
					 NewImArray = PasaraUnsignedChar(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
					 cli::array<unsigned char, 2>^ NewImArray2;
					 NewImArray2 = ThresholdINT(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva2->MatrizImagen = NewImArray2;
					 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
					 Vnueva2->aColores = false;
					 Vnueva2->tienetresholding = true;
					 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
					 Vnueva2->MdiParent = this;
					 Vnueva2->Show();			
			 }		 		 
		}

	private: void RegionesConectadasD8(cli::array<unsigned char,2>^ MatrizBinariaImagen)
		{
			int x,y,i,j,tamant;
			int CantidadDeRegiones = 0;
			int CantidadDePuntos;
			cli::array<cli::array<cli::array<int>^>^>^ ListadoDeRegiones = gcnew cli::array<cli::array<cli::array<int>^>^>(0);
			cli::array<cli::array<int>^>^ ListaAgregados;
			cli::array<cli::array<int>^>^ ListaAgregar;
			cli::array<cli::array<int>^>^ Aux;
			cli::array<bool,2>^ Verificados = gcnew cli::array<bool,2>(MatrizBinariaImagen->GetLength(0),MatrizBinariaImagen->GetLength(1));
			for(y=1;y<MatrizBinariaImagen->GetLength(1)-1;y++){
				for(x=1;x<MatrizBinariaImagen->GetLength(0)-1;x++){
					if(MatrizBinariaImagen[x,y] && !Verificados[x,y]){
						ListaAgregados = gcnew cli::array<cli::array<int>^>(0);
						Verificados[x,y]=true;
						CantidadDeRegiones++;
						Aux = gcnew cli::array<cli::array<int>^>(1);
						Aux[0] = gcnew cli::array<int>(2);
						Aux[0][0]=x;
						Aux[0][1]=y;
						do{
							ListaAgregar = gcnew cli::array<cli::array<int>^>(0);
							CantidadDePuntos=0;
							for each(cli::array<int>^ punto in Aux){
								if(punto[0]>0 && punto[1]>0 && punto[0]<(MatrizBinariaImagen->GetLength(0)-1) && punto[1]<(MatrizBinariaImagen->GetLength(1)-1)){
									for(j=-1;j<2;j++){
										for(i=-1;i<2;i++){
											if(MatrizBinariaImagen[punto[0]+i,punto[1]+j] && !Verificados[punto[0]+i,punto[1]+j]){
												CantidadDePuntos++;
												Verificados[punto[0]+i,punto[1]+j]=true;
												ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
												ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
												ListaAgregar[CantidadDePuntos-1][0]=punto[0]+i;
												ListaAgregar[CantidadDePuntos-1][1]=punto[1]+j;
											}
										}
									}
								}
							}
							tamant = ListaAgregados->Length;
							ListaAgregados->Resize(ListaAgregados,tamant+Aux->Length);
							Aux->CopyTo(ListaAgregados,tamant);
							Aux = gcnew cli::array<cli::array<int>^>(ListaAgregar->Length);
							ListaAgregar->CopyTo(Aux,0);
						}while(CantidadDePuntos!=0);
						ListadoDeRegiones->Resize(ListadoDeRegiones,CantidadDeRegiones);
						ListadoDeRegiones[CantidadDeRegiones-1] = gcnew cli::array<cli::array<int>^>(ListaAgregados->Length);
						ListaAgregados->CopyTo(ListadoDeRegiones[CantidadDeRegiones-1],0);
					}
				}
			}
			int indice = 0;
			probables = gcnew cliext::vector<Estructuras::Probable^>();
			for each (cli::array<cli::array<int>^>^ ec in ListadoDeRegiones)
			{
				if(ec->GetLength(0)>=50 && ec->GetLength(0)<=5000)
				{
					indice++;
					Estructuras::Probable^ probable = gcnew Estructuras::Probable();
					probable->area=ec->GetLength(0);
					bool band = false;
					for each (cli::array<int>^ punto in ec)
					{
						if(!band)
						{
							probable->xmin=punto[0];
							probable->Yxmin=punto[1];
							probable->ymin=punto[1];
							probable->Xymin=punto[0];
							probable->xmax=punto[0];
							probable->Yxmax=punto[1];
							probable->ymax=punto[1];
							probable->Xymax=punto[0];
							band=true;
						}
						else
						{

							if (punto[1]>probable->ymax)
							{
								probable->ymax=punto[1];
								probable->Xymax=punto[0];
							}
							if (punto[1]<probable->ymin)
							{
								probable->ymin=punto[1];
								probable->Xymin=punto[0];
							}
							if (punto[0]>probable->xmax)
							{
								probable->xmax=punto[0];
								probable->Yxmax=punto[1];
							}
							if (punto[0]<probable->xmin)
							{
								probable->xmin=punto[0];
								probable->Yxmin=punto[1];
							}
						}
						probable->largo=probable->xmax-probable->xmin+1;
						probable->ancho=probable->ymax-probable->ymin+1;
						probable->x0=probable->xmin;
						probable->y0=probable->ymin;
					}
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(probable->largo, probable->ancho);
					for each (cli::array<int>^ punto in ec)
					regionaux[punto[0]-probable->xmin,punto[1]-probable->y0]=255;
					probable->region = regionaux;
					probables->push_back(probable);
				}
			}
			cantelemsig=indice;
		}

	private: void RegionesConectadasD4(cli::array<unsigned char,2>^ MatrizBinariaImagen)
		{
			int x,y,tamant;
			int CantidadDeRegiones = 0;
			int CantidadDePuntos;
			cli::array<cli::array<cli::array<int>^>^>^ ListadoDeRegiones = gcnew cli::array<cli::array<cli::array<int>^>^>(0);
			cli::array<cli::array<int>^>^ ListaAgregados;
			cli::array<cli::array<int>^>^ ListaAgregar;
			cli::array<cli::array<int>^>^ Aux;
			cli::array<bool,2>^ Verificados = gcnew cli::array<bool,2>(MatrizBinariaImagen->GetLength(0),MatrizBinariaImagen->GetLength(1));
			for(y=1;y<MatrizBinariaImagen->GetLength(1)-1;y++){
				for(x=1;x<MatrizBinariaImagen->GetLength(0)-1;x++){
					if(MatrizBinariaImagen[x,y] && !Verificados[x,y]){
						ListaAgregados = gcnew cli::array<cli::array<int>^>(0);
						Verificados[x,y]=true;
						CantidadDeRegiones++;
						Aux = gcnew cli::array<cli::array<int>^>(1);
						Aux[0] = gcnew cli::array<int>(2);
						Aux[0][0]=x;
						Aux[0][1]=y;
						do{
							ListaAgregar = gcnew cli::array<cli::array<int>^>(0);
							CantidadDePuntos=0;
							for each(cli::array<int>^ punto in Aux){
								if(punto[0]>0 && punto[1]>0 && punto[0]<(MatrizBinariaImagen->GetLength(0)-1) && punto[1]<(MatrizBinariaImagen->GetLength(1)-1)){
									if(MatrizBinariaImagen[punto[0],punto[1]-1] && !Verificados[punto[0],punto[1]-1]){
										CantidadDePuntos++;
										Verificados[punto[0],punto[1]-1]=true;
										ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
										ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
										ListaAgregar[CantidadDePuntos-1][0]=punto[0];
										ListaAgregar[CantidadDePuntos-1][1]=punto[1]-1;
									}
									if(MatrizBinariaImagen[punto[0],punto[1]+1] && !Verificados[punto[0],punto[1]+1]){
										CantidadDePuntos++;
										Verificados[punto[0],punto[1]+1]=true;
										ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
										ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
										ListaAgregar[CantidadDePuntos-1][0]=punto[0];
										ListaAgregar[CantidadDePuntos-1][1]=punto[1]+1;
									}
									if(MatrizBinariaImagen[punto[0]-1,punto[1]] && !Verificados[punto[0]-1,punto[1]]){
										CantidadDePuntos++;
										Verificados[punto[0]-1,punto[1]]=true;
										ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
										ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
										ListaAgregar[CantidadDePuntos-1][0]=punto[0]-1;
										ListaAgregar[CantidadDePuntos-1][1]=punto[1];
									}
									if(MatrizBinariaImagen[punto[0]+1,punto[1]] && !Verificados[punto[0]+1,punto[1]]){
										CantidadDePuntos++;
										Verificados[punto[0]+1,punto[1]]=true;
										ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
										ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
										ListaAgregar[CantidadDePuntos-1][0]=punto[0]+1;
										ListaAgregar[CantidadDePuntos-1][1]=punto[1];
									}
								}
							}
							tamant = ListaAgregados->Length;
							ListaAgregados->Resize(ListaAgregados,tamant+Aux->Length);
							Aux->CopyTo(ListaAgregados,tamant);
							Aux = gcnew cli::array<cli::array<int>^>(ListaAgregar->Length);
							ListaAgregar->CopyTo(Aux,0);
						}while(CantidadDePuntos!=0);
						ListadoDeRegiones->Resize(ListadoDeRegiones,CantidadDeRegiones);
						ListadoDeRegiones[CantidadDeRegiones-1] = gcnew cli::array<cli::array<int>^>(ListaAgregados->Length);
						ListaAgregados->CopyTo(ListadoDeRegiones[CantidadDeRegiones-1],0);
					}
				}
			}
			int indice = 0;
			probables = gcnew cliext::vector<Estructuras::Probable^>();
			for each (cli::array<cli::array<int>^>^ ec in ListadoDeRegiones)
			{
				if(ec->GetLength(0)>=50 && ec->GetLength(0)<=5000)
				{
					indice++;
					Estructuras::Probable^ probable = gcnew Estructuras::Probable();
					probable->area=ec->GetLength(0);
					bool band = false;
					for each (cli::array<int>^ punto in ec)
					{
						if(!band)
						{
							probable->xmin=punto[0];
							probable->Yxmin=punto[1];
							probable->ymin=punto[1];
							probable->Xymin=punto[0];
							probable->xmax=punto[0];
							probable->Yxmax=punto[1];
							probable->ymax=punto[1];
							probable->Xymax=punto[0];
							band=true;
						}
						else
						{

							if (punto[1]>probable->ymax)
							{
								probable->ymax=punto[1];
								probable->Xymax=punto[0];
							}
							if (punto[1]<probable->ymin)
							{
								probable->ymin=punto[1];
								probable->Xymin=punto[0];
							}
							if (punto[0]>probable->xmax)
							{
								probable->xmax=punto[0];
								probable->Yxmax=punto[1];
							}
							if (punto[0]<probable->xmin)
							{
								probable->xmin=punto[0];
								probable->Yxmin=punto[1];
							}
						}
						probable->largo=probable->xmax-probable->xmin+1;
						probable->ancho=probable->ymax-probable->ymin+1;
						probable->x0=probable->xmin;
						probable->y0=probable->ymin;
					}
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(probable->largo, probable->ancho);
					for each (cli::array<int>^ punto in ec)
					regionaux[punto[0]-probable->xmin,punto[1]-probable->y0]=255;
					probable->region = regionaux;
					probables->push_back(probable);
				}
			}
			cantelemsig=indice;
			// lo sgte es solo para visualizar
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(MatrizBinariaImagen->GetLength(0),MatrizBinariaImagen->GetLength(1));
			for each (Estructuras::Probable^ probable in probables)
			for (y=probable->y0; y<=probable->ymax; y++)
				for (x=probable->x0; x<=probable->xmax; x++)
					NewImArray[x,y]+=probable->region[x-probable->x0,y-probable->y0];
			ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
			Vnueva->MatrizImagen = NewImArray;
			Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
			Vnueva->aColores = false;
			Vnueva->tienetresholding=true;
			Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos significativos = " + cantelemsig;
			Vnueva->Size::set(Vnueva->Imagen->Size::get());
			Vnueva->MdiParent = this;
			Vnueva->Show();
		}

	private: void RegionesConectadasColorD8()
		{
			int cubo = 9;
			int x,y,i,j,tamant;
			int CantidadDeRegiones = 0;
			int CantidadDePuntos;
			cli::array<cli::array<cli::array<int>^>^>^ ListadoDeRegiones = gcnew cli::array<cli::array<cli::array<int>^>^>(0);
			cli::array<cli::array<int>^>^ ListaAgregados;
			cli::array<cli::array<int>^>^ ListaAgregar;
			cli::array<cli::array<int>^>^ Aux;
			cli::array<bool,2>^ Verificados = gcnew cli::array<bool,2>(this->Imagen->Width,this->Imagen->Height);
			for(y=1;y<this->Imagen->Height-1;y++){
				for(x=1;x<this->Imagen->Width-1;x++){
					if(!Verificados[x,y]){
						ListaAgregados = gcnew cli::array<cli::array<int>^>(0);
						Verificados[x,y]=true;
						CantidadDeRegiones++;
						Aux = gcnew cli::array<cli::array<int>^>(1);
						Aux[0] = gcnew cli::array<int>(2);
						Aux[0][0]=x;
						Aux[0][1]=y;
						do{
							ListaAgregar = gcnew cli::array<cli::array<int>^>(0);
							CantidadDePuntos=0;
							for each(cli::array<int>^ punto in Aux){
								if(punto[0]>0 && punto[1]>0 && punto[0]<(this->Imagen->Width-1) && punto[1]<(this->Imagen->Height-1)){
									for(j=-1;j<2;j++){
										for(i=-1;i<2;i++){
											if(System::Math::Abs(this->Imagen->GetPixel(punto[0]+i,punto[1]+j).R-this->Imagen->GetPixel(punto[0],punto[1]).R)<cubo &&
											   System::Math::Abs(this->Imagen->GetPixel(punto[0]+i,punto[1]+j).G-this->Imagen->GetPixel(punto[0],punto[1]).G)<cubo &&
											   System::Math::Abs(this->Imagen->GetPixel(punto[0]+i,punto[1]+j).B-this->Imagen->GetPixel(punto[0],punto[1]).B)<cubo &&
											   !Verificados[punto[0]+i,punto[1]+j]){
												CantidadDePuntos++;
												Verificados[punto[0]+i,punto[1]+j]=true;
												ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
												ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
												ListaAgregar[CantidadDePuntos-1][0]=punto[0]+i;
												ListaAgregar[CantidadDePuntos-1][1]=punto[1]+j;
											}
										}
									}
								}
							}
							tamant = ListaAgregados->Length;
							ListaAgregados->Resize(ListaAgregados,tamant+Aux->Length);
							Aux->CopyTo(ListaAgregados,tamant);
							Aux = gcnew cli::array<cli::array<int>^>(ListaAgregar->Length);
							ListaAgregar->CopyTo(Aux,0);
						}while(CantidadDePuntos!=0);
						ListadoDeRegiones->Resize(ListadoDeRegiones,CantidadDeRegiones);
						ListadoDeRegiones[CantidadDeRegiones-1] = gcnew cli::array<cli::array<int>^>(ListaAgregados->Length);
						ListaAgregados->CopyTo(ListadoDeRegiones[CantidadDeRegiones-1],0);
					}
				}
			}
			int indice=0;
			probables = gcnew cliext::vector<Estructuras::Probable^>();
			for each (cli::array<cli::array<int>^>^ ec in ListadoDeRegiones)
			{
				if(ec->GetLength(0)>=50 && ec->GetLength(0)<=5000)
				{
					indice++;
					Estructuras::Probable^ probable = gcnew Estructuras::Probable();
					probable->area=ec->GetLength(0);
					bool band = false;
					for each (cli::array<int>^ punto in ec)
					{
						if(!band)
						{
							probable->xmin=punto[0];
							probable->Yxmin=punto[1];
							probable->ymin=punto[1];
							probable->Xymin=punto[0];
							probable->xmax=punto[0];
							probable->Yxmax=punto[1];
							probable->ymax=punto[1];
							probable->Xymax=punto[0];
							band=true;
						}
						else
						{

							if (punto[1]>probable->ymax)
							{
								probable->ymax=punto[1];
								probable->Xymax=punto[0];
							}
							if (punto[1]<probable->ymin)
							{
								probable->ymin=punto[1];
								probable->Xymin=punto[0];
							}
							if (punto[0]>probable->xmax)
							{
								probable->xmax=punto[0];
								probable->Yxmax=punto[1];
							}
							if (punto[0]<probable->xmin)
							{
								probable->xmin=punto[0];
								probable->Yxmin=punto[1];
							}
						}
						probable->largo=probable->xmax-probable->xmin+1;
						probable->ancho=probable->ymax-probable->ymin+1;
						probable->x0=probable->xmin;
						probable->y0=probable->ymin;
					}
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(probable->largo, probable->ancho);
					for each (cli::array<int>^ punto in ec)
					regionaux[punto[0]-probable->xmin,punto[1]-probable->y0]=255;
					probable->region = regionaux;
					probables->push_back(probable);
				}
			}
			cantelemsig=indice;
			// lo sgte es solo para visualizar
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(this->Imagen->Width,this->Imagen->Height);
			for each (Estructuras::Probable^ probable in probables)
			for (y=probable->y0; y<=probable->ymax; y++)
				for (x=probable->x0; x<=probable->xmax; x++)
					NewImArray[x,y]+=probable->region[x-probable->x0,y-probable->y0];
			ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
			Vnueva->MatrizImagen = NewImArray;
			Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
			Vnueva->aColores = false;
			Vnueva->tienetresholding=true;
			Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos significativos = " + cantelemsig;
			Vnueva->Size::set(Vnueva->Imagen->Size::get());
			Vnueva->MdiParent = this;
			Vnueva->Show();
		}

	private: void RegionesConectadasColorD4()
		{
			int cubo = 400;
			int x,y,tamant;
			int CantidadDeRegiones = 0;
			int CantidadDePuntos;
			cli::array<cli::array<cli::array<int>^>^>^ ListadoDeRegiones = gcnew cli::array<cli::array<cli::array<int>^>^>(0);
			cli::array<cli::array<int>^>^ ListaAgregados;
			cli::array<cli::array<int>^>^ ListaAgregar;
			cli::array<cli::array<int>^>^ Aux;
			cli::array<bool,2>^ Verificados = gcnew cli::array<bool,2>(this->Imagen->Width,this->Imagen->Height);
			for(y=1;y<this->Imagen->Height-1;y++){
				for(x=1;x<this->Imagen->Width-1;x++){
					if(!Verificados[x,y]){
						ListaAgregados = gcnew cli::array<cli::array<int>^>(0);
						Verificados[x,y]=true;
						CantidadDeRegiones++;
						Aux = gcnew cli::array<cli::array<int>^>(1);
						Aux[0] = gcnew cli::array<int>(2);
						Aux[0][0]=x;
						Aux[0][1]=y;
						do{
							ListaAgregar = gcnew cli::array<cli::array<int>^>(0);
							CantidadDePuntos=0;
							for each(cli::array<int>^ punto in Aux){
								if(punto[0]>0 && punto[1]>0 && punto[0]<(this->Imagen->Width-1) && punto[1]<(this->Imagen->Height-1)){
									if(!Verificados[punto[0]-1,punto[1]]){
										if(((this->Imagen->GetPixel(punto[0]-1,punto[1]).R-this->Imagen->GetPixel(punto[0],punto[1]).R)*(this->Imagen->GetPixel(punto[0]-1,punto[1]).R-this->Imagen->GetPixel(punto[0],punto[1]).R) +
											(this->Imagen->GetPixel(punto[0]-1,punto[1]).G-this->Imagen->GetPixel(punto[0],punto[1]).G)*(this->Imagen->GetPixel(punto[0]-1,punto[1]).G-this->Imagen->GetPixel(punto[0],punto[1]).G) +
											(this->Imagen->GetPixel(punto[0]-1,punto[1]).B-this->Imagen->GetPixel(punto[0],punto[1]).B)*(this->Imagen->GetPixel(punto[0]-1,punto[1]).B-this->Imagen->GetPixel(punto[0],punto[1]).B) )<cubo){
											CantidadDePuntos++;
											Verificados[punto[0]-1,punto[1]]=true;
											ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
											ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
											ListaAgregar[CantidadDePuntos-1][0]=punto[0]-1;
											ListaAgregar[CantidadDePuntos-1][1]=punto[1];
										}
									}
									if(!Verificados[punto[0]+1,punto[1]]){
										if((this->Imagen->GetPixel(punto[0]+1,punto[1]).R-this->Imagen->GetPixel(punto[0],punto[1]).R)*(this->Imagen->GetPixel(punto[0]+1,punto[1]).R-this->Imagen->GetPixel(punto[0],punto[1]).R)+
										   (this->Imagen->GetPixel(punto[0]+1,punto[1]).G-this->Imagen->GetPixel(punto[0],punto[1]).G)*(this->Imagen->GetPixel(punto[0]+1,punto[1]).G-this->Imagen->GetPixel(punto[0],punto[1]).G)+
										   (this->Imagen->GetPixel(punto[0]+1,punto[1]).B-this->Imagen->GetPixel(punto[0],punto[1]).B)*(this->Imagen->GetPixel(punto[0]+1,punto[1]).B-this->Imagen->GetPixel(punto[0],punto[1]).B)<cubo){
											CantidadDePuntos++;
											Verificados[punto[0]+1,punto[1]]=true;
											ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
											ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
											ListaAgregar[CantidadDePuntos-1][0]=punto[0]+1;
											ListaAgregar[CantidadDePuntos-1][1]=punto[1];
										}
									}
									if(!Verificados[punto[0],punto[1]-1]){
										if((this->Imagen->GetPixel(punto[0],punto[1]-1).R-this->Imagen->GetPixel(punto[0],punto[1]).R)*(this->Imagen->GetPixel(punto[0],punto[1]-1).R-this->Imagen->GetPixel(punto[0],punto[1]).R)+
										   (this->Imagen->GetPixel(punto[0],punto[1]-1).G-this->Imagen->GetPixel(punto[0],punto[1]).G)*(this->Imagen->GetPixel(punto[0],punto[1]-1).G-this->Imagen->GetPixel(punto[0],punto[1]).G)+
										   (this->Imagen->GetPixel(punto[0],punto[1]-1).B-this->Imagen->GetPixel(punto[0],punto[1]).B)*(this->Imagen->GetPixel(punto[0],punto[1]-1).B-this->Imagen->GetPixel(punto[0],punto[1]).B)<cubo){
											CantidadDePuntos++;
											Verificados[punto[0],punto[1]-1]=true;
											ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
											ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
											ListaAgregar[CantidadDePuntos-1][0]=punto[0];
											ListaAgregar[CantidadDePuntos-1][1]=punto[1]-1;
										}
									}
									if(!Verificados[punto[0],punto[1]+1]){
										if((this->Imagen->GetPixel(punto[0],punto[1]+1).R-this->Imagen->GetPixel(punto[0],punto[1]).R)*(this->Imagen->GetPixel(punto[0],punto[1]+1).R-this->Imagen->GetPixel(punto[0],punto[1]).R)+
										   (this->Imagen->GetPixel(punto[0],punto[1]+1).G-this->Imagen->GetPixel(punto[0],punto[1]).G)*(this->Imagen->GetPixel(punto[0],punto[1]+1).G-this->Imagen->GetPixel(punto[0],punto[1]).G)+
										   (this->Imagen->GetPixel(punto[0],punto[1]+1).B-this->Imagen->GetPixel(punto[0],punto[1]).B)*(this->Imagen->GetPixel(punto[0],punto[1]+1).B-this->Imagen->GetPixel(punto[0],punto[1]).B)<cubo){
											CantidadDePuntos++;
											Verificados[punto[0],punto[1]+1]=true;
											ListaAgregar->Resize(ListaAgregar,CantidadDePuntos);
											ListaAgregar[CantidadDePuntos-1] = gcnew cli::array<int>(2);
											ListaAgregar[CantidadDePuntos-1][0]=punto[0];
											ListaAgregar[CantidadDePuntos-1][1]=punto[1]+1;
										}
									}
								}
							}
							tamant = ListaAgregados->Length;
							ListaAgregados->Resize(ListaAgregados,tamant+Aux->Length);
							Aux->CopyTo(ListaAgregados,tamant);
							Aux = gcnew cli::array<cli::array<int>^>(ListaAgregar->Length);
							ListaAgregar->CopyTo(Aux,0);
						}while(CantidadDePuntos!=0);
						ListadoDeRegiones->Resize(ListadoDeRegiones,CantidadDeRegiones);
						ListadoDeRegiones[CantidadDeRegiones-1] = gcnew cli::array<cli::array<int>^>(ListaAgregados->Length);
						ListaAgregados->CopyTo(ListadoDeRegiones[CantidadDeRegiones-1],0);
					}
				}
			}
			int indice = 0;
			probables = gcnew cliext::vector<Estructuras::Probable^>();
			for each (cli::array<cli::array<int>^>^ ec in ListadoDeRegiones)
			{
				if(ec->GetLength(0)>=50 && ec->GetLength(0)<=5000)
				{
					indice++;
					Estructuras::Probable^ probable = gcnew Estructuras::Probable();
					probable->area=ec->GetLength(0);
					bool band = false;
					for each (cli::array<int>^ punto in ec)
					{
						if(!band)
						{
							probable->xmin=punto[0];
							probable->Yxmin=punto[1];
							probable->ymin=punto[1];
							probable->Xymin=punto[0];
							probable->xmax=punto[0];
							probable->Yxmax=punto[1];
							probable->ymax=punto[1];
							probable->Xymax=punto[0];
							band=true;
						}
						else
						{

							if (punto[1]>probable->ymax)
							{
								probable->ymax=punto[1];
								probable->Xymax=punto[0];
							}
							if (punto[1]<probable->ymin)
							{
								probable->ymin=punto[1];
								probable->Xymin=punto[0];
							}
							if (punto[0]>probable->xmax)
							{
								probable->xmax=punto[0];
								probable->Yxmax=punto[1];
							}
							if (punto[0]<probable->xmin)
							{
								probable->xmin=punto[0];
								probable->Yxmin=punto[1];
							}
						}
						probable->largo=probable->xmax-probable->xmin+1;
						probable->ancho=probable->ymax-probable->ymin+1;
						probable->x0=probable->xmin;
						probable->y0=probable->ymin;
					}
					cli::array<unsigned char, 2>^ regionaux = gcnew cli::array<unsigned char, 2>(probable->largo, probable->ancho);
					for each (cli::array<int>^ punto in ec)
					regionaux[punto[0]-probable->xmin,punto[1]-probable->y0]=255;
					probable->region = regionaux;
					probables->push_back(probable);
				}
			}
			cantelemsig=indice;
			// lo sgte es solo para visualizar
			cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(this->Imagen->Width,this->Imagen->Height);
			unsigned char grispd =0;
			for each (Estructuras::Probable^ probable in probables)
			{
				if(grispd==240)
					grispd=0;
				else
					grispd += 20;
				for (y=probable->y0; y<=probable->ymax; y++)
				{
					for (x=probable->x0; x<=probable->xmax; x++)
					{
						if(probable->region[x-probable->x0,y-probable->y0]==255)
							NewImArray[x,y]+=grispd;
					}
				}
			}
			ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
			Vnueva->MatrizImagen = NewImArray;
			Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
			Vnueva->aColores = false;
			Vnueva->tienetresholding=true;
			Vnueva->toolStripStatusLabel1->Text = L"Cantidad de elementos significativos = " + cantelemsig;
			Vnueva->Size::set(Vnueva->Imagen->Size::get());
			Vnueva->MdiParent = this;
			Vnueva->Show();
		}

	private: System::Void RegAB_Click(System::Object^  sender, System::EventArgs^  e)
		{
		 	 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			 {
				RegionesConectadasD4(V->MatrizImagen);
			 }		 
			 if (V != nullptr && V->aColores == true)
			 {
				 RegionesConectadasColorD4();
			 }
		}

	private: cli::array<unsigned char, 2>^ ThresholdAdaptivo (cli::array<int, 2>^ MatrizImagen, int TamVentana, double T){
			 int x, y, x1, y1, x2, y2, sum, CantPixeles;
			 int s2 = TamVentana/2;
			 cli::array<unsigned char, 2>^ Resultado =  gcnew cli::array<unsigned char, 2>(MatrizImagen->GetLength(0), MatrizImagen->GetLength(1));
			 cli::array<int, 2>^ MatrizIntegral =  gcnew cli::array<int, 2>(MatrizImagen->GetLength(0), MatrizImagen->GetLength(1));
			 for(x=0;x<MatrizImagen->GetLength(0);x++){
				 sum=0;
				 for(y=0;y<MatrizImagen->GetLength(1);y++){
					 sum += MatrizImagen[x,y];
					 if(x==0){
						 MatrizIntegral[x,y] = sum;
					 }
					 else{
						 MatrizIntegral[x,y] = MatrizIntegral[x-1,y] + sum;
					 }
				 }
			 }
			 for(x=0;x<MatrizImagen->GetLength(0);x++){
				 for(y=0;y<MatrizImagen->GetLength(1);y++){
					 x1 = x - s2;
					 if(x1 < 0){x1=0;}
					 x2 = x + s2;
					 if(x2 >= MatrizImagen->GetLength(0)){x2 = MatrizImagen->GetLength(0)-1;}
					 y1 = y - s2;
					 if(y1 < 0){y1=0;}
					 y2 = y + s2;
					 if(y2 >= MatrizImagen->GetLength(1)){y2 = MatrizImagen->GetLength(1)-1;} 
					 CantPixeles = (x2 - x1)*(y2 - y1);
					 sum = MatrizIntegral[x2,y2] - MatrizIntegral[x2,y1] - MatrizIntegral[x1,y2] + MatrizIntegral[x1,y1];
					 if((MatrizImagen[x,y]*CantPixeles) <= (sum*(100-T)/100)){
						 Resultado[x,y] = 0;
					 }
					 else{
						 Resultado[x,y] = 255;
					 }
				 }
			 }
			 return Resultado;
		 }

	private: System::Void adaptativoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
		 	 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = ThresholdAdaptivo(AplicarMexicanINT(V->MatrizImagen),20,5.0);
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding=true;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }		 
		 }

	private: cli::array<unsigned char, 2>^ UnirLineas (cli::array<unsigned char, 2>^ Imagen)
		{
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			cli::array<unsigned char,2>^ AuxArray = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ feat1 =
					{
							{1,1,1,1,1},
							{1,1,1,1,1},
							{0,0,255,0,0},
							{255,255,255,255,255},
							{255,255,255,255,255}
					};
			int m = feat1->GetLength(0);
			int n = feat1->GetLength(1);
			int x, y, i, j, a, b, c, d;
			c=(m-1)/2;
			d=(n-1)/2;
			int bandera;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					AuxArray[x,y]=Imagen[x,y];
					bandera = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat1[i,j]==0 || feat1[i,j]==255)
							{
								if(Imagen[a,b]!=feat1[i,j])
									bandera = 1;
							}
						}
					}
					if (bandera==0)
						AuxArray[x,y]=0;
				}
			}
			cli::array<unsigned char,2>^ feat2 =
					{
							{255,255,255,255,255},
							{255,255,255,255,255},
							{0,0,255,0,0},
							{1,1,1,1,1},
							{1,1,1,1,1}
					};
			c=(m-1)/2;
			d=(n-1)/2;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					bandera = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat1[i,j]==0 || feat2[i,j]==255)
							{
								if(Imagen[a,b]!=feat2[i,j])
									bandera = 1;
							}
						}
					}
					if (bandera==0)
						AuxArray[x,y]=0;
				}
			}
			return AuxArray;
		}

	private: cli::array<unsigned char, 2>^ UnirLineas2 (cli::array<unsigned char, 2>^ Imagen)
		{
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			cli::array<unsigned char,2>^ AuxArray = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ AuxArray2 = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ AuxArray3 = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ AuxArray4 = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ feat1 =
					{
							{1,1,1,1,1},
							{1,1,1,1,1},
							{0,0,0,0,0},
							{255,255,255,255,255},
							{255,255,255,255,255}
					};
			cli::array<unsigned char,2>^ feat2 =
					{
							{255,255,255,255,255},
							{255,255,255,255,255},
							{0,0,0,0,0},
							{1,1,1,1,1},
							{1,1,1,1,1}
					};
			cli::array<unsigned char,2>^ feat3 =
					{
							{1,0,255},
							{1,0,255},
							{1,0,255},
							{1,0,255},
							{1,0,255}
					};
			cli::array<unsigned char,2>^ feat4 =
					{
							{255,0,1},
							{255,0,1},
							{255,0,1},
							{255,0,1},
							{255,0,1}
					};
			int m = feat1->GetLength(0);
			int n = feat1->GetLength(1);
			int x, y, i, j, a, b, c, d;
			int blanco, negro;
			c=(m-1)/2;
			d=(n-1)/2;
			int bandera;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					bandera = 0;
					blanco = negro = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat1[i,j]==0)
							{
								if(Imagen[a,b]==255)
									blanco++;
							}
							if(feat1[i,j]==255)
							{
								if(Imagen[a,b]==0)
									bandera=1;
							}
						}
					}
					if (blanco<3 && bandera==0)
					{
						for(j=0;j<n;j++)
						{
							b=y+j-(n-1)/2;
							if(Imagen[x,b]==255)
							{
								AuxArray[x,b]=255;
								break;
							}
						}
					}
				}
			}
			m = feat2->GetLength(0);
			n = feat2->GetLength(1);
			c=(m-1)/2;
			d=(n-1)/2;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					bandera = 0;
					blanco = negro = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat2[i,j]==0)
							{
								if(Imagen[a,b]==255)
									blanco++;
							}
							if(feat2[i,j]==255)
							{
								if(Imagen[a,b]==0)
									bandera=1;
							}
						}
					}
					if (blanco<3 && bandera==0)
					{
						for(j=0;j<n;j++)
						{
							b=y+j-(n-1)/2;
							if(Imagen[x,b]==255)
							{
								AuxArray2[x,b]=255;
								break;
							}
						}
					}
				}
			}
			m = feat3->GetLength(0);
			n = feat3->GetLength(1);
			c=(m-1)/2;
			d=(n-1)/2;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					bandera = 0;
					blanco = negro = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat3[i,j]==0)
							{
								if(Imagen[a,b]==255)
									blanco++;
							}
							if(feat3[i,j]==255)
							{
								if(Imagen[a,b]==0)
									bandera=1;
							}
						}
					}
					if (blanco<3 && bandera==0)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							if(Imagen[a,y]==255)
							{
								AuxArray3[a,y]=255;
								//break;
							}
						}
					}
				}
			}
			m = feat4->GetLength(0);
			n = feat4->GetLength(1);
			c=(m-1)/2;
			d=(n-1)/2;
			for(y=d;y<N-d;y++)
			{
				for(x=c;x<M-c;x++)
				{
					bandera = 0;
					blanco = negro = 0;
					for(j=0;j<n;j++)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							b=y+j-(n-1)/2;
							if(feat4[i,j]==0)
							{
								if(Imagen[a,b]==255)
									blanco++;
							}
							if(feat4[i,j]==255)
							{
								if(Imagen[a,b]==0)
									bandera=1;
							}
						}
					}
					if (blanco<3 && bandera==0)
					{
						for(i=0;i<m;i++)
						{
							a=x+i-(m-1)/2;
							if(Imagen[a,y]==255)
							{
								AuxArray4[a,y]=255;
								//break;
							}
						}
					}
				}
			}
			for(y=0;y<N;y++)
			{
				for(x=0;x<M;x++)
				{
					if(AuxArray[x,y]||AuxArray2[x,y] || AuxArray3[x,y]||AuxArray4[x,y])
						AuxArray[x,y]=255;
				}
			}
			for(y=0;y<N;y++)
			{
				for(x=0;x<M;x++)
				{
					if(AuxArray[x,y]==255)
						AuxArray[x,y]=0;
					else
						AuxArray[x,y]=Imagen[x,y];
				}
			}
			RegionesConectadasD8(AuxArray);
			for each (Probable^ probable in probables)
			{
				int principio, fin;
				int M = probable->region->GetLength(0);
				int N = probable->region->GetLength(1);
				probable->area=0;
				for (y=0; y<N; y++)
				{
					principio = fin = 0;
					x=0;
					while (x<M)
					{
						if (probable->region[x,y]==255)
						{
							principio=x;
							break;
						}
						x++;
					}
					x=M;
					while (x!=0)
					{
						if (probable->region[x-1,y]==255)
						{
							fin=x-1;
							break;
						}
						x--;
					}
					if (fin>(principio+1))
					{
						for (x=principio+1; x<fin; x++)
						{
							probable->region[x,y]=Imagen[x+probable->x0,y+probable->y0];
						}
					}
				}
				for (y=0; y<N; y++)
				{
					for (x=0; x<M; x++)
					{
						if(Imagen[x+probable->x0,y+probable->y0]==255)
						{
							probable->area++;
						}
					}
				}
			}
			return AuxArray;
		}

	private: cli::array<unsigned char, 2>^ UnirLineas3 (cli::array<unsigned char, 2>^ Imagen)
		{
			int M = Imagen->GetLength(0);
			int N = Imagen->GetLength(1);
			cli::array<unsigned char,2>^ AuxArray = gcnew cli::array<unsigned char,2>(M,N);
			cli::array<unsigned char,2>^ AuxArray2 = gcnew cli::array<unsigned char,2>(M,N);
			cliext::vector<array<unsigned char,2>^>^ Features = gcnew cliext::vector<array<unsigned char,2>^>();
			cli::array<unsigned char,2>^ feat1 =
					{
							{1,1,1,1,1},
							{1,1,1,1,1},
							{0,0,0,0,0},
							{255,255,255,255,255},
							{255,255,255,255,255}
					};
			cli::array<unsigned char,2>^ feat2 =
					{
							{255,255,255,255,255},
							{255,255,255,255,255},
							{0,0,0,0,0},
							{1,1,1,1,1},
							{1,1,1,1,1}
					};
			cli::array<unsigned char,2>^ feat3 =
					{
							{1,0,255},
							{1,0,255},
							{1,0,255},
							{1,0,255},
							{1,0,255}
					};
			cli::array<unsigned char,2>^ feat4 =
					{
							{255,0,1},
							{255,0,1},
							{255,0,1},
							{255,0,1},
							{255,0,1}
					};
			Features->push_back(feat3);
			Features->push_back(feat4);
			Features->push_back(feat1);
			Features->push_back(feat2);
			for each (cli::array<unsigned char,2>^ feat in Features)
			{
				int m = feat->GetLength(0);
				int n = feat->GetLength(1);
				int x, y, i, j, a, b, c, d;
				int cont = 0;
				cont++;
				int blanco, negro;
				c=(m-1)/2;
				d=(n-1)/2;
				int bandera;
				for(y=d;y<N-d;y++)
				{
					for(x=c;x<M-c;x++)
					{
						bandera = 0;
						blanco = negro = 0;
						for(j=0;j<n;j++)
						{
							for(i=0;i<m;i++)
							{
								a=x+i-(m-1)/2;
								b=y+j-(n-1)/2;
								if(feat[i,j]==0)
								{
									if(Imagen[a,b]==255)
										blanco++;
								}
								if(feat[i,j]==255)
								{
									if(Imagen[a,b]!=255)
										bandera=1;
								}
							}
						}
						if (blanco<3 && bandera==0 && cont>2)
						{
							for(j=0;j<n;j++)
							{
								b=y+j-(n-1)/2;
								AuxArray[x,b]=255;
							}
						}
						if (blanco<2 && bandera==0 && cont<3)
						{
							for(i=0;i<m;i++)
							{
								a=x+i-(m-1)/2;
								AuxArray[a,y]=255;
							}
						}
					}
				}
			}
			int x,y;
			for(y=0;y<N;y++)
			{
				for(x=0;x<M;x++)
				{
					if(AuxArray[x,y]==255)
						AuxArray[x,y]=0;
					else
						AuxArray[x,y]=Imagen[x,y];
				}
			}
			AuxArray2 = UnirLineas(Imagen);
			for(y=0;y<N;y++)
			{
				for(x=0;x<M;x++)
				{
					if(AuxArray[x,y]||AuxArray2[x,y])
						AuxArray[x,y]=255;
				}
			}
			return AuxArray;
		}

	private: void UnirLineasGW ()
		{
			VentanaImagen^ V = safe_cast<VentanaImagen^>(this->ActiveMdiChild);
			cli::array<double, 2>^ SobelMaskArray = gcnew cli::array<double, 2>(3,3);
			if(V!=nullptr && !V->aColores)
			{
				SobelMaskArray[0,0]= -1.0; SobelMaskArray[1,0]= -2.0; SobelMaskArray[2,0]= -1.0;
				SobelMaskArray[0,1]= 0.0; SobelMaskArray[1,1]= 0.0; SobelMaskArray[2,1]= 0.0;
				SobelMaskArray[0,2]= 1.0; SobelMaskArray[1,2]= 2.0; SobelMaskArray[2,2]= 1.0;
				int M = V->MatrizImagen->GetLength(0);
				int N = V->MatrizImagen->GetLength(1);
				int m = SobelMaskArray->GetLength(0);
				int n = SobelMaskArray->GetLength(1);
				cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(M,N);
				cli::array<double, 2>^ AuxArray1 = gcnew cli::array<double, 2>(M,N);
				cli::array<double, 2>^ AuxArray2 = gcnew cli::array<double, 2>(M,N);
				cli::array<double, 2>^ Gradiente = gcnew cli::array<double, 2>(M,N);
				cli::array<double, 2>^ Alfa = gcnew cli::array<double, 2>(M,N);
				int x, y, i, j, a ,b;
				for(y=0; y<N; y++){
					for(x=0; x<M; x++){
						AuxArray1[x,y]=0;
						for(j=0; j<n; j++){
							for(i=0; i<m; i++){
								a=x+i-(m-1)/2;
								b=y+j-(n-1)/2;
								if((a>=0 && a<M) && (b>=0 && b<N))
									AuxArray1[x,y]+=safe_cast<double>(SobelMaskArray[i,j]*safe_cast<double>(V->MatrizImagen[a,b]/1.0));
							}
						}
					}
				}
				SobelMaskArray[0,0]= -1.0; SobelMaskArray[1,0]= 0.0; SobelMaskArray[2,0]= 1.0;
				SobelMaskArray[0,1]= -2.0; SobelMaskArray[1,1]= 0.0; SobelMaskArray[2,1]= 2.0;
				SobelMaskArray[0,2]= -1.0; SobelMaskArray[1,2]= 0.0; SobelMaskArray[2,2]= 1.0;
				for(y=0; y<N; y++){
					for(x=0; x<M; x++){
						AuxArray2[x,y]=0;
						for(j=0; j<n; j++){
							for(i=0; i<m; i++){
								a=x+i-(m-1)/2;
								b=y+j-(n-1)/2;
								if((a>=0 && a<M) && (b>=0 && b<N))
									AuxArray2[x,y]+=safe_cast<double>(SobelMaskArray[i,j]*safe_cast<double>(V->MatrizImagen[a,b]/1.0));
							}
						}
					}
				}
				for(j=0;j<V->MatrizImagen->GetLength(1);j++){
					for(i=0;i<V->MatrizImagen->GetLength(0);i++){
						Gradiente[i,j]=(System::Math::Abs(AuxArray1[i,j])+System::Math::Abs(AuxArray2[i,j]));
						Alfa[i,j] = System::Math::Atan(AuxArray2[i,j]/AuxArray1[i,j]);
					}
				}
				cli::array<unsigned char, 2>^ ThresImage1;
				ThresImage1 = Threshold2INT(AplicarMexicanINT(V->MatrizImagen));
				ProgramaTFGv1::VentanaImagen^ Vnueva1 = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva1->MatrizImagen = gcnew cli::array<unsigned char, 2>(M,N);
				for(y=0; y<N; y++){
					for(x=0; x<M; x++){
						if(ThresImage1[x,y]==255)
						{
							ThresImage1[x,y]=0;
							Vnueva1->MatrizImagen[x,y]=ThresImage1[x,y];
						}
						else
						{
							ThresImage1[x,y]=255;
							Vnueva1->MatrizImagen[x,y]=ThresImage1[x,y];
						}
					}
				}
				Vnueva1->establecerImagen(this->MatrizAImagen(Vnueva1->MatrizImagen));
				Vnueva1->aColores = false;
				Vnueva1->tienetresholding=true;
				Vnueva1->Size::set(Vnueva1->Imagen->Size::get());
				Vnueva1->MdiParent = this;
				Vnueva1->Show();


				double grados = 10.0;
				double difgrad = 85.0;
				m = n = 5; // tamano de ventana para edge linking
				for(y=0; y<N; y++){
					for(x=0; x<M; x++){
						if(ThresImage1[x,y]==255 || ThresImage1[x,y]==125)
						{
							for(j=0; j<n; j++){
								for(i=0; i<m; i++){
									a=x+i-(m-1)/2;
									b=y+j-(n-1)/2;
									if((a>=0 && a<M) && (b>=0 && b<N) && x!=a && y!=b && ThresImage1[a,b]==0 && System::Math::Abs(Gradiente[x,y]-Gradiente[a,b])<difgrad && System::Math::Abs(Alfa[x,y]-Alfa[a,b])<(grados*System::Math::PI/180.0)){
										ThresImage1[a,b]=125;
										Vnueva1->MatrizImagen[a,b]=255;
									}
								}
							}
						}
					}
				}
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = ThresImage1;
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->tienetresholding=false;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
				for(y=0; y<N; y++){
					for(x=0; x<M; x++){
						if(Vnueva1->MatrizImagen[x,y]==255)
							Vnueva1->MatrizImagen[x,y]=0;
						else
							Vnueva1->MatrizImagen[x,y]=255;
					}
				}
				ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva2->MatrizImagen = Vnueva1->MatrizImagen;
				Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
				Vnueva2->aColores = false;
				Vnueva2->tienetresholding=true;
				Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
				Vnueva2->MdiParent = this;
				Vnueva2->Show();
			}
		}

	private: System::Void Linking_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			if (V != nullptr && V->aColores == false && V->tienetresholding==true)
			{
				ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				Vnueva->MatrizImagen = UnirLineas2(V->MatrizImagen);
				Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				Vnueva->aColores = false;
				Vnueva->tienetresholding=true;
				Vnueva->Size::set(Vnueva->Imagen->Size::get());
				Vnueva->MdiParent = this;
				Vnueva->Show();
			}
		}

	private: System::Void Linking2_Click(System::Object^  sender, System::EventArgs^  e)
		{
			UnirLineasGW();
		}

	private: System::Void mexHatImagenChicoToolStripMenuItem_Click(System::Object^sender, System::EventArgs^e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray;
					 NewImArray = PasaraUnsignedChar(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
					 cli::array<unsigned char, 2>^ NewImArray2;
					 NewImArray2 = ThresholdINTchiki(AplicarMexicanINT(V->MatrizImagen));
					 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva2->MatrizImagen = NewImArray2;
					 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
					 Vnueva2->aColores = false;
					 Vnueva2->tienetresholding = true;
					 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
					 Vnueva2->MdiParent = this;
					 Vnueva2->Show();			
			 }		 		 
		}

	private: cli::array<unsigned char, 2>^ Sauvola (cli::array<unsigned char, 2>^ Imagen)
		 {
			 int M = Imagen->GetLength(0);
			 int N = Imagen->GetLength(1);
			 int x, y;
			 cli::array<double, 2>^ Integral = gcnew cli::array<double, 2>(M,N);
			 cli::array<double, 2>^ Integral2 = gcnew cli::array<double, 2>(M,N);
			 cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);
			 for(y=0;y<N;y++)
			 {
				 Integral[0,y]=Imagen[0,y];
				 Integral2[0,y]=Imagen[0,y]*Imagen[0,y];
				 for(x=1;x<M;x++)
				 {
					 Integral[x,y] = Integral[x-1,y]+Imagen[x,y]; 
					 Integral2[x,y] = Integral2[x-1,y]+Imagen[x,y]*Imagen[x,y]; 
				 }
			 }
			 for(x=M-1;x>=0;x--)
			 {
				 for(y=1;y<N;y++)
				 {
					 Integral[x,y] += Integral[x,y-1]; 
					 Integral2[x,y] += Integral2[x,y-1]; 
				 }
			 }
			 int w = 15;
			 int mw = 7;
			 double k = 0.02; // rango 0.2 a 0.5
			 double mean, desv;
			 unsigned char t;
			  for(y=mw; y<N-mw; y++)
			  {
				  for (x=mw; x<M-mw; x++)
				  {
					  mean = (Integral[x+mw,y+mw]+Integral[x-mw,y-mw]-Integral[x-mw,y+mw]-Integral[x+mw,y-mw])/(w*w);
					  desv = (Integral2[x+mw,y+mw]+Integral2[x-mw,y-mw]-Integral2[x-mw,y+mw]-Integral2[x+mw,y-mw])/(w*w);
					  desv = System::Math::Sqrt(desv - mean*mean);
					  t = safe_cast<unsigned char>(mean*(1.0+k*(desv/128.0-1)));
					  if (Imagen[x,y]<=t)
						  AuxArray[x,y] = 0;
					  else
						  AuxArray[x,y] = 255;
				  }
			  }
			 return AuxArray;
		 }

	private: cli::array<unsigned char, 2>^ SauvolaINT (cli::array<int, 2>^ Imagen)
		 {
			 int M = Imagen->GetLength(0);
			 int N = Imagen->GetLength(1);
			 int x, y;
			 cli::array<double, 2>^ Integral = gcnew cli::array<double, 2>(M,N);
			 cli::array<double, 2>^ Integral2 = gcnew cli::array<double, 2>(M,N);
			 cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);

			 for(y=0;y<N;y++)
			 {
				 Integral[0,y]=Imagen[0,y];
				 Integral2[0,y]=Imagen[0,y]*Imagen[0,y];
				 for(x=1;x<M;x++)
				 {
					 Integral[x,y] = Integral[x-1,y]+Imagen[x,y]; 
					 Integral2[x,y] = Integral2[x-1,y]+Imagen[x,y]*Imagen[x,y]; 
				 }
			 }
			 for(x=M-1;x>=0;x--)
			 {
				 for(y=1;y<N;y++)
				 {
					 Integral[x,y] += Integral[x,y-1]; 
					 Integral2[x,y] += Integral2[x,y-1]; 
				 }
			 }

			 int w = 33;
			 int mw = 16;
			 double k = -0.2; // rango 0.2 a 0.5
			 double mean, desv;
			 unsigned char t;
			  for(y=mw; y<N-mw; y++)
			  {
				  for (x=mw; x<M-mw; x++)
				  {
					  mean = (Integral[x+mw,y+mw]+Integral[x-mw,y-mw]-Integral[x-mw,y+mw]-Integral[x+mw,y-mw])/(w*w);
					  desv = (Integral2[x+mw,y+mw]+Integral2[x-mw,y-mw]-Integral2[x-mw,y+mw]-Integral2[x+mw,y-mw])/(w*w);
					  desv = System::Math::Sqrt(desv - mean*mean);
					  t = safe_cast<int>(mean*(1.0+k*(desv/128.0-1)));
					  if (Imagen[x,y]<=t)
						  AuxArray[x,y] = 0;
					  else
						  AuxArray[x,y] = 255;
				  }
			  }
			 
			 return AuxArray;

		 }

	private: System::Void thresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray;
					 NewImArray = Sauvola(V->MatrizImagen);
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding = true;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();			
			 }		 		 		 
		}

	private: System::Void mexHatImagenSauvolaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
				 cli::array<unsigned char, 2>^ NewImArray;
				 cli::array<double, 2>^ MaskArray = {
						 {0.0,0.0,-1.0,0.0,0.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {-1.0,-2.0,16.0,-2.0,-1.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {0.0,0.0,-1.0,0.0,0.0} };
				 NewImArray = PasaraUnsignedChar(AplicarMascaraINT(V->MatrizImagen, MaskArray));
				 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->tienetresholding = false;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();
				 cli::array<unsigned char, 2>^ NewImArray2;
				 NewImArray2 = SauvolaINT(AplicarMascaraINT(V->MatrizImagen, MaskArray));
				 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva2->MatrizImagen = NewImArray2;
				 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
				 Vnueva2->aColores = false;
				 Vnueva2->tienetresholding = true;
				 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
				 Vnueva2->MdiParent = this;
				 Vnueva2->Show();
			 }		 
		 }

	private: int Kittler (cli::array<int>^ h, int min, int max)
		{
			 int T;
			 int n = h->GetLength(0);
			 int x, y, p1, p2, u1, u2;
			 p1 = p2 = u1 = u2 = 0;
			 double s1, s2;
			 s1 = s2 = 0.0;
			 int t0 = min+(max-min)/4;
			 int t1 = max-(max-min)/4;
			 cli::array<double>^ J = gcnew cli::array<double>(t1-t0+1);
			 for(y=t0;y<t1;y++)
			 {
				 T = y;
				 for(x=0;x<=T;x++)
				 {
					 p1 += h[x];
					 u1 += h[x]*x;
				 }
				 for(x=T+1;x<n;x++)
				 {
					 p2 += h[x];
					 u2 += h[x]*x;
				 }
				 u1 /= p1;
				 u2 /= p2;
				 for(x=0;x<=T;x++)
				 {
					 s1 += (x-u1)*(x-u1)*h[x];
				 }
				 for(x=T+1;x<n;x++)
				 {
					 s2 += (x-u2)*(x-u2)*h[x];
				 }
				 s1 = System::Math::Sqrt(s1/p1);
				 s2 = System::Math::Sqrt(s2/p2);
				 J[y-t0] = 1+2*(p1*System::Math::Log10(s1)+p2*System::Math::Log10(s2))-2*(p1*System::Math::Log10(p1)+p2*System::Math::Log10(p2));
			 }
			 double minT = J[0];
			 int indT = 0;
			 for(y=1;y<t1-t0+1;y++)
			 {
				 if(J[y]<minT)
				 {
					 minT = J[y];
					 indT = y;
				 }
			 }
			 T = t0+y;
			 return T;
		}

	private: System::Void mexHatImagenKittlerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
					 cli::array<unsigned char, 2>^ NewImArray;
					 cli::array<double, 2>^ MaskArray = { 
						 {0.0,0.0,-1.0,0.0,0.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {-1.0,-2.0,19.0,-2.0,-1.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {0.0,0.0,-1.0,0.0,0.0} };
					 NewImArray = PasaraUnsignedChar(AplicarMascaraINT(V->MatrizImagen, MaskArray));
					 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva->MatrizImagen = NewImArray;
					 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
					 Vnueva->aColores = false;
					 Vnueva->tienetresholding = false;
					 Vnueva->Size::set(Vnueva->Imagen->Size::get());
					 Vnueva->MdiParent = this;
					 Vnueva->Show();	

					  cli::array<unsigned char, 2>^ NewImArray2;
					  NewImArray2 = PasaraUnsignedChar(AplicarMascaraINT(V->MatrizImagen, MaskArray));
					  int M = NewImArray2->GetLength(0);
					  int N = NewImArray2->GetLength(1);
					  int m = 80; // tiene que ser multiplo de 640x480 por ejemplo.
					  int n = 40; // idem
					  int T;
					  int x, y;
					  int i, j;
					  int a, b;
					  int max, min;
					  cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
					  cli::array<int>^ histo = gcnew cli::array<int>(256);
					  for(y=0; y<=(N-n); y+=n)
					  {
						  for (x=0; x<=(M-m); x+=m)
						  {
							  max=NewImArray2[x,y];
							  min=NewImArray2[x,y];
							  for (j=0; j<n; j++)
							  {
								  for(i=0; i<m; i++)
								  {
									  a=x+i;
									  b=y+j;
									  if (NewImArray2[a,b]>max)
										  max=NewImArray2[a,b];
									  if (NewImArray2[a,b]<min)
										  min=NewImArray2[a,b];
									  histo[NewImArray2[a,b]]++;
								  }
							  }
							  T = Kittler(histo, min, max);
							  for (j=0; j<n; j++)
							  {
									  for(i=0; i<m; i++)
									  {
										  a=x+i;
										  b=y+j;
										  //if (NewImArray2[a,b]+16*255>T)
										  if (NewImArray2[a,b]>T)
											  AuxArray[a,b] = 255;
										  else
											  AuxArray[a,b] = 0;
									  }
							   }
						  }
					  }
					 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
					 Vnueva2->MatrizImagen = AuxArray;
					 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
					 Vnueva2->aColores = false;
					 Vnueva2->tienetresholding = true;
					 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
					 Vnueva2->MdiParent = this;
					 Vnueva2->Show();	
			 }			 
		}

	private: System::Void mexHToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			 ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			 if (V != nullptr && V->aColores == false)
			 {
				 cli::array<unsigned char, 2>^ NewImArray;
				 cli::array<double, 2>^ MaskArray = {
						 {0.0,0.0,-1.0,0.0,0.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {-1.0,-2.0,19.0,-2.0,-1.0},
						 {0.0,-1.0,-2.0,-1.0,0.0},
						 {0.0,0.0,-1.0,0.0,0.0} };
				 NewImArray = PasaraUnsignedChar(AplicarMascaraINT(V->MatrizImagen, MaskArray));
				 ProgramaTFGv1::VentanaImagen^ Vnueva = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva->MatrizImagen = NewImArray;
				 Vnueva->establecerImagen(this->MatrizAImagen(Vnueva->MatrizImagen));
				 Vnueva->aColores = false;
				 Vnueva->tienetresholding = false;
				 Vnueva->Size::set(Vnueva->Imagen->Size::get());
				 Vnueva->MdiParent = this;
				 Vnueva->Show();
				 cli::array<unsigned char, 2>^ NewImArray2;
				 NewImArray2 = PasaraUnsignedChar(AplicarMascaraINT(V->MatrizImagen, MaskArray));
				 int M = NewImArray2->GetLength(0);
				 int N = NewImArray2->GetLength(1);
				 int m = 15; // tiene que ser multiplo de 640x480 por ejemplo.
				 int n = 15; // idem
				 int T;
				 int x, y;
				 int i, j;
				 int a, b;
				 int max, min;
				 cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M, N);
				 for(y=0; y<N; y++)
				 {
					 for (x=0; x<M; x++)
					 {
						 cli::array<int>^ histo = gcnew cli::array<int>(256);
						 max=NewImArray2[x,y];
						 min=NewImArray2[x,y];
						 for (j=0; j<n; j++)
						 {
							 for(i=0; i<m; i++)
							 {
								 a=x+i-(m-1)/2;
								 b=y+j-(n-1)/2;
								 if (a>=0 && a<M && b>=0 && b<N)
								 {
									 if (NewImArray2[a,b]>max)
										 max=NewImArray2[a,b];
									 if (NewImArray2[a,b]<min)
										 min=NewImArray2[a,b];
									 histo[NewImArray2[a,b]]++;
								 }
							 }
						 }
						 T = Kittler(histo, min, max);
						 if (NewImArray2[x,y]>T)
							 AuxArray[x,y] = 255;
						 else
							 AuxArray[x,y] = 0;
					 }
				 }
				 ProgramaTFGv1::VentanaImagen^ Vnueva2 = gcnew ProgramaTFGv1::VentanaImagen();
				 Vnueva2->MatrizImagen = AuxArray;
				 Vnueva2->establecerImagen(this->MatrizAImagen(Vnueva2->MatrizImagen));
				 Vnueva2->aColores = false;
				 Vnueva2->tienetresholding = true;
				 Vnueva2->Size::set(Vnueva2->Imagen->Size::get());
				 Vnueva2->MdiParent = this;
				 Vnueva2->Show();
			 }			 
		}

	private: cli::array<unsigned char, 2>^ ExtraccionHSI () {	
		float limiteH = 360.0;
		float limiteS = 1.0;
		float limiteI = 0.14;
		float mediaH, mediaS, mediaI;
		int x,y;
		int bandera=0;
		raiz=0;
		int nroblob, raiznueva;
		int M = Imagen->Width;
		int N = Imagen->Height;
		blobs = gcnew cliext::list<Blob^>();
		cli::array<float, 2>^ MatrizH = gcnew cli::array<float, 2>(M,N);
		cli::array<float, 2>^ MatrizS = gcnew cli::array<float, 2>(M,N);
		cli::array<float, 2>^ MatrizI = gcnew cli::array<float, 2>(M,N);
		for(y=0; y<N; y++)
		{
			for (x=0; x<M; x++)
			{
				MatrizH[x,y] = Imagen->GetPixel(x,y).GetHue();
				MatrizS[x,y] = Imagen->GetPixel(x,y).GetSaturation();
				MatrizI[x,y] = Imagen->GetPixel(x,y).GetBrightness();
			}
		}
		y=0;
		x=0;
		while(x<M)
		{
			mediaH = mediaS = mediaI= 0.0;
			Blob^ blob = gcnew Blob();
			Estructuras::Run^ run = gcnew Estructuras::Run();
			run->r=y;
			run->c1=x;
			if(x<M-1)
			{
				while((System::Math::Abs(MatrizH[x+1,y]-MatrizH[x,y])<limiteH || System::Math::Abs(System::Math::Abs(MatrizH[x+1,y]-MatrizH[x,y])-360.0)<limiteH) &&
					  System::Math::Abs(MatrizS[x+1,y]-MatrizS[x,y])<limiteS &&
					  System::Math::Abs(MatrizI[x+1,y]-MatrizI[x,y])<limiteI )
				{
					mediaH+=MatrizH[x,y];
					mediaS+=MatrizS[x,y];
					mediaI+=MatrizI[x,y];
					x++;
					if(x==M-1)
						break;
				}
			}
			run->c2=x;
			blob->parent = raiz;
			raiz++;
			blob->pixeles=run->c2-run->c1+1;
			blob->mediaH=(mediaH+MatrizH[x,y])/blob->pixeles;
			blob->mediaS=(mediaS+MatrizS[x,y])/blob->pixeles;
			blob->mediaI=(mediaI+MatrizI[x,y])/blob->pixeles;
			blob->listaderuns = gcnew cliext::list<Run^>();
			blob->listaderuns->push_back(run);
			blobs->push_back(blob);
			x++;
		}
		y++;
			while (y<N)
			{
				x=0;
				while(x<M)
				{
						mediaH = mediaS = mediaI= 0.0;
						Estructuras::Run^ run = gcnew Estructuras::Run();
						run->r=y;
						run->c1=x;
						if(x<M-1)
						{
							while((System::Math::Abs(MatrizH[x+1,y]-MatrizH[x,y])<limiteH || System::Math::Abs(System::Math::Abs(MatrizH[x+1,y]-MatrizH[x,y])-360.0)<limiteH) &&
								   System::Math::Abs(MatrizS[x+1,y]-MatrizS[x,y])<limiteS &&
								   System::Math::Abs(MatrizI[x+1,y]-MatrizI[x,y])<limiteI )
							{
								mediaH+=MatrizH[x,y];
								mediaS+=MatrizS[x,y];
								mediaI+=MatrizI[x,y];
								x++;
								if(x==M-1)
									break;
							}
						}
						run->c2=x;
						mediaH=(mediaH+MatrizH[x,y])/(run->c2-run->c1+1);
						mediaS=(mediaS+MatrizS[x,y])/(run->c2-run->c1+1);
						mediaI=(mediaI+MatrizI[x,y])/(run->c2-run->c1+1);
						bandera=0;
						nroblob=0;
						for each (Blob^ blob in blobs)
						{
							cliext::list<Estructuras::Run^>::iterator iter = blob->listaderuns->end();
							iter--;
							while (iter->r>=(y-1))
							{
								if (((run->c1<iter->c1 && run->c2>=iter->c1) || (run->c1>=iter->c1 && run->c1<=iter->c2)) // D4
								//if (((run->c1<iter->c1 && (run->c2+1)>=iter->c1) || (run->c1>=iter->c1 && (run->c1-1)<=iter->c2)) // D8
									&& System::Math::Abs(blob->mediaH-mediaH)<limiteH
									&& System::Math::Abs(blob->mediaS-mediaS)<limiteS
									&& System::Math::Abs(blob->mediaI-mediaI)<limiteI ) 
								{
									if (bandera==0)
									{
										blob->listaderuns->push_back(run);
										blob->pixeles+=run->c2-run->c1+1;
										blob->mediaH =(blob->mediaH+mediaH)/2;
										blob->mediaS =(blob->mediaS+mediaS)/2;
										blob->mediaI =(blob->mediaI+mediaI)/2;
										raiznueva=blob->parent;
										bandera=1;
									}								
									if (bandera==1)
									{
										blob->parent=raiznueva;
									}
								}
								if(iter!=blob->listaderuns->begin())
								iter--;
								else
									break;
							}
							nroblob++;
						}
						if (bandera==0)
						{
							Blob^ blobnuevo = gcnew Blob();
							blobnuevo->parent = raiz;
							raiz++;
							blobnuevo->mediaH = mediaH;
							blobnuevo->mediaS = mediaS;
							blobnuevo->mediaI = mediaI;
							blobnuevo->pixeles=run->c2-run->c1+1;
							blobnuevo->listaderuns = gcnew cliext::list<Run^>();
							blobnuevo->listaderuns->push_back(run);
							blobs->push_back(blobnuevo);
						}
					x++;
				}
				y++;
			}
		// Lo sgte es solo para visualizar		
		cliext::vector<int>^ raices = gcnew cliext::vector<int>();
		cli::array<unsigned char, 2>^ NewArray = gcnew cli::array<unsigned char, 2>(M,N);
		nroblob=0;
		for each (Blob^ blob in blobs)
		{
			int r=nroblob;
			raices->push_back(blob->parent);
			while(raices[r]!=r)
				r = raices[r];
			for each (Estructuras::Run^ run in blob->listaderuns)
			{
				for(x=run->c1;x<=run->c2;x++)
					NewArray[x,run->r]=safe_cast<unsigned char>(20*(r+1));
			}
			nroblob++;
		}	
		// para saber el numero de elementos conectados
		nroblob=0;
		cantelemconec=0;
		for each(int aux in raices)
		{
			if(aux==nroblob)
				cantelemconec++;
			nroblob++;
		}
		return NewArray;
	}


	private: void MexicanColor ()
		{
			int x,y;
			int M = Imagen->Width;
			int N = Imagen->Height;
			
			cli::array<System::Drawing::Color, 2>^ ImagenAux = gcnew cli::array<System::Drawing::Color, 2>(M,N);
			for(y=0; y<N; y++)
			{
				for(x=0; x<M; x++)
				{
						ImagenAux[x,y] = Imagen->GetPixel(x,y);
				}
			}
			 cli::array<double, 2>^ MaskArray = {
				 {-1,-1,-1},
				 {-1,8,-1},
				 {-1,-1,-1} };
			 int m = MaskArray->GetLength(0);
			 int n = MaskArray->GetLength(1);
			 int i, j, a ,b;
			 for(y=0; y<N; y++){
				 for(x=0; x<M; x++){
					 int red =0;
					 int blue =0;
					 int green =0;
					 for(j=0; j<n; j++){
						 for(i=0; i<m; i++){
							 a=x+i-(m-1)/2;
							 b=y+j-(n-1)/2;
							 if((a>=0 && a<M) && (b>=0 && b<N))
							 {
								 red+=safe_cast<int>(ImagenAux[a,b].R*MaskArray[i,j]/(m*n));
								 blue+=safe_cast<int>(ImagenAux[a,b].B*MaskArray[i,j]/(m*n));
								 green+=safe_cast<int>(ImagenAux[a,b].G*MaskArray[i,j]/(m*n));
							 }
						 }
					 }
					 System::Drawing::Color coloraux;
					 coloraux = coloraux.FromArgb(safe_cast<unsigned char>(red),safe_cast<unsigned char>(green),safe_cast<unsigned char>(blue));
					 Imagen->SetPixel(x, y, coloraux);
				 }
			 }
		}

	private: System::Void mexicanColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			ProgramaTFGv1::VentanaImagen^ V = safe_cast<ProgramaTFGv1::VentanaImagen^>(this->ActiveMdiChild);
			if (V != nullptr && V->aColores == true)
			{
				 MexicanColor();
				 V->Invalidate();
			}
		}

};
}


#pragma once

#include "Rectangulo.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ProgramaTFGv1 {

	/// <summary>
	/// Resumen de VentanaImagen
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class VentanaImagen : public System::Windows::Forms::Form
	{
	public:
		VentanaImagen(void)
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
		~VentanaImagen()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>

		Point firstPoint, lastPoint;
		bool drawing;
		bool vergrises;	
		Rectangulo^ rectanguloTemp;

		System::ComponentModel::Container ^components;
	
	public:  System::Drawing::Bitmap^ Imagen;
			 cli::array<unsigned char, 2>^ MatrizImagen;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	public:  bool aColores;
	public:  bool tienetresholding;

	public:  System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 244);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(292, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(109, 17);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// VentanaImagen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->statusStrip1);
			this->Name = L"VentanaImagen";
			this->Text = L"VentanaImagen";
			this->Load += gcnew System::EventHandler(this, &VentanaImagen::VentanaImagen_Load);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaImagen::VentanaImagen_MouseUp);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VentanaImagen::VentanaImagen_Paint);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaImagen::VentanaImagen_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaImagen::VentanaImagen_MouseMove);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

    public: void establecerImagen (System::Drawing::Bitmap^ Imagen){
				this->Imagen = Imagen;
				this->BackgroundImage::set(this->Imagen);
			}

	private: System::Void VentanaImagen_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void VentanaImagen_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;
			 if(rectanguloTemp!=nullptr)
				 rectanguloTemp->DibujarRectangulo(g);		 
			 }

    private: System::Void VentanaImagen_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if (e->Button == System::Windows::Forms::MouseButtons::Left && aColores==false)
			 {
				 drawing = true;
				 firstPoint = e->Location;
				 this->toolStripStatusLabel1->Text = L"Posicion inicial del cursor (x,y) = "+ e->Location.X + "," + e->Location.Y;
			 }
			 if (e->Button == System::Windows::Forms::MouseButtons::Right && aColores==false)
			 {
				 vergrises=true;
			 }
			 }

    private: System::Void VentanaImagen_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(drawing)
			 {
				 rectanguloTemp = gcnew Rectangulo(firstPoint, e->Location);
				 this->toolStripStatusLabel1->Text = L"Tamano de rectangulo = " + (1+rectanguloTemp->boundRect.Width) + "x" + (1+rectanguloTemp->boundRect.Height);
				 this->Invalidate();
			 }
			 if (vergrises)
				 if (aColores==false && e->X>=0 && e->X<MatrizImagen->GetLength(0) && e->Y>=0 && e->Y<MatrizImagen->GetLength(1))
					 this->toolStripStatusLabel1->Text = L"Gris del pixel = " + MatrizImagen[e->X,e->Y]+L"   Pos = "+e->X+L","+e->Y;
			 }

	private: System::Void VentanaImagen_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 vergrises=false;
			 if(!drawing)
				 return;
			 
			 if (rectanguloTemp && aColores==false)
			 {
				 int x, y;
				 int z=0;
				 double media = 0.0;
				 double desv = 0.0;

				 for (y=rectanguloTemp->boundRect.Y;y<=rectanguloTemp->boundRect.Bottom;y++)
				 {
					 for (x=rectanguloTemp->boundRect.X;x<=rectanguloTemp->boundRect.Right;x++)
					{
						media += safe_cast<double>(this->MatrizImagen[x,y]);
						z++;
					}
				 }

				 media /= z;

				 for (y=rectanguloTemp->boundRect.Y;y<=rectanguloTemp->boundRect.Bottom;y++)
				 {
					 for (x=rectanguloTemp->boundRect.X;x<=rectanguloTemp->boundRect.Right;x++)
					{
						desv += (safe_cast<double>(this->MatrizImagen[x,y])-media)*(safe_cast<double>(this->MatrizImagen[x,y])-media);
					 }
				 }
				 
				 desv = System::Math::Sqrt(desv/z);
				 toolStripStatusLabel1->Text = L"Posicion final del cursor (x,y) = "+ e->Location.X + "," + e->Location.Y + L"   Media = " + media + L"   Desviacion = "+desv; //+ L" Last pixel color " + Matriz[rectanguloTemp->position.X+rectanguloTemp->width,rectanguloTemp->position.Y-27+rectanguloTemp->height];
				 media = 0.0;
					 
				 rectanguloTemp = nullptr;
				 this->Invalidate();
			 }
			 drawing = false;
		 }
};
}

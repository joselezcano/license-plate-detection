// ProgramaTFGv1.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "VentanaImagen.h"
#include "Form1.h"

using namespace ProgramaTFGv1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ning�n control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Crear la ventana principal y ejecutarla
	Application::Run(gcnew Form1());
	return 0;
}

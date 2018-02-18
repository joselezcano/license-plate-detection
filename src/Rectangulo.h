// Rectangulo.h
// Rectangulo para ventana extractora de atributos

using namespace System;
using namespace System::Drawing;

public ref class Rectangulo
	{
		public:
			int width;
			int height;
			Pen^ pen;
			Point position;
			Color colordelpen;
			System::Drawing::Rectangle boundRect;

		public:
			Rectangulo (Point p1, Point p2)
			{
				colordelpen = Color::Blue;
				pen = gcnew Pen(colordelpen);
				position = Point (Math::Min(p1.X, p2.X), Math::Min(p1.Y, p2.Y));
				width = Math::Abs(p1.X - p2.X);
				height =  Math::Abs(p1.Y - p2.Y);
				boundRect = System::Drawing::Rectangle(position, Size(width, height));
				if (boundRect.Width < 2) boundRect.Width = 2;
				if (boundRect.Height < 2) boundRect.Height = 2;
			}

			void DibujarRectangulo(Graphics^ g)
			{
				g->DrawRectangle(pen, boundRect);
			}
	};
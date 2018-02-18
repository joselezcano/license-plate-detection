#pragma once
#include <cliext/vector>

namespace Estructuras {

	ref struct Clasificador{
			Clasificador (void): a(0), b(0), xmax(0), xmin(0), ymax(0), ymin(0), Xymax(0), Xymin(0), Yxmax(0), Yxmin(0) {}
			Clasificador(const Clasificador% t) : a(t.a), b(t.b) // Copy constructor
			{
			} 
			Clasificador% operator=(const Clasificador% p) // Assignment operator
			{
			// Function body...
				if(this != %p)
				{
				a = p.a;
				b = p.b;
				xmax = p.xmax;
				xmin = p.xmin;
				ymax = p.ymax;
				ymin = p.ymin;
				Xymax = p.Xymax;
				Xymin = p.Xymin;
				Yxmax = p.Yxmax;
				Yxmin = p.Yxmin;
				}
				return *this;
			}
			~Clasificador() // Destructor
			{
			// Function body...
			}
			int a, b, xmax, xmin, ymax, ymin, Xymax, Xymin, Yxmax, Yxmin;
    };

}
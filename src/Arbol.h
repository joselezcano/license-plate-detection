// Arbol.h para extraer regiones rapidamente

#pragma once

#include <cliext/list>
#include <cliext/vector>

namespace Estructuras {

	ref struct Run {
			Run (void): r(0), c1(0), c2(0) {}
			Run(const Run% t) : r(t.r), c1(t.c1), c2(t.c2) // Copy constructor
			{
			} 
			Run% operator=(const Run% p) // Assignment operator
			{
			// Function body...
				if(this != %p)
				{
				r = p.r;
				c1 = p.c1;
				c2 = p.c2;
				}
				return *this;
			}
			~Run() // Destructor
			{
			// Function body...
			}
			int r, c1, c2;
    };


	ref struct Blob{
			Blob (void): parent(0), pixeles(0), mediaH(0), mediaS(0), mediaI(0), listaderuns(nullptr) {}
			Blob(const Blob% t) : parent(t.parent), pixeles(t.pixeles), mediaH(t.mediaH), mediaS(t.mediaS), mediaI(t.mediaI), listaderuns(t.listaderuns) // Copy constructor
			{
			} 
			Blob% operator=(const Blob% p) // Assignment operator
			{
			// Function body...
				if(this != %p)
				{
				parent = p.parent;
				pixeles = p.pixeles;
				}
				return *this;
			}
			~Blob() // Destructor
			{
			// Function body...
			}
			int parent, pixeles;
			float mediaH, mediaS, mediaI;
			cliext::list<Run^>^ listaderuns;
    };

    ref struct Letras{
			Letras (void): x0(0), y0(0), largo(0), ancho(0), area(0), xmax(0), xmin(0), ymax(0), ymin(0), region(nullptr) {}
			Letras(const Letras% t) : x0(t.x0), y0(t.y0), largo(t.largo), ancho(t.ancho), area(t.area), xmax(t.xmax), xmin(t.xmin), ymax(t.ymax), ymin(t.ymin), region(t.region) // Copy constructor
			{
			} 
			Letras% operator=(const Letras% p) // Assignment operator
			{
			// Function body...
				if(this != %p)
				{
				x0 = p.x0;
				y0 = p.y0;
				largo = p.largo;
				ancho = p.ancho;
				area = p.area;
				xmax = p.xmax;
				xmin = p.xmin;
				ymax = p.ymax;
				ymin = p.ymin;
				region = p.region;
				}
				return *this;
			}
			~Letras() // Destructor
			{
			// Function body...
			}
			int  x0, y0, largo, ancho, area, xmax, xmin, ymax, ymin;
			cli::array<unsigned char, 2>^ region;
    };

	ref struct Probable{
			Probable (void): x0(0), y0(0), largo(0), ancho(0), area(0), nroletras(0), xmax(0), xmin(0), ymax(0), ymin(0), Xymax(0), Xymin(0), Yxmax(0), Yxmin(0), region(nullptr), lasletras(nullptr) {}
			Probable(const Probable% t) : x0(t.x0), y0(t.y0), largo(t.largo), ancho(t.ancho), area(t.area), nroletras(t.nroletras), xmax(t.xmax), xmin(t.xmin), ymax(t.ymax), ymin(t.ymin), Xymax(t.Xymax), Xymin(t.Xymin), Yxmax(t.Yxmax), Yxmin(t.Yxmin), region(t.region), lasletras(t.lasletras) // Copy constructor
			{
			} 
			Probable% operator=(const Probable% p) // Assignment operator
			{
			// Function body...
				if(this != %p)
				{
				x0 = p.x0;
				y0 = p.y0;
				largo = p.largo;
				ancho = p.ancho;
				area = p.area;
				xmax = p.xmax;
				xmin = p.xmin;
				ymax = p.ymax;
				ymin = p.ymin;
				Xymax = p.Xymax;
				Xymin = p.Xymin;
				Yxmax = p.Yxmax;
				Yxmin = p.Yxmin;
				region = p.region;
				nroletras = p.nroletras;
				lasletras = p.lasletras;
				}
				return *this;
			}
			~Probable() // Destructor
			{
			// Function body...
			}
			int  x0, y0, largo, ancho, area, nroletras, xmax, xmin, ymax, ymin, Xymax, Xymin, Yxmax, Yxmin;
			cli::array<unsigned char, 2>^ region;
			cliext::vector<Letras^>^ lasletras;
    };

}

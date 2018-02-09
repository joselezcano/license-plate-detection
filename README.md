# License Plate Detection
This repository is a review of some Image Processing techniques and interesting heuristics to detect license plates.
Code snippets were written in C++/CLI, since this application was originally developed in Microsoft Visual C++.

## Working with images in grayscale
Although cameras provide colorful images, it is faster to work with grayscale images since we do not need to manipulate 3 color channels (RGB) at any processing step. Also, color may not be a good feature to filter candidates due to the high probability of finding objects with similar hue in a given scene.

<img src="image1.jpeg?raw=true" alt="Color image" height="220" width="294"> <img src="image2.png?raw=true" alt="Grayscale image" height="220" width="294">

Next, a function to convert a color image to its grayscale version according to ITU BT.709:

```c++
private: array<unsigned char, 2>^ toGrayscale (System::Drawing::Bitmap^ Image) {
   int x, y;
   double r, g, b;
   // Store pixels in a two-dimensional image array
   array<unsigned char, 2>^ ImArray = gcnew array<unsigned char, 2>(Image->Width, Image->Height);
   for (y=0;y<Image->Height;y++) {
      for (x=0;x<Image->Width;x++) {
        // Obtain red, blue and green components
        r = safe_cast<double> (Image->GetPixel(x,y).R);
        g = safe_cast<double> (Image->GetPixel(x,y).G);
        b = safe_cast<double> (Image->GetPixel(x,y).B);
        // Convert each color pixel to its grayscale version
        ImArray [x,y] = safe_cast<unsigned char>(0.21*r + 0.71*g + 0.08*b);			
      }
   }
   return ImArray;
}
```
## Enhancing license plate borders before edge detection
It's a good idea to enhance a grayscale image before edge detection. To this end, you can use histogram equalization or another adaptive technique; however, a nice effect can be accomplished with a LoG filter (a.k.a Mexican Hat filter) which fills the gaps between worn out borders of old license plates, as depicted in the following figures:

<img src="image3.png?raw=true" alt="LoG filter" height="220" width="285"> <img src="image4.png?raw=true" alt="LoG filter" height="242" width="450">

The next function applies the Mexican Hat filter to the grayscale image:

```c++
private: cli::array<unsigned char, 2>^ ApplyMexicanHat (cli::array<unsigned char, 2> ^ ImArray){
  int M = ImArray->GetLength(0);
  int N = ImArray->GetLength(1);
  cli::array<double, 2>^ MaskArray = { 
                                       { 0.0, 0.0, -1.0, 0.0, 0.0},
                                       { 0.0,-1.0, -2.0,-1.0, 0.0},
                                       {-1.0,-2.0, 16.0,-2.0,-1.0},
                                       { 0.0,-1.0, -2.0,-1.0, 0.0},
                                       { 0.0, 0.0, -1.0, 0.0, 0.0} };
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
  /* The remaining code adjusts the filtered image so that we can take a look at it.
     However, remember to comment these lines before going to the next detection step */
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
```

Note that the Mexican Hat filter has zero mean and the resulting image pixel value may extend beyond the range [0,255]. For display purpose, the previous code normalizes each pixel to have an intensity value in the former range.

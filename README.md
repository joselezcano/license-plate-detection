# License Plate Detection
This repository is a review of some Image Processing techniques and interesting heuristics to detect license plates.
Code snippets were written in C++/CLI, since this application was originally developed in Microsoft Visual C++.

## Working with images in grayscale
Although cameras provide colorful images, it is faster to work with grayscale images since we do not need to manipulate 3 color channels (RGB) at any processing step. Also, color may not be a good feature to filter candidates due to the high probability of finding objects with similar hue in a given scene.

<img src="image1.jpeg?raw=true" alt="Color image" height="220" width="294"> <img src="image2.png?raw=true" alt="Grayscale image" height="220" width="294">

Next, a function to convert a color image to its grayscale version according to ITU BT.709:

```c++
private: array<unsigned char, 2>^ ToGrayscale (System::Drawing::Bitmap^ Image){
   int x, y;
   double r, g, b;
   // Store pixels in a two-dimensional image array
   array<unsigned char, 2>^ ImArray = gcnew array<unsigned char, 2>(Image->Width, Image->Height);
   for (y = 0; y < Image->Height; y++){
      for (x = 0; x < Image->Width; x++){
        // Obtain red, blue and green components
        r = safe_cast<double> (Image->GetPixel(x,y).R);
        g = safe_cast<double> (Image->GetPixel(x,y).G);
        b = safe_cast<double> (Image->GetPixel(x,y).B);
        // Convert each color pixel to its grayscale version
        ImArray[x,y] = safe_cast<unsigned char>(0.21*r + 0.71*g + 0.08*b);			
      }
   }
   return ImArray;
}
```
## Enhancing license plate borders before detection
It's a good idea to enhance a grayscale image before detecting an object. To this end, you can use histogram equalization or another adaptive technique; however, a nice effect can be accomplished with a Laplacian of Gaussian (LoG) filter which fills the gaps between worn out borders of old license plates, as depicted in the following figures:

<img src="image3.png?raw=true" alt="LoG filter" height="220" width="285"> <img src="image4.png?raw=true" alt="LoG filter" height="242" width="450">

The figure on the left is a side view of the LoG filter (a.k.a Mexican Hat filter). Figure a) is a license plate with red borders (as used in Paraguay), figure b) is the grayscale version of the color image, and figure c) is the LoG-filtered image.
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
  for(y = 0; y < N; y++){
    for(x = 0; x < M; x++){
      AuxArray[x,y]=0;
      for(j = 0; j < n; j++){
        for(i = 0; i < m; i++){
          a = x + i - (m - 1)/2;
	  b = y + j - (n - 1)/2;
	  if((a >= 0 && a < M) && (b >= 0 && b < N))
	    AuxArray[x,y] += safe_cast<double>(MaskArray[i,j] * ImArray[a,b]);
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
  for(y = 0; y < N; y++){
    for(x = 0; x < M; x++){
      NewImArray[x,y] = safe_cast<unsigned char>((AuxArray[x,y] - auxmin)/(auxmax - auxmin)*255.0);
    }
  }
  return NewImArray;
}
```

Note that the Mexican Hat filter has zero mean and the resulting image pixel value may extend beyond the range [0,255]. For display purpose, the previous code normalizes each pixel to have an intensity value in the former range. As a result, we get the following picture which looks a bit opaque due to normalization:

<img src="image5.png?raw=true" alt="Grayscale image" height="220" width="294">

## Turn the filtered image into a binary image
After enhancing a grayscale image, you can turn it into 1s and 0s (i.e pixel values of 255 and 0) to start segmenting the image. An simple way to map a gray pixel to black or white is to compare it with a threshold (e.g. 150), but this method does not perform well when parts of an image differ in their local intensities. An adaptive algorithm would consider a neighborhood around the current pixel ('pixel actual' in Spanish) to decide which threshdold is the most suitable in each region of the image. 

<img src="image6.png?raw=true" alt="Grayscale image" height="220" width="294">

The following algorithm starts with a threshold of 150, then calculates a mean for dark and bright pixels, updates the threshold to the mid-point between those means, and keeps iterating until the threshold converges to an appropiate value.

```c++
private: cli::array<unsigned char, 2>^ ToBinary (cli::array<unsigned char, 2>^ Image){
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  int m = 33; // neighborhood width
  int n = 33; // neighborhood height
  int T = 150; // initial threshold
  int t =0;
  int x, y;
  int i, j;
  int a, b;
  int count;
  int u1, u2;
  cli::array<unsigned char, 2>^ BinaryArray = gcnew cli::array<unsigned char, 2>(M, N);
  for(y = 0; y < N; y++){
    for (x = 0; x < M; x++){
      while(T != t){
        t = T;
        count = 0;
        u1 = u2 = 0;
        for (j = 0; j < n; j++){
          for(i = 0; i < m; i++){
            a = x + i - (m - 1)/2;
            b = y + j - (n - 1)/2;
	    if (a >= 0 && a <= M && b >= 0 && b <= N){
	      if (Image[a,b] > t){
	        u1 += Image[a,b];
		count++;
	      } else {
	        u2 += Image[a,b];
	      }
	    }
	  }
        }
	if (count > 0)
	  if(count < m * n)
	    T = (u1/count + u2/(m * n - count))/2;
	  else
	    T = u1/(2 * count);
	else
	  T = u2/(2 * m * n);
      }
      if (Image[x,y] > T)
        BinaryArray[x,y] = 255;
      else
        BinaryArray[x,y] = 0;
    }
  }
  return BinaryArray;
}
```

The new binary image is shown next.

<img src="image7.png?raw=true" alt="Grayscale image" height="220" width="294">

## Extract connected components
The next step in detecting an object inside an image is to segment it in its components. Connected pixels define an isolated region that may represent a meaningful part of an image (or just a cluster of pixels). The following function implements a fast algorithm to label connected components:

```c++
cli::array<unsigned char, 2>^ ExtractConnectedComponents (cli::array<unsigned char, 2>^ Image){
  int x, y;
  int i = 0;
  int label = 0; // label ID
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);
  cliext::vector<int>^ labels = gcnew cliext::vector<int>(M*N);
  cliext::vector<ConnectedComponent^>^ labeledCC;
  cliext::fill(labels->begin(), labels->end(), 0);
  if (Image[0,0] == 255){
    label++;
    labels[i] = label;
  }
  i++;
  for (x = 1; x < M; x++){
    if (Image[x,0] == 255){
      if(Image[x,0] == Image[x-1,0]){
        labels[i] = labels[i-1];
      } else {
        label++;
        labels[i] = label;
      }
    }
    i++;
  }
  for (y = 1; y < N; y++){
    for (x = 0; x < M; x++){
      if (Image[x,y] == 255){
        if (x == 0){
          if (Image[x,y-1] == 255){
            labels[i] = labels[i-M];
          }
        } else {
          if (Image[x-1,y] == 255){
            labels[i] = labels[i-1];
          }
          if (Image[x,y-1] == 255){
            if (Image[x-1,y] == 255 && labels[i] != labels[(y-1)*M+x]){
              Merge(labels, labels[(y-1)*M+x], labels[i]);
            } else {
              labels[i] = labels[i-M];
            }
          }
          if (Image[x-1,y] == 0 && Image[x,y-1] == 0){
	    if (Image[x-1,y-1] == 255){
	      labels[i] = labels[(y-1)*M+x-1];
	    } else {
	      label++;
	      labels[i] = label;
	    }
          }
        }
      } else {
        if(x != 0){
	  if (Image[x-1,y] == 255 && Image[x,y-1] == 255){
	    Merge(labels, labels[(y-1)*M+x], labels[i-1]);
	  }
	}
      }
      i++;
    }
  }
  labeledCC = gcnew cliext::vector<ConnectedComponent^>();
  int j = 0;
  int k, c, q;
  for (q = 0; q < M*N; q++){
    if(labels[q] != 0){
      if (j > 0){
        c = 0;
	for (k = 0; k < j; k++){
	  if (labels[q] != labeledCC[k]->a)
	    c++;
          else {
	    labeledCC[k]->b++;
	    labeledCC[k]->ymax = (q - q % M)/M; 
	    labeledCC[k]->Xymax = q % M;
	    if (q % M < labeledCC[k]->xmin){
	      labeledCC[k]->xmin = q % M; 
	      labeledCC[k]->Yxmin = (q - q % M)/M;
	    }
	    if (q % M > labeledCC[k]->xmax){
	      labeledCC[k]->xmax = q % M; 
	      labeledCC[k]->Yxmax = (q - q % M)/M;
            }
          }
	  if (c == j){
	    ConnectedComponent^ element = gcnew ConnectedComponent();
	    element->a = labels[q];
	    element->b++;
	    element->ymin = (q - q % M)/M;
	    element->Xymin = q % M;
	    element->xmin = q % M;
	    element->xmax = q % M;
	    labeledCC->push_back(element);
	    j++;
	  }
	}
      } else {
        ConnectedComponent^ element = gcnew ConnectedComponent();
	element->a = labels[q];
	element->b++;
	element->ymin = (q - q % M)/M;
	element->xmin = q % M;
	element->xmax = q % M;
	labeledCC->push_back(element);
	j++;
      }
    }
  }
  // At this point, j holds the amount of connected components found
  for (y = 0; y < N; y++)
    for (x = 0; x < M; x++)
      if(labels[x+y*M] > 0)
        AuxArray[x,y] = 255;	
  return AuxArray; 
}
```

The function 'Merge' consolidates two labels into one when two sub-regions happen to belong to the same connected component during the execution of the 'ExtractConnectedComponents' function.

```c++
void Merge (cliext::vector<int>^ labels, int parent1, int parent2){
  int i=0;
  for each (int label in labels){
    if (parent1 < parent2 && label == parent2)
      labels[i] = parent1;
    if (parent2 < parent1 && label == parent1)
      labels[i] = parent2;
    i++;
  }
}
```

Also, the following class is useful to keep details of each connected components found, such their bounding box coordinates.

```c++
ref struct ConnectedComponent{
  // Constructor
  ConnectedComponent (void): a(0), b(0), xmax(0), xmin(0), ymax(0), ymin(0), Xymax(0), Xymin(0), Yxmax(0), Yxmin(0) {}
  // Assignment operator
  ConnectedComponent% operator=(const ConnectedComponent% p){ 
    if(this != %p){
      a = p.a; // label ID
      b = p.b; // amount of pixels in the connected component
      xmax = p.xmax; // bounding box maximum x value
      xmin = p.xmin; // bounding box minimum x value
      ymax = p.ymax; // bounding box maximum y value
      ymin = p.ymin; // bounding box minimum x value
      Xymax = p.Xymax; // extreme C
      Xymin = p.Xymin; // extreme A
      Yxmax = p.Yxmax; // extreme B
      Yxmin = p.Yxmin; // extreme D
    }
    return *this;
  }
  int a, b, xmax, xmin, ymax, ymin, Xymax, Xymin, Yxmax, Yxmin;
};
```

Connected components found by this algorithm are depicted in different shades of gray in the following figure. Note that the license plate was correctly segmented since no other object from the image ended up connected to it.

<img src="image8.png?raw=true" alt="Grayscale image" height="220" width="294">


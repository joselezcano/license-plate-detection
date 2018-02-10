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
// This vector will contain all connected components that will be filtered out step by step in next sections
cliext::vector<ConnectedComponent^>^ labeledCC;

void ExtractConnectedComponents (cli::array<unsigned char, 2>^ Image){
  int x, y;
  int i = 0;
  int label = 0; // label ID
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  cli::array<unsigned char, 2>^ AuxArray = gcnew cli::array<unsigned char, 2>(M,N);
  cliext::vector<int>^ labels = gcnew cliext::vector<int>(M*N);  
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

## Eliminate connected components that are too small or too big
Whichever application your aiming at with this detection algorithm (e.g. license plate character recognition), you'll only process license plates of a certain, useful size. The following function discards components with less than 170 pixels and more than 22,000 pixels.  

```c++
cli::array<unsigned char, 2>^ EliminateComponentsBySize (cli::array<unsigned char, 2>^ Image){
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
  int x, y;
  int deletedComponents = 0;
  int index = 0;
  for each (ConnectedComponent^ element in labeledCC){
    if (element->b < 170 || element->b > 22000){
      deletedComponents++;
      // This loops turns the eliminated candidate into black background
      for(x = 0; x < M*N; x++){
        if (labels[x] == element->a){ // element->a holds the label ID
	  labels[x] = 0;
	}
      }
      labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
    }
    index++;
  }
  // If there is some valid candidates after deletion, they'll be seen in the next binary image in white
  for (y = 0; y < N; y++)
      for (x = 0; x < M; x++)
        if(labels[x+y*M] > 0)
	  NewImArray[x,y] = 255;
  return NewImArray;
}
```
After this elimination step, 1096 connected components get reduced to only 47 relevant candidates.

<img src="image9.png?raw=true" alt="Grayscale image" height="220" width="294">

## Employ bounding box aspect ratio to reduce candidates
If your camera is fixed, in horizontal position, you will find that most license plates are almost horizontally aligned with the ground as well. Some tilt is allowed and it depends on you which range to use for filtering candidates, for instance, [-45, 45] degrees is more than a safe range.
When a license plate is tilted in the range [-45, 45] degrees, its bounding box will have an aspect ratio (m/n) in the interval [1, 2], as shown next for a Paraguayan license plate whose width is twice its height (a/b = 2).

<img src="image10.png?raw=true" alt="Grayscale image" height="124" width="124"> <img src="image12.png?raw=true" alt="Grayscale image" height="220" width="294"> <img src="image11.png?raw=true" alt="Grayscale image" height="120" width="220">

This function will eliminates those candidates whose bounding boxes have an aspect ratio outside the range [1, 2].

```c++
cli::array<unsigned char, 2>^ ApplyBoundingBoxCriterion (cli::array<unsigned char, 2>^ Image){
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  int x,y;
  int deletedCandidates = 0;
  // Bounding box aspect ratio limits
  double minValidAspectRatio = 1.0; // For Paraguayan license plates with tilt in range [-45, 45] degrees
  double maxValidAspectRatio = 2.0; // For Paraguayan license plates with tilt in range [-45, 45] degrees
  int index = 0;
  for each (ConnectedComponent^ element in labeledCC){
    if (element->a != 0){
      // Checks if a candidate has zero width or zero height and deletes it
      if (System::Math::Abs(element->ymax - element->ymin) == 0 || System::Math::Abs(element->xmax - element->xmin) == 0){
        deletedCandidates++;
	// This loops turns the eliminated candidate into black background
	for(x = 0; x < M*N; x++){
	  if (labels[x] == element->a){ // element->a holds the label ID
	    labels[x] = 0;	    
	  }
	}
	labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
    } else {
      double candidateAspectRatio = safe_cast<double>(System::Math::Abs(element->xmax - element->xmin))/safe_cast<double>(System::Math::Abs(element->ymax - element->ymin));
      // Checks if a candidate has a bounding box with aspect ratio outside the valid range and deletes it
      if (candidateAspectRatio < minValidAspectRatio || candidateAspectRatio > maxValidAspectRatio){
        deletedCandidates++;
	// This loops turns the eliminated candidate into black background
	for(x = 0; x < M*N; x++){
	  if (labels[x] == element->a){ // element->a holds the label ID
	    labels[x] = 0; 
	  }
        }
	labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
      }     
    }
    index++; 
  }
  // If there is some valid candidates after deletion, they'll be seen in the next binary image in white
  for (y = 0; y < N; y++)
    for (x = 0; x < M; x++)
      if(labels[x+y*M] > 0)
        NewImArray[x,y] = 255;
  return NewImArray; 
}    
```
Before applying the bounding box criterion, the image had 47 connected components; after it, the image has only 23 valid candidates. The binary image with the remaining candidates is presented next:

<img src="image20.png?raw=true" alt="Grayscale image" height="220" width="294">

## Filter out candidates without rectangular proportions
Take a look at the following figures:

<img src="image14.png?raw=true" alt="Grayscale image" height="157" width="766">

On figure a) there's a candidate, in figure b) you'll see its extreme points calculated in the ExtractConnectedComponents function, and in figure c) imagine a rectangle defined by those extreme points.
A perfect license plate would have equal sides AD and BC, as well as AB and CD. Also, segment BC should be twice segment CD for Paraguayan license plates.
The next function deletes candidates that do not conform to these metrics.

```c++
cli::array<unsigned char, 2>^ RectangularProportionsCriteria (cli::array<unsigned char, 2>^ Image){
  int M = Image->GetLength(0);
  int N = Image->GetLength(1);
  cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(M,N);
  int x,y;
  int deletedCandidates = 0;
  // Let's define excentricity as width/height
  double plateExcentricity = 2.0; // For Paraguayan license plates
  int index = 0;
  for each (ConnectedComponent^ element in labeledCC){
    if (element->a!=0 ){
      double side1 = safe_cast<double>((element->ymin - element->Yxmax)*(element->ymin - element->Yxmax) + (element->xmax - element->Xymin)*(element->xmax - elemento->Xymin));
      double side2 = safe_cast<double>((element->Yxmax - element->ymax)*(element->Yxmax - element->ymax) + (element->xmax - element->Xymax)*(element->xmax - element->Xymax));
      double side3 = safe_cast<double>((element->Xymax - element->xmin)*(element->Xymax - element->xmin) + (element->Yxmin - element->ymax)*(element->Yxmin - element->ymax));
      double side4 = safe_cast<double>((element->ymin - element->Yxmin)*(element->ymin - element->Yxmin) + (element->Xymin - element->xmin)*(element->Xymin - element->xmin));
      double relation13 = side1/side3;
      double relation24 = side2/side4;
      double excentricity;
      if (side1 > side2)
        excentricity = side1/side2;
      else
	excentricity = side2/side1;
      // Let's use a 20% tolerance for rectangular proportions
      if (excentricity < 0.8 * plateExcentricity || excentricidad > 1.2 * plateExcentricity || 
          relation13 > 1.21 || relation13 < 0.81 || relation24 > 1.21 || relation24 < 0.81){
	deletedCandidates++;
	for(x = 0; x < M*N; x++){
	  if (labels[x] == element->a){ // element->a holds the label ID
	    labels[x] = 0;
	  }
	}
	labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
      }      
    }
    index++;
  }
  // If there is some valid candidates after deletion, they'll be seen in the next binary image in white
  for (y = 0; y < N; y++)
    for (x = 0; x < M; x++)
      if(labels[x+y*M] > 0)
        NewImArray[x,y] = 255;
  return NewImArray; 
}  
```

The amount of candidates reduces from 23 to only 9, as depicted next.

<img src="image15.png?raw=true" alt="Grayscale image" height="220" width="294">

## Use area as a feature to remove more candidates
At this step, some candidates may have survived previous filters, which means they have a valid bounding box and rectangular proportions. However, their area, given by the amount of pixels, may still be smaller or higher than that of a license plate inside the same bounding box. For this reason, we should discard candidates that do not have a valid area.
Before removing candidates, we should estimate the area of a license plate for each size of a valid bounding box (because a plate could be tilted) an fill in the holes of connected components (due to letters inside plates), as shown next.

<img src="image16.png?raw=true" alt="Grayscale image" height="248" width="666">

Figure a) shows a segmented license plates with holes due to letters. Figure b) shows the same license plate after filling up its holes with white pixels. 
The following function discards candidates by area.

```c++
cli::array<unsigned char, 2>^ AreaCriterion (cli::array<unsigned char, 2>^ ImArray){
  // ImArray contains the resulting image from the RectangularProportionsCriteria function
  cli::array<unsigned char, 2>^ NewImArray = gcnew cli::array<unsigned char, 2>(ImArray->GetLength(0), ImArray->GetLength(1));
  int deletedCandidates = 0;
  int index;
  // Iterate over each connected component (candidate)
  for each (ConnectedComponent^ element in labeledCC){
    int x, y;
    int begin, end;
    int fill = 0;
    cli::array<unsigned char, 2>^ region = gcnew cli::array<unsigned char, 2>(element->xmax - element->xmin, element->ymax - element->ymin);
    int M = region->GetLength(0);
    int N = region->GetLength(1);
    // Let's create a sub-image called 'region' with the current connected component
    for (y = 0; y < N; y++)
      for (x = 0; x < M; x++)
        region[x,y] = ImArray[element->xmin + x, element->ymin + y];
    int area = 0;
    // This for loop calculates the amount of pixels needed to fill holes inside a region
    for (y = 0; y < N; y++){
      begin = end = 0;
      x = 0;
      while (x < M){
        if (region[x,y] == 255)
	  begin = x;
	  x++;
      }
      x = M;
      while (x != 0){
        if (region[x-1,y] == 255)
	  end = x;
	  x--;
      }
      if (end > (begin + 1)){
        for (x = begin + 1; x < fin; x++){
	  if (region[x,y] == 0)
	    fill++;
	  }
	}
      }      
    }
    // The area of the region including pixels that fill into holes is
    area = fill + element->b;    
    // The total area including the exterior of a region is
    int totalArea = area + (element->ymax - element->Yxmax)*(element->xmax - element->Xymax) + (element->ymax - element->Yxmin)*(element->Xymax - element->xmin);
    // The following if-clause deletes a candidate assuming it is tilted
    if (totalArea < 0.8*M*N || totalArea > 1.2*M*N){ // 20% tolerance
      deletedCandidates++;
      for(x = 0; x < M*N; x++){
        if (labels[x] == element->a){ // element->a holds the label ID
          labels[x] = 0;
        }
      }
      labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
    } else {
      int totalArea = area;
      // The following if-clause deletes a candidate considering no tilt
      if (totalArea < 0.8*M*N || totalArea > 1.2*M*N){ // 20% tolerance
        deletedCandidates++;
	for(x = 0; x < M*N; x++){
	  if (labels[x] == element->a){ // element->a holds the label ID
	    labels[x] = 0;
	  }
	}
	labeledCC[index]->a = 0; // label ID 0 is used for discarded candidates
      }
    }
    index++;
  }
  // If there is some valid candidates after deletion, they'll be seen in the next binary image in white
  for (y = 0; y < N; y++)
    for (x = 0; x < M; x++)
      if(labels[x+y*M] > 0)
        NewImArray[x,y] = 255;
  return NewImArray; 
}
```

After filtering out components using the area criterion there are only 3 final candidates.

<img src="image17.png?raw=true" alt="Grayscale image" height="220" width="294">

## Final remarks
To sum up, all previous steps reduce the amount of connected components to a handful of good candidates which can be fed to a neural network for character recognition (the candidate with 6 letters will be the Paraguayan license plate). The advantage of a pure Image Processing approach is that you do not need to scan the input image repeatedly using windows of several sizes, as in neural network processing.

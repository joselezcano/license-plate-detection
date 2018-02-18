# License Plate Detection
This repository is a review of some Image Processing techniques and interesting heuristics to detect license plates.
Code snippets were written in C++/CLI, since this application was originally developed in Microsoft Visual C++.

## Working with images in grayscale
Although cameras provide colorful images, it is faster to work with grayscale images since we do not need to manipulate 3 color channels (RGB) at any processing step. Also, color may not be a good feature to filter candidates due to the high probability of finding objects with similar hue in a given scene. The following grayscale image was created with the ITU BT.709 formula.

<img src="img/image1.jpeg?raw=true" alt="Color image" height="220" width="294"> <img src="img/image2.png?raw=true" alt="Grayscale image" height="220" width="294">

## Enhancing license plate borders before detection
It's a good idea to enhance a grayscale image before detecting an object. To this end, you can use histogram equalization or another adaptive technique; however, a nice effect can be accomplished with a Laplacian of Gaussian (LoG) filter which fills the gaps between worn out borders of old license plates, as depicted in the following figures:

<img src="img/image3.png?raw=true" alt="LoG filter" height="220" width="285"> <img src="img/image4.png?raw=true" alt="Border improvement" height="242" width="450">

The figure on the left is a side view of the LoG filter (a.k.a Mexican Hat filter). Figure a) is a license plate with red borders (as used in Paraguay), figure b) is the grayscale version of the color image, and figure c) is the LoG-filtered image.
Note that the Mexican Hat filter has zero mean and the resulting image pixel value may extend beyond the range [0,255]. For display purpose, you can normalize each pixel to have an intensity value in the former range. As a result, you'll get the following picture which looks a bit opaque due to normalization:

<img src="img/image5.png?raw=true" alt="LoG filtered image" height="220" width="294">

## Turn the filtered image into a binary image
After enhancing a grayscale image, you can turn it into 1s and 0s (i.e pixel values of 255 and 0) to start segmenting the image. A simple way to map a gray pixel to black or white is to compare it with a threshold (e.g. 150), but this method does not perform well when parts of an image differ in their local intensities. An adaptive algorithm would consider a neighborhood around the current pixel ('pixel actual' in Spanish) to decide which threshdold is the most suitable in each region of the image. 

<img src="img/image6.png?raw=true" alt="Threshold image" height="220" width="294">

The new binary image is shown next.

<img src="img/image7.png?raw=true" alt="Binary image" height="220" width="294">

## Extract connected components
The next step in detecting an object inside an image is to segment it in its components. Connected pixels define an isolated region that may represent a meaningful part of an image (or just a cluster of pixels). 
Connected components found by the function 'ExtraerRegionesD8' included in the source code are depicted in different shades of gray in the following figure. Note that the license plate was correctly segmented since no other object from the image ended up connected to it.

<img src="img/image8.png?raw=true" alt="CCs image" height="220" width="294">

## Eliminate connected components that are too small or too big
Whichever application your aiming at with this detection algorithm (e.g. license plate character recognition), you'll only process license plates of a certain, useful size. Therefore, a function to discard components with less than 170 pixels and more than 22,000 pixels was used.  
After this elimination step, 1096 connected components get reduced to only 47 relevant candidates.

<img src="img/image9.png?raw=true" alt="Good-sized candidates image" height="220" width="294">

## Employ bounding box aspect ratio to reduce candidates
If your camera is fixed, in horizontal position, you will find that most license plates are almost horizontally aligned with the ground as well. Some tilt is allowed and it depends on you which range to use for filtering candidates, for instance, [-45, 45] degrees is more than a safe range.
When a license plate is tilted in the range [-45, 45] degrees, its bounding box will have an aspect ratio (m/n) in the interval [1, 2], as shown next for a Paraguayan license plate whose width is twice its height (a/b = 2). The 'Contenedores_Click' function applies this criterion. 

<img src="img/image10.png?raw=true" alt="Object image" height="124" width="124"> <img src="img/image12.png?raw=true" alt="Problem Geometry" height="220" width="294"> <img src="img/image11.png?raw=true" alt="Formula" height="120" width="220">

Before applying the bounding box criterion, the image had 47 connected components; after it, the image has only 23 valid candidates. The binary image with the remaining candidates is presented next:

<img src="img/image20.png?raw=true" alt="Bounding box result image" height="220" width="294">

## Filter out candidates without rectangular proportions
Take a look at the following figures:

<img src="img/image14.png?raw=true" alt="Rectangle extremes image" height="157" width="766">

On figure a) there's a candidate, in figure b) you'll see its extreme points calculated in the 'ExtraerRegionesD8' function, and in figure c) imagine a rectangle defined by those extreme points.
A perfect license plate would have equal sides AD and BC, as well as AB and CD. Also, segment BC should be twice segment CD for Paraguayan license plates.
The 'Excentricidad_Click' function deletes candidates that do not conform to these metrics. Then, the amount of candidates reduces from 23 to only 9, as depicted next.

<img src="img/image15.png?raw=true" alt="Rectangular proportions image" height="220" width="294">

## Use area as a feature to remove more candidates
At this step, some candidates may have survived previous filters, which means they have a valid bounding box and rectangular proportions. However, their area, given by the amount of pixels, may still be smaller or higher than that of a license plate inside the same bounding box. For this reason, we should discard candidates that do not have a valid area.
Before removing candidates, we should estimate the area of a license plate for each size of a valid bounding box (because a plate could be tilted) an fill in the holes of connected components (due to letters inside plates), as shown next.

<img src="img/image16.png?raw=true" alt="Fill up holes image" height="166" width="444">

Figure a) shows a segmented license plate with holes due to letters. Figure b) shows the same license plate after filling up its holes with white pixels. 
The 'Areas_Click' function discards candidates by area. After filtering out components using the area criterion there are only 3 final candidates.

<img src="img/image17.png?raw=true" alt="Area image" height="220" width="294">

## Detection examples
You can further reduce the amount of candidates until you end up with only one. For this purpose, you need to add a few more criteria (such as presence of character shapes) or a scoring scheme to estimate the likelihood of each candidate to be a license plate. I chose the latter alternative and got a detection rate above 90%. I share some examples next (note we can estimate the distance to a vehicle as an application of this algorithm). 

<img src="img/example2.bmp?raw=true" alt="Example 2" height="238" width="317"> <img src="img/example1.bmp?raw=true" alt="Example 1" height="240" width="245">

## Final remarks
To sum up, all previous steps reduce the amount of connected components to a handful of good candidates which can be fed to a neural network for character recognition or to another application. The advantage of a pure Image Processing approach is that you do not need to scan the input image repeatedly using windows of several sizes, as in neural network processing. 
Note that I didn't use any specialized library to optimize the license plate detection algorithm, as this project is part of a bachelor's degree thesis and its purpuse was to depict every image processing step in an academic manner. If you want to speed up the code, you may use linear algebra libraries, OpenCV, multithreading, etc. If you have a GPU, you can also find libraries that take advantage of this hardware.

## References
This work and more features added afterwards turned into 2 peer-reviewed academic papers; one for an Image Processing conference, and the other one for a Computer Applications journal.
### Moving License Plate Segmentation
Jun 2010 - 17th International Conference on Systems, Signals and Image Processing
### Moving license plate segmentation by region and corner-based approach
Oct 2012  - International Journal of Innovative Computing and Applications

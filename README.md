# license-plate-detection
This repository is a review of some Image Processing techniques and interesting heuristics to detect license plates.
Code snippets were written in C++/CLI, since this application was originally developed in Microsoft Visual C++.

# Working with images in grayscale
Although cameras provide colorful images, it is faster to work with grayscale images since we do not need to process 3 color channels (RGB) at any processing step. Also, color may not be a good feature to filter candidates due to the high probability of finding objects with similar hue in a given scene.





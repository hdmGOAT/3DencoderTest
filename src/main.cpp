#include <opencv2/opencv.hpp>
#include <iostream>
#include "functions/basics/encoder.h"
#include "functions/basics/decoder.h"

#include "functions/multilayer/3Dencoder.h"
#include "functions/multilayer/3Ddecoder.h"

using namespace cv;
using namespace std;

int main(){
    string text = "Hello, OpenCV!";
    string outputImagePath = "C:/Users/User/Desktop/testImages/encoded_image.png";

    encode(text, outputImagePath);


	cout << "Decoded text: " << decode(outputImagePath) << endl;


	string text3D = "Hello, 3D OpenCV!";
	string outputImagePath3D = "C:/Users/User/Desktop/testImages/3D_encoded_image.png";
	int numLayers = 4;

    return 0;
}
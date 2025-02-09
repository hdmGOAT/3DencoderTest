#include <opencv2/opencv.hpp>
#include <iostream>
#include "functions/encoder.h"
#include "functions/decoder.h"

using namespace cv;
using namespace std;

int main(){
    string text = "Hello, OpenCV!";
    string outputImagePath = "C:/Users/User/Desktop/testImages/encoded_image.png";

    encode(text, outputImagePath);


	cout << "Decoded text: " << decode(outputImagePath) << endl;

    return 0;
}
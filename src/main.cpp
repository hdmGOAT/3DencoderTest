#include <opencv2/opencv.hpp>
#include <iostream>
#include "functions/encoder.h"

using namespace cv;
using namespace std;

int main(){
    string text = "Hello, OpenCV!";
    string outputImagePath = "C:/Users/User/Desktop/encoded_image.png";

    encode(text, outputImagePath);

    return 0;
}
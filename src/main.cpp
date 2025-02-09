#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat image = Mat::zeros(300,300,CV_8UC3);
    circle(image, Point(150,150), 100, Scalar(0,255,0),-1);
}
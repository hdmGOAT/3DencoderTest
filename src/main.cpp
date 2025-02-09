#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat image = Mat::zeros(300,300,CV_8UC3);
    circle(image, Point(150,150), 100, Scalar(0,255,0),-1);
    
    rectangle(image, Point(100, 100), Point(400, 400), Scalar(255, 0, 0), 2);

    line(image, Point(100, 400), Point(400, 100), Scalar(0, 0, 255), 3);

    putText(image, "OpenCV Test", Point(120, 480), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

    imshow("Test Window", image);

    imwrite("output_test_image.jpg", image);

    waitKey(0);

    return 0;
}
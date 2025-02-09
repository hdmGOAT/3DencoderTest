#include "encoder.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>
#include <string>

using namespace cv;
using namespace std;

void encode(const string& text, const string& outputImagePath) {

    string binaryData;
    for (char c : text) {
        binaryData += bitset<8>(c).to_string(); 
    }

    int side = ceil(sqrt(binaryData.length())); 
    Mat image = Mat::zeros(side, side, CV_8UC1);

    int bitIndex = 0;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            if (bitIndex < binaryData.length()) {
                image.at<uchar>(i, j) = (binaryData[bitIndex] == '1') ? 255 : 0; 
                bitIndex++;
            }
        }
    }
    imwrite(outputImagePath, image);
    cout << "Text encoded into image: " << outputImagePath << endl;
}
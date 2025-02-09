#include "decoder.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>
#include <string>

using namespace cv;
using namespace std;

string decode(const string& inputImagePath) {
    Mat image = imread(inputImagePath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Could not open or find the image: " << inputImagePath << endl;
        return "";
    }

    string binaryData;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            binaryData += (image.at<uchar>(i, j) == 255) ? '1' : '0';
        }
    }

    string decodedText;
    for (size_t i = 0; i < binaryData.length(); i += 8) {
        if (i + 8 <= binaryData.length()) {
            string byte = binaryData.substr(i, 8);
            decodedText += static_cast<char>(bitset<8>(byte).to_ulong());
        }
    }

    return decodedText;
}


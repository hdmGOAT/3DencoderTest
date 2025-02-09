#include "3Dencoder.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>


using namespace cv;
using namespace std;

vector<int> generatePrimesVector(int numLayers) {
    vector<int> primes;
    int candidate = 2;
    while (primes.size() < numLayers) {
        bool isPrime = true;
        for (int p : primes) {
            if (candidate % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(candidate);
        candidate++;
    }
    return primes;
}


void ThreeDEncode(const string& text, const string& outputImagePath, int numLayers) {
    vector<int> primes = generatePrimesVector(numLayers);

    string binaryData;
    for (char c : text) {
        binaryData += bitset<8>(c).to_string();
    }
    
    int side = ceil(sqrt(binaryData.length() / (float)numLayers));
    Mat image = Mat::zeros(side, side, CV_8UC1); 

    int bitIndex = 0;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            if (bitIndex < binaryData.length()) {
                int pixelValue = 0;
                for (int k = 0; k < numLayers && bitIndex < binaryData.length(); ++k) {
                    if (binaryData[bitIndex] == '1') {
                        pixelValue += primes[k]; 
                    }
                    bitIndex++;
                }
                image.at<uchar>(i, j) = (pixelValue > 255) ? 255 : pixelValue;
            }   
        }
    }

    imwrite(outputImagePath, image);
    cout << "Text encoded into image: " << outputImagePath << endl;

}


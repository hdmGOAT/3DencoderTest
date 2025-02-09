#include "3Ddecoder.h"
#include "3Dencoder.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace cv;
using namespace std;

vector<int> factorizePrimeSum(int pixelValue, const vector<int>& primes) {
	vector<int> layers;
	int remainingValue = pixelValue;
	for (int prime : primes) {
		if (remainingValue >= prime) {
			layers.push_back(prime);
			remainingValue -= prime;
		}
	}
	return layers;
}

void ThreeDDecode(const string& inputImagePath, int numLayers) {
    Mat image = imread(inputImagePath, IMREAD_GRAYSCALE);
    if (image.empty()) {
        cerr << "Error: Could not open image: " << inputImagePath << endl;
        return "";
    }

    vector<int> primes = generatePrimesVector(numLayers);
    string binaryData;

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            int pixelValue = image.at<uchar>(i, j);
            vector<int> layers = factorizePrimeSum(pixelValue, primes);

            for (int prime : primes) {
                binaryData += (find(layers.begin(), layers.end(), prime) != layers.end()) ? '1' : '0';
            }
        }
    }

    string decodedText;
    for (size_t i = 0; i < binaryData.length(); i += 8) {
        string byte = binaryData.substr(i, 8);
        decodedText += static_cast<char>(bitset<8>(byte).to_ulong());
    }

    return decodedText;
}
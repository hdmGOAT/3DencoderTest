#include "bstack.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <bitset>

using namespace cv;
using namespace std;

string fileToBinary(const string& filePath) {
	ifstream file(filePath, ios::binary);
	if (!file) {
		cout << "Error: File not found" << endl;
		return;
	}

	string binaryData;
	char byte;
	while (file.get(byte)) {
		binaryData += bitset<8>(byte).to_string();
	}
	file.close();
	return binaryData;
}

void bstackEncode(const std::string& binaryData, std::string& outputImagePath) {
	int tot_bits = binaryData.size();
	int pixel_req = ceil((double)tot_bits / 32); // 32 bits per pixel
	int side = ceil(sqrt(pixel_req));

	Mat img(side, side, CV_8UC3, Scalar(0, 0, 0, 255));

	int bit_index = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Vec3b pixel = img.at<Vec3b>(i, j);
			for (int k = 0; k < 3; k++) {
				if (bit_index < tot_bits) {
					pixel.val[k] = binaryData[bit_index++] - '0';
				}
			}
			img.at<Vec3b>(i, j) = pixel;
		}
	}
}
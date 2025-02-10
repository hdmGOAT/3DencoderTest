#include "bstack.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>

using namespace cv;
using namespace std;



void pixstackencode(const std::string& binaryData, std::string& outputImagePath) {
	if (binaryData.empty()) {
		cout << "Error: Binary data is empty. Exiting..." << endl;
		return;
	}

	
	int tot_bits = binaryData.size();
	int pixel_req = ceil((double)tot_bits / 32); // 32 bits per pixel

	if (pixel_req == 0) {
		cout << "Error: No pixels required for encoding. Exiting..." << endl;
		return;
	}


	int side = ceil(sqrt(pixel_req));

	Mat img(side, side, CV_8UC4, Scalar(0, 0, 0, 255));

	int bit_index = 0;
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j) {
			if (bit_index < tot_bits) {
				uint32_t stack = 0;

				for (int k = 0; k < 32 && bit_index < tot_bits; ++k) {
					stack |= (binaryData[bit_index] =='1')? (1 << k): 0;
					++bit_index;
				}

				Vec4b pixel(
					(stack >> 24) & 0xFF,
					(stack >> 16) & 0xFF,
					(stack >> 8) & 0xFF,
					stack & 0xFF
				);

				img.at<Vec4b>(i, j) = pixel;
			}
		}
	}
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9); // Maximum compression

	
	outputImagePath = outputImagePath + "output.png";
	if (!imwrite(outputImagePath, img, compression_params)) {
		cerr << "Error: Failed to save the image!" << endl;
		return ;
	}

	cout << "Image encoded successfully!" << endl;
}
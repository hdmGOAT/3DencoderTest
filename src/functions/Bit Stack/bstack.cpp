#include "bstack.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <bitset>

void bstackEncode(std::string text, std::string outputImagePath) {
	cv::Mat image = cv::imread(outputImagePath, cv::IMREAD_COLOR);
	cv::Mat encodedImage = image.clone();
	int textLength = text.length();
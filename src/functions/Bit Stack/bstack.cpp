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

void bstackEncode(const std::string& binaryData, std::string& outputImagePath) {}
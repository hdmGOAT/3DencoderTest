#include "functions/bitstack/bitstack.h"

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
		return "";
	}

	string binaryData;
	char byte;
	while (file.get(byte)) {
		binaryData += bitset<8>(byte).to_string();
	}
	file.close();
	return binaryData;
}

int main(){

	string fileName = "BlackMarble_2016_928m_conus.tif";

	string inputFilePath = "C:\\Users\\User\\Desktop\\testImages\\tifs\\" + fileName;


	string outputImagePath = "C:/Users/User/Desktop/testImages/" + fileName +".bstack";

	bitStackEncode(inputFilePath, outputImagePath, 16);


	bitStackDecode(outputImagePath, "C:/Users/User/Desktop/testImages/" + fileName + "_decoded.tif");

    return 0;
}
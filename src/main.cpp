#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <bitset>

#include "functions/basics/encoder.h"
#include "functions/basics/decoder.h"

#include "functions/Bit-Stack/pstack.h"
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
	string inputFilePath = "C:/Users/User/Desktop/testImages/2024-11-02 08-51-04.mkv";

	string binaryData = fileToBinary(inputFilePath);

	string outputImagePath = "C:/Users/User/Desktop/testImages/";

	bstackEncode(binaryData, outputImagePath);

    return 0;
}
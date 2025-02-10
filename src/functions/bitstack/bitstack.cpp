#include "bitstack.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct BStackHeader {
	char signature[8] = "BSTACK\0";
	uint64_t originalSize;
	uint8_t bitDepth = 8;
};

void bstackEncode(const string& binaryData, string& outputFile) {

	ofstream output(outputFile, ios::binary);
	if (!output) {
		cerr << "Error: Could not open file for writing" << endl;
		return;
	}

	BStackHeader header = { "BSTACK\0", fileSize, 8 };
	output.write(reinterpret_cast<char*>(&header), sizeof(header));
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

struct BStackHeader {
    char signature[8] = "BSTACK\0";  
    uint64_t originalSize;           
    uint8_t bitDepth = 8;           
};

/*
    Bit Stacking expected functionality:
        Each first bit is in Layer 1,
		Each second bit is in Layer 2,
		Each third bit is in Layer 3,
		Each fourth bit is in Layer 4,
        ...

		This allows for compressors to better view redundancy in the data.
*/


void bitStackEncode(const string& inputFile, const string& outputFile) {
    ifstream input(inputFile, ios::binary | ios::ate);
    if (!input) {
        cerr << "Error: Cannot open input file: " << inputFile << endl;
        return;
    }


    size_t fileSize = input.tellg();
    input.seekg(0, ios::beg);
    vector<uint8_t> rawData(fileSize);
    input.read(reinterpret_cast<char*>(rawData.data()), fileSize);
    input.close();

   
    ofstream output(outputFile, ios::binary);
    if (!output) {
        cerr << "Error: Cannot open output file: " << outputFile << endl;
        return;
    }

    BStackHeader header = { "BSTACK\0", fileSize, 8 };
    output.write(reinterpret_cast<char*>(&header), sizeof(header));


    vector<uint8_t> bitLayers[8];  
	for (int i = 0; i < 8; i++) {
		bitLayers[i].resize(fileSize);
	}


    for (size_t i = 0; i < fileSize; i++) {
        uint8_t byte = rawData[i];
        for (int bitPos = 0; bitPos < 8; bitPos++) {
            size_t index = i / 8; 
            uint8_t bitValue = (byte >> bitPos) & 1;
            bitLayers[bitPos][index] |= (bitValue << (7 - (i % 8))); 
        }
    }

    for (int bitPos = 0; bitPos < 8; bitPos++) {
        output.write(reinterpret_cast<char*>(bitLayers[bitPos].data()), bitLayers[bitPos].size());
    }

    cout << "Encoded binary file " << inputFile << " into " << outputFile << " successfully!" << endl;
}

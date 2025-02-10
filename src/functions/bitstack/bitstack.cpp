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
    bitLayers[0].resize(fileSize);
    bitLayers[1].resize(fileSize);
    bitLayers[2].resize(fileSize);
    bitLayers[3].resize(fileSize);
    bitLayers[4].resize(fileSize);
    bitLayers[5].resize(fileSize);
    bitLayers[6].resize(fileSize);
    bitLayers[7].resize(fileSize);


    for (size_t i = 0; i < fileSize; i++) {
        uint8_t byte = rawData[i];
        for (int bitPos = 0; bitPos < 8; bitPos++) {
            bitLayers[bitPos][i] = (byte >> bitPos) & 1;  
        }
    }

    for (int bitPos = 0; bitPos < 8; bitPos++) {
        output.write(reinterpret_cast<char*>(bitLayers[bitPos].data()), fileSize);
    }

    cout << "Encoded binary file " << inputFile << " into " << outputFile << " successfully!" << endl;
}

#ifndef _3DENCODER_H_
#define _3DENCODER_H_

#include <string>
#include <vector>

using namespace std;

void ThreeDEncode(const string& text, const string& outputImagePath, int numLayers);

vector<int> generatePrimesVector(int numLayers);

#endif // _3DENCODER_H_

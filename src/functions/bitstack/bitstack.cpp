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
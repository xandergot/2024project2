#include "AddressDecoder.hpp"
#include <math.h> // Include the math library for log2

AddressDecoder::AddressDecoder(int numSets, int blockSize) {
    this->numSets = numSets;
    this->blockSize = blockSize;

    // Calculate the number of bits needed for the offset
    this->blockOffsetBits = log2(blockSize);

    // Calculate the number of bits needed for the index
    this->setIndexBits = log2(numSets);

    // Calculate the number of bits needed for the tag
    this->tagBits = 32 - blockOffsetBits - setIndexBits; // Assuming 32-bit addresses
}
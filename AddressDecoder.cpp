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

AddressComponents AddressDecoder::decodeAddress(int address) const {
    AddressComponents components;

    // Extract the block offset bits
    components.blockOffset = address & (blockSize - 1);

    // Extract the set index bits
    components.setIndex = (address >> blockOffsetBits) & (numSets - 1);

    // Extract the tag bits
    components.tag = address >> (blockOffsetBits + setIndexBits);

    return components;
}
#include <iostream>
#include "Cache.hpp"
#include "AddressDecoder.hpp"

Cache::Cache(int size, int associativity, int blockSize)
    : size(size), associativity(associativity), blockSize(blockSize),
      decoder(size / (associativity * blockSize), blockSize) { // Initialize decoder using initializer list
    int setNum = size / (associativity * blockSize);
    sets = new Set*[setNum]; // Allocate memory for sets

    for (int i = 0; i < setNum; i++) {
        sets[i] = new Set(associativity, blockSize);
    }
}

int Cache::getSize() {
    return this->size;
}

int Cache::getAssociativity() {
    return this->associativity;
}

int Cache::getBlockSize() {
    return this->blockSize;
}

unsigned char Cache::read(unsigned long address) {
    unsigned long tag, setIndex, blockOffset;
    AddressComponents components = decoder.decodeAddress(address);
    tag = components.tag;
    setIndex = components.setIndex;
    blockOffset = components.blockOffset;
    // Implement the read functionality here
    return 0; // Placeholder return value
}
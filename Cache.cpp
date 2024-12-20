#include <iostream>
#include "Cache.hpp"
#include "AddressDecoder.hpp"

Cache::Cache(Memory* mDisplay, int size, int associativity, int blockSize)
    :decoder(size / (associativity * blockSize), blockSize){ // Initialize decoder using initializer list{
    this->size =size;
    this->associativity = associativity;
    this->blockSize = blockSize;
    this->mDisplay = mDisplay;
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

unsigned int Cache::read(unsigned long address) {
    AddressComponents components = decoder.decodeAddress(address);
    unsigned long tag = components.tag;
    unsigned long setIndex = components.setIndex;
    unsigned long blockOffset = components.blockOffset;
    // Implement the read functionality here, using mDisplay if necessary
    if (mDisplay) {
        std::cout << "Reading address: " << address << std::endl;
    }
    return 0; // Placeholder return value
}
#include <iostream>
#include "Cache.hpp"
#include "AddressDecoder.hpp"

Cache::Cache(int size, int associativity, int blockSize){
    this->size = size;
    this->associativity = associativity;
    this->blockSize = blockSize;
    int setNum = size/(associativity * blockSize);
    decoder = AddressDecoder(blockSize, setNum);
    sets = Set*[setNum];

    for (int i = 0; i < setNum; i++) {
        sets[i] = new Set(associativity, blockSize);
    }

}

int Cache::getSize(){
    return(this->size);
}

int Cache::getAssociativity(){
    return(this->associativity);
}

int Cache::getBlockSize(){
    return(this->blockSize);
}

unsigned char Cache::read(unsigned long address){
    unsigned long tag, setIndex, blockOffset;
    decoder.decodeAddress(address, tag, setIndex, blockOffset);

    Set* set = sets[setIndex];
    return set->loadBlock(tag, blockOffset);
}

void Cache::write(){
     unsigned long tag, setIndex, blockOffset;
    decoder.decode(address, tag, setIndex, blockOffset);

    // Access the appropriate set and write the value
    Set* set = sets[setIndex];
    set->writeBlock(tag, blockOffset, value);
}
void Cache::display(){
        for (int i = 0; i < size/(associativity * blockSize); i++) {
        std::cout << "Set " << i << ": ";
        sets[i]->display();
    }
}
#ifndef Block_hpp
#define Block_hpp

#include "Memory.hpp"
#include <stdio.h>
#include <chrono>

// Implement the block class in this file
// This should be the first class you do after memory 

class Block {
public:
    Block(Memory* memory, int block_size);
    unsigned char blockRead(unsigned long blockOffset);
    void blockWrite(unsigned long blockOffset, unsigned char new_value);
    void loadFromMemory(unsigned long address);
    void writeToMemory(unsigned long address);
    void display();

    unsigned long valid;
    unsigned long dirty;
    unsigned long tag;
    long stamp;

private:
    Memory* mainMemory;
    int blockSize;
    unsigned char* data;
    
    
};

Block::Block(Memory* memory, int block_size) {
    // Set the main memory pointer
    this->mainMemory = memory;
    this->blockSize = block_size;
    // Create an array of unsigned chars to hold Block byte data
    this->data = new unsigned char[block_size];
    // Indicates whether the block has been used or not
    // 0 means it has not been used
    // 1 means it has been used
    this->valid = 0;
    this->dirty = 0;
}

unsigned char Block::blockRead(unsigned long blockOffset) {
    // Read the byte from the block with the block offset as the address 
    // Update the timestamp on each access 
    std::chrono::high_resolution_clock stamp;
    long nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(stamp.now().time_since_epoch()).count();
    this->stamp = nanoSec;
    return data[blockOffset];
}

void Block::blockWrite(unsigned long blockOffset, unsigned char new_value) {
    // Write the byte with the block offset as the address
    // update the timestamp 
    std::chrono::high_resolution_clock stamp;
    long nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(stamp.now().time_since_epoch()).count();
    this->stamp = nanoSec;
    data[blockOffset] = new_value;
}

void Block::loadFromMemory(unsigned long address) {
    // These should simply loop and load the correct number of bytes to fill the Block from/to memory
    // This means that we should go to an address in memory and load BLOCK_SIZE bytes into the block FROM memory
    printf("Loading block from memory\n");
    printf("Address: %lu\n", address);
        for (int i = 0; i < blockSize; i++) {
            data[i] = mainMemory->getByte(address + i);
            // Update the valid bit
            valid = 1;
            // 
        }
}

void Block::writeToMemory(unsigned long address) {
    // Write the block to memory
    for (int i = 0; i < blockSize; i++) {
        mainMemory->setBytes(address);
    }
}

void Block::display() {
    // Print the valid, tag, dirty, and timestamp
    printf("    Valid: %lu ", valid);
    printf("    Tag: %lu ", tag);
    printf("    Dirty: %lu\n", dirty);
    printf("    Timestamp: %ld\n", stamp);

    // Print the bytes of the block from the cache
    for (int i = 0; i < blockSize; i++) {
        printf("    %02X ", data[i]);
    }
    printf("\n");
}  

#endif
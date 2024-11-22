#include "Block.hpp"
#include <stdio.h>
#include <chrono>
// Implement the block class in this file
// This should be the first class you do after memory 

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
    // Read byte from the block with the block offset as the address
    std::chrono::high_resolution_clock stamp;
    long nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(stamp.now().time_since_epoch()).count();
    this->stamp = nanoSec;
    return data[blockOffset];
}

void Block::blockWrite(unsigned long blockOffset, unsigned char new_value) {
    // Write the byte with the block offset as the address
    std::chrono::high_resolution_clock stamp;
    long nanoSec = std::chrono::duration_cast<std::chrono::nanoseconds>(stamp.now().time_since_epoch()).count();
    this->stamp = nanoSec;
    data[blockOffset] = new_value;
}

void Block::loadFromMemory(unsigned long address) {
 // Loops and loads bytes to fill the Block from/to memory
 printf("Loading block from memory\n");
 printf("Address: %lu\n", address);
    for (int i = 0; i < blockSize; i++) {
        data[i] = mainMemory->getByte(address + i);
        // Update the valid bit
        valid = 1;
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

    // Print the data in the block
    for (int i = 0; i < blockSize; i++) {
        printf("    %02X ", data[i]);
    }
    printf("\n");
}  


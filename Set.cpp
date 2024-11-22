#include <stdio.h>

#include "Set.hpp"
#include "Block.hpp"
#include "PerformanceCounter.hpp"
#include "AddressDecoder.hpp"

Set::Set(int num_blocks, int block_size, Memory* mainMemory, AddressDecoder* addressDecoder, PerformanceCounter* performanceCounter) {
    this->block_size = block_size;
    this->num_blocks = num_blocks;
    blocks = new Block*[num_blocks];
    this->addressDecoder = addressDecoder;
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = new Block(mainMemory, block_size);
        blocks[i]->valid = 0;
        blocks[i]->dirty = 0;
    }
    this->performanceCounter = performanceCounter;
}

unsigned char Set::setRead(unsigned long address) {
    performanceCounter->incrementAccessCount();
    unsigned long blockNum = num_blocks;
    for (unsigned long i = 0; i < blockNum; i++) {
        if (blocks[i]->valid == 1 && blocks[i]->tag == addressDecoder->getTag(address)) {
            printf("CACHE HIT DETECTED\n");
            performanceCounter->incrementHitCount();
            blocks[i]->tag = addressDecoder->getTag(address);
            return blocks[i]->blockRead(addressDecoder->decodeBlockOffset(address));
        }
    }
    printf("CACHE MISS DETECTED\n");
    performanceCounter->incrementMissCount();
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i]->valid == 0) {
            blocks[i]->loadFromMemory(address);
            blocks[i]->tag = addressDecoder->getTag(address);
            return blocks[i]->blockRead(addressDecoder->decodeBlockOffset(address)); 
        }
    }
    Block* lru_block = blocks[0];
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i]->stamp < lru_block->stamp) {
            lru_block = blocks[i];
        }
    }
    if (lru_block->dirty == 1) {
        lru_block->writeToMemory(address);
        performanceCounter->incrementWriteBackCount();
    }
    lru_block->loadFromMemory(address);
    return lru_block->blockRead(addressDecoder->getBlockOffset(address));
}

void Set::setWrite(unsigned long address, unsigned char new_value) {
    performanceCounter->incrementAccessCount();
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i]->tag == addressDecoder->getTag(address)) {
            blocks[i]->tag = addressDecoder->getTag(address);
            blocks[i]->dirty = 1;
            return blocks[i]->blockWrite(addressDecoder->decodeBlockOffset(address), new_value);
        }
    }
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i]->valid == 0) {
            blocks[i]->loadFromMemory(address);
            blocks[i]->tag = addressDecoder->getTag(address);
            return blocks[i]->blockWrite(addressDecoder->getBlockOffset(address), new_value);
        }
    }
    Block* lru_block = blocks[0];
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i]->stamp < lru_block->stamp) {
            lru_block = blocks[i];
        }
    }
    if (lru_block->dirty == 1) {
        lru_block->writeToMemory(address);
        performanceCounter->incrementWriteBackCount();
    }
    lru_block->loadFromMemory(address);
}

void Set::setDump() {
    printf("  Blocks\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("   %d\n", i);
        blocks[i]->display();
    }
}
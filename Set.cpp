#include "Set.hpp"
#include "Block.cpp"
#include <iostream>

//Note: LRU stands for Least Recently Used, which is a cache replacement policy 

// Constructor
Set::Set(int associativity, int blockSize) : associativity(associativity) {
    // Initialize the blocks in the set
    for (int i = 0; i < associativity; ++i) {
        blocks.push_back(Block(blockSize));
    }
}

// Find a block in the set based on the address
Block* Set::findBlock(unsigned long address) {
    for (Block& block : blocks) {
        if (block.getTag() == (address >> (block.getBlockOffsetBits() + setIndexBits))) {
            return &block;
        }
    }
    return nullptr; // Block not found
}

// Load a block into the set
void Set::loadBlock(const Block& newBlock) {
    // Check if there is an empty block in the set
    for (Block& block : blocks) {
        if (!block->isValid()) {
            block = newBlock;
            block.setValid(true);
            return;
        }
    }

    // If no empty block is found, evict a block using LRU policy
    evictBlock();

    // Load the new block into the evicted block's position
    for (Block& block : blocks) {
        if (!block.isValid()) {
            block = newBlock;
            block->setValid(true);
            return;
        }
    }
}

// Evict a block from the set (LRU)
void Set::evictBlock() {
    int lruIndex = lruList.front(); // Get the least recently used block index
    lruList.pop_front(); // Remove it from the LRU list
    blocks[lruIndex].setValid(false); // Invalidate the block
    lruList.push_back(lruIndex); // Move it to the back of the list
    lruIterators[lruIndex] = --lruList.end(); // Update the iterator
}

// Display the contents of the set
void Set::display() {
    std::cout << "Set contents:" << std::endl;
    for (int i = 0; i < associativity; ++i) {
        std::cout << "Block " << i << ": "
                  << "Tag: " << blocks[i].getTag() 
                  << ", Valid: " << blocks[i].isValid() 
                  << ", Data: " << blocks[i].readData() 
                  << std::endl;
    }
}
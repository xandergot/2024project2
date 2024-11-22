#ifndef SET_H
#define SET_H
#include "Block.hpp"
#include "AddressDecoder.hpp"
#include "PerformanceCounter.hpp"

class Set {
    public:
        // Array of pointers to Blocks
        int block_size;
        int num_blocks;
        PerformanceCounter* performanceCounter;
        Block** blocks;
        AddressDecoder* addressDecoder;
        // The constructor takes in number of blocks and block size
        // As well as a pointer to the main memory and an address decoder
        Set(int num_blocks, int block_size, Memory* mainMemory, AddressDecoder* addressDecoder, PerformanceCounter* performanceCounter);
        unsigned char setRead(unsigned long address);
        void setWrite(unsigned long address, unsigned char new_value);
        void setDump();
};
#endif
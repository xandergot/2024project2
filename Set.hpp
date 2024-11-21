#ifndef Set_hpp
#define Set_hpp

#include "Block.hpp"

class Set {
    private:
        int associativity;
        Block* blocks;

    public:
        // Constructor
        Set(int associativity, int blockSize);

        // Core functions
        Block* findBlock(unsigned long address);
        Block* loadBlock(unsigned long address);
        void evictBlock();
        void display();

};

#endif
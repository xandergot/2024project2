#ifndef Cache_hpp // checks if Cache_hpp is defined.
#define Cache_hpp // if not defined, define Cache_hpp
#include "Set.hpp"
#include "AddressDecoder.hpp"
#include "Memory.hpp"

class Cache{
    private:
        int size;
        int associativity;
        int blockSize;
        AddressDecoder decoder;
        bool mDisplay;
        Set** sets;

    public:

        Cache(Memory* mDisplay, int size, int associativity, int blockSize);

        // Getters
        int getSize();
        int getAssociativity();
        int getBlockSize();

        // Setters
        void setSize(int size);
        void setAssociativity(int associativity);
        void setBlockSize(int blockSize);

        // Core operations
        unsigned int read(unsigned long address);
        void write(unsigned long address, unsigned int value);
        void display();
   
};

#endif // closes the ifndef block
// The program would continue here
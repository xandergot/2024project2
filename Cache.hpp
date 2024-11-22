#ifndef Cache_hpp // checks if Cache_hpp is defined.
// If Cache_hpp is defined, the program skip to after the #endif
#define Cache_hpp // if not defined, define Cache_hpp
#include "Set.hpp"
#include "AddressDecoder.hpp"

class Cache{
    private:
        int size;
        int associativity;
        int blockSize;
        AddressDecoder decoder;
        bool mDisplay;
        Set** sets;

    public:

        Cache(unsigned int mDisplay, int size, int associativity, int blockSize);

        // Getters
        int getSize();
        int getAssociativity();
        int getBlockSize();

        // Setters
        void setSize(int size);
        void setAssociativity(int associativity);
        void setBlockSize(int blockSize);

        // Core operations
        unsigned char read(unsigned long address);
        void write(unsigned long address, unsigned char value);
        void display();
   
};

#endif // closes the ifndef block
// The program would continue here
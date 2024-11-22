#ifndef AddressDecoder_hpp
#define AddressDecoder_hpp

struct AddressComponents {
    int tag;
    int setIndex;
    int blockOffset;
};

class AddressDecoder {
private:
    int numSets;
    int blockSize;
    int tagBits;
    int setIndexBits;
    int blockOffsetBits;

public:
    AddressDecoder(int numSets, int blockSize); // Constructor
    AddressComponents decodeAddress(int address) const; // Decode the address
    int getTag(int address) const;
    unsigned long decodeBlockOffset(unsigned long address) const;
    unsigned long getBlockOffset(unsigned long address) const;
};

#endif
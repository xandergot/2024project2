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

};

#endif
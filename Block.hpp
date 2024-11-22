#ifndef Block_hpp
#define Block_hpp

class Block {
private:
    unsigned long tag;
    bool valid;
    int data;  // is this an int?
    bool dirtyBit;
    int timestamp;

public:
    Block();
   
    unsigned long getTag();
    bool isValid();

    void setTag(unsigned long t);
    void setValid(bool v);

    int readData();
    void writeData(int d);

    void setDirty(bool d);
};


#endif
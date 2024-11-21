#ifndef Block_hpp
#define Block_hpp

class Block {
private:
    unsigned long tag;
    bool valid;
    int data;  // is this an int?

public:
    // Constructor
    Block() : tag(0), valid(false), data(0) {}

    // Getters
    unsigned long getTag() const { return tag; }
    bool isValid() const { return valid; }
    int getData() const { return data; }

    // Setters
    void setTag(unsigned long t) { tag = t; }
    void setValid(bool v) { valid = v; }
    void setData(int d) { data = d; }

    // Core functions
    int readData() const { return data; }
    void writeData(int d) { data = d; }
};


#endif
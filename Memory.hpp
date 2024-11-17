#ifndef Memory_hpp
#define Memory_hpp
class Memory{
    private:
        int memorySize;
        unsigned char* MainMemory; 

    public:
        Memory(int size);

        unsigned char getByte(unsigned long address);

        void setBytes(unsigned long address);

        int getMemorySize();

        void displayBits();
};
#endif
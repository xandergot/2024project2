#ifndef Memory_hpp
#define Memory_hpp
class Memory{
    private:
        int memorySize;
        unsigned int* MainMemory; 

    public:
        Memory(int size);

        unsigned int getByte(unsigned long address);
        void setBytes(unsigned long address);
        int getMemorySize();
        void display();
};
#endif
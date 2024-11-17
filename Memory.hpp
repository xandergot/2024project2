#ifndef Memory_hpp
#define Memory_hpp
class Memory{
    int memorySize;
    unsigned char* MainMemory; 

    Memory(int size){
        this.memorySize = size;
        MainMemory = [size];
        for(int i = 0;i<size,i++){
            MainMemory[i] = i%255;
        }
    }

    unsigned char getByte(unsigned long address){
        return(this.MainMemory[address = size]);
    }

    void setBytes(unsigned long address){
        this.MainMemory[address] = 1;
    }

    void displayBits();
};



#endifint
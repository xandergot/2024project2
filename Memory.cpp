#include "Memory.hpp"


Memory::Memory(int size){
        this->memorySize = size;
        MainMemory = [size];
        for(int i = 0;i<size,i++){
            MainMemory[i] = i%255;
        }
}

void Memory::setBytes(unsigned long address){
    this->MainMemory[address] = 1;
}

unsigned char Memory::getByte(unsigned long address){
    return(this->MainMemory[address = size]);
}


int Memory::getMemorySize(){
    return(this.memorySize);
}

void Memory::displayBits(){
    
}
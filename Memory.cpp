#include <Memmory.hpp>


Memmory::Memory(int size){
        this.memorySize = size;
        MainMemory = [size];
        for(int i = 0;i<size,i++){
            MainMemory[i] = i%255;
        }
}

void Memmory::setBytes(unsigned long address){
    this.MainMemory[address] = 1;
}

unsigned char Memmory::getByte(unsigned long address){
    return(this.MainMemory[address = size]);
}


int Memmory::getMemorySize(){
    return(this.memorySize);
}

void Memmory::displayBits(){
    
}
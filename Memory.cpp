#include "Memory.hpp"
#include <iostream> // io stream allows you use cout and cin

Memory::Memory(int size) {
    this->memorySize = size;
    MainMemory = new unsigned char[size]; // Correctly allocate memory
    for (int i = 0; i < size; i++) { // Use semicolon instead of comma
        MainMemory[i] = i % 255;
    }
}

Memory::~Memory() {
    delete[] MainMemory; // Free allocated memory
}

void Memory::setBytes(unsigned long address) {
    this->MainMemory[address] = 1;
}

unsigned char Memory::getByte(unsigned long address) {
    return this->MainMemory[address]; // Correct array access
}

int Memory::getMemorySize() {
    return this->memorySize; // Use arrow operator for member access
}

void Memory::display() {
    for (int i = 0; i < memorySize; i++) {
        std::bitset<8> bits(MainMemory[i]);
        std::cout << "Address " << i << ": " << bits << std::endl;
    }
}
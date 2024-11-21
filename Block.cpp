#include "Block.hpp"

Block::Block(){
    this->tag = 0;
    this->valid = false;
    this->data = 0;
}

unsigned long Block::getTag(){ return this->tag; }
bool Block::isValid() { return this->valid; }

void Block::setTag(unsigned long t) { tag = t; }
void Block::setValid(bool v) { valid = v; }

int Block::readData(){ return this->data;}
void Block::writeData(int d) { this->data = d; }
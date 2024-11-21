#include "PerformanceCounter.hpp"

PerformanceCounter::PerformanceCounter() : hits(0), misses(0), writeBacks(0) {}

void PerformanceCounter::incrementHits() {
    hits++;
}

void PerformanceCounter::incrementMisses() {
    misses++;
}

void PerformanceCounter::incrementWritebacks() {
    writeBacks++;
}

int PerformanceCounter::getHits() const {
    return hits;
}

int PerformanceCounter::getMisses() const {
    return misses;
}

int PerformanceCounter::getWritebacks() const {
    return writeBacks;
}

double PerformanceCounter::getMissRate() const {
    double totalAccesses = hits + misses;
    return (totalAccesses > 0) ? (static_cast<double>(misses) / totalAccesses) * 100 : 0;
}

double PerformanceCounter::getWritebackRate() const {
    double totalAccesses = hits + misses;
    return (totalAccesses > 0) ? (static_cast<double>(writeBacks) / totalAccesses) * 100 : 0;
}
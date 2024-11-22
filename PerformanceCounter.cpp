#include "PerformanceCounter.hpp"

// Constructor for the PerformanceCounter class
PerformanceCounter::PerformanceCounter() {
    // Initialize all variables to 0
    hits = 0;
    accesses = 0;
    misses = 0;
    writebacks = 0;
    miss_percentage = 0.0;
    writeback_percentage = 0.0;
}

// Function to increment the hits counter
void PerformanceCounter::incrementHitCount() {
    hits += 1;
} 

// Function to increment the accesses counter
void PerformanceCounter::incrementAccessCount() {
    accesses += 1;
}

// Function to increment the misses counter
void PerformanceCounter::incrementMissCount() {
    misses += 1;
}

// Function to increment the writebacks counter
void PerformanceCounter::incrementWriteBackCount() {
    writebacks += 1;
}

// Function to calculate the miss percentage
void PerformanceCounter::calculateMissPercentage() {
    if (accesses > 0) {
        miss_percentage = (static_cast<double>(misses) / accesses) * 100.0;
    } else {
        miss_percentage = 0.0;
    }
}

// Function to calculate the writeback percentage
void PerformanceCounter::calculateWritebackPercentage() {
    if (accesses > 0) {
        writeback_percentage = (static_cast<double>(writebacks) / accesses) * 100.0;
    } else {
        writeback_percentage = 0.0;
    }
}
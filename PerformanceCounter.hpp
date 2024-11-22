#ifndef PERFORMANCECOUNTER_H
#define PERFORMANCECOUNTER_H
// DONE: Add this after the Cache/Set/Block system is working 
// Keeps track of how many hits, misses, and writebacks happen in a simulation 
class PerformanceCounter {
    public:
        // Variables
        int hits;
        int accesses;
        int misses;
        int writebacks;
        int miss_percentage;
        int writeback_percentage;

        // Constructor
        PerformanceCounter();

        // Functions
        void incrementHitCount();
        void incrementAccessCount();
        void incrementMissCount();
        void incrementWriteBackCount();
        void calculateMissPercentage();
        void calculateWritebackPercentage();
};
#endif
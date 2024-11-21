#ifndef PerformanceCounter_hpp
#define PerformanceCounter_hpp

class PerformanceCounter {
private:
    int hits;
    int misses;
    int writeBacks;

public: 
    // Constructor
    PerformanceCounter();

    // Increment functions
    void incrementHits();
    void incrementMisses();
    void incrementWritebacks();

    // Getter functions
    int getHits() const;
    int getMisses() const;
    int getWritebacks() const;

    // Rate functions
    double getMissRate() const;
    double getWritebackRate() const;
};
};

#endif
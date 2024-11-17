#ifndef Cache_hpp // checks if Cache_hpp is defined.
// If Cache_hpp is defined, the program skip to after the #endif
#define Cache_hpp // if not defined, define Cache_hpp


class Cache{
    private:
        int size;
        int associativity;
        int blockSize;

    public:
        Cache(int size, int associativity, int blockSize);
        
        // Getters
        int getSize();
        int getAssociativity();
        int getBlockSize();

        // Setters
        void setSize(int size);
        void setAssociativity(int associativity);
        void setBlockSize(int blockSize);

        // Core operations
        void read();
        void write();
        void display();
   
};

#endif // closes the ifndef block
// The program would continue here
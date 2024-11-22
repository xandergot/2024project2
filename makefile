main.o: performanceCounter.o cache.o block.o addressDecoder.o simulation.o
	g++ memory.o performanceCounter.o set.o cache.o block.o addressDecoder.o  simulation.o -o test

addressDecoder.o: AddressDecoder.hpp
	g++ -c AddressDecoder.cpp

block.o: Block.hpp
	g++ -c Block.cpp

cache.o: Cache.hpp
	g++ -c Cache.cpp

memory.o: Memory.hpp
	g++ -c Memory.cpp

performanceCounter.o: PerformanceCounter.hpp
	g++ -c PerformanceCounter.cpp

set.o: Set.hpp
	g++ -c Set.cpp

simulation.o:
	g++ -c Simulation.cpp




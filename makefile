main.o: main.o preformanceCounter.o cache.o block.o addressDecoder.o simulation.o
	g++ memory.o preformanceCounter.o set.o cache.o block.o addressDecoder.o  simulation.o -o test

addressDecoder.o: AddressDecoder.hpp
	g++ -o AddressDecoder.cpp

block.o: Block.hpp
	g++ -c Block.cpp

cache.o: Cache.hpp
	g++ -c Cache.cpp

memory.o: Memory.hpp
	g++ -c Memory.cpp

preformanceCounter.o: preformanceCounter.hpp
	g++ -c preformanceCounter

set.o: Set.hpp
	g++ -c Set.cpp

simulation.o: Simulation.hpp
	g++ -c Simulation.cpp




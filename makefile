COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

Structures: Structures.hpp Node.hpp SingleNode.hpp DoubleNode.hpp LinkedList.hpp
	$(COMPILER) $(CPPFLAGS) -o structures Structures.cpp

clean:
	rm -f structures-test
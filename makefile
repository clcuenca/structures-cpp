COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

Structures: Structures.hpp Node.hpp SingleNode.hpp DoubleNode.hpp LinkedList.hpp
	$(COMPILER) $(CPPFLAGS) -o structures Structures.cpp

Test: LinkedListTest.hpp
	$(COMPILER) $(CPPFLAGS) -o structures-test StructuresTest.cpp

clean:
	rm -f structures-test
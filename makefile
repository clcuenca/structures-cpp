COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

structures-test: Structures.hpp
	$(COMPILER) $(CPPFLAGS) -o structures Structures.cpp

clean:
	rm -f structures-test
#include "LinkedList.hpp"
#include <iostream>

int main() {

	structures::LinkedList<int, int> linkedList;
	structures::LinkedList<int, int> otherLinkedList;

	for(int index = 0; index < 10; index++) 
		linkedList += index;

	for(int index = 10; index < 30; index++)
		otherLinkedList += index;

	std::cout << linkedList << std::endl;

	std::cout << linkedList + otherLinkedList << std::endl;

	return 0;
}
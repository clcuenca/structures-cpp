
#include "Structures.hpp"
#include "Node.hpp"
#include "SingleNode.hpp"
#include "DoubleNode.hpp"
#include "LinkedList.hpp"
#include <iostream>

int main() {

	structures::LinkedList<int> linkedList;
	structures::LinkedList<int> otherLinkedList;

	for(int index = 0; index < 10; index++) 
		linkedList += index;

	for(int index = 10; index < 30; index++)
		otherLinkedList += index;

	std::cout << linkedList << std::endl;

	std::cout << linkedList + otherLinkedList << std::endl;

	return 0;
}
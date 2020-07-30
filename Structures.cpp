
#include "Structures.hpp"
#include "Node.hpp"
#include "SingleNode.hpp"
#include "DoubleNode.hpp"
#include <iostream>

int main() {

	structures::Node<int> node = 10;
	structures::Node<int> other = 10;

	structures::SingleNode<int> singleNode = 69;
	structures::SingleNode<int> otherNode = 69;

	structures::DoubleNode<int> doubleNode = 13;
	structures::DoubleNode<int> otherDoubleNode = 13;

	if(node == other) {

		std::cout << "They're equal." << std::endl;

	}

	std::cout << node       << " " << other           << std::endl;
	std::cout << singleNode << " " << otherNode       << std::endl;
	std::cout << doubleNode << " " << otherDoubleNode << std::endl;

	return 0;
}
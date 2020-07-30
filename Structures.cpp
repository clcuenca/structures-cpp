
#include "Structures.hpp"
#include "Node.hpp"
#include <iostream>

int main() {

	structures::Node<int> node;
	structures::Node<int> other;

	node = 10;
	other = 10;

	if(node == other) {

		std::cout << "They're equal." << std::endl;

	}

	std::cout << node << " " << other << std::endl;


	return 0;
}
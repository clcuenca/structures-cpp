
#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include<iostream>

namespace structures {

	/// -------
	/// Classes

	template<typename Type>
	class Node;

	template<typename Type>
	class SingleNode;

	template<typename Type>
	class DoubleNode;

	template<typename Type, typename Index>
	class LinkedList;

    /// ------------------
	/// Template Functions

	template<typename Type>
	std::ostream& operator<< (std::ostream&, const structures::Node<Type>&);
	
	template<typename Type>
	std::istream& operator>> (std::istream&, structures::Node<Type>&);

	template<typename Type, typename Index>
	std::ostream& operator<< (std::ostream&, const structures::LinkedList<Type, Index>&);

	/// --------------
	/// Test Namespace

	namespace test {

		class LinkedListTest;

	}

}

#endif
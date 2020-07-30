#ifndef STRUCTURES_SINGLE_NODE_HPP
#define STRUCTURES_SINGLE_NODE_HPP

#include "Structures.hpp"
#include "Node.hpp"

/* 
 * SingleNode<Type>
 * Type - Type of data to be stored
 * Single List Node, contains one
 * reference to a sibling Node
 */
template<typename Type>
class structures::SingleNode: public structures::Node<Type>{

public:

	/// ------------
	/// Constructors

	SingleNode();
	SingleNode(const Type&);
	SingleNode(const structures::Node<Type>&);
	~SingleNode();

	/// ----------------
	/// Member Variables

	structures::Node<Type>* right;

};

/*
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: instantiates the SingleNode  
 */
template<typename Type>
structures::SingleNode<Type>::SingleNode():structures::Node<Type>(), right(0){}

/*
 * Function: Copy Constructor
 * Parameters: const Type&
 * Return: n/a
 * Description: Instantiates the single node with the given value 
 */
template<typename Type>
structures::SingleNode<Type>::SingleNode(const Type& type):structures::Node<Type>(type), right(0){}

/*
 * Function: Copy Constructor
 * Parameters: const Node<Type>&
 * Return: n/a
 * Description: instantiates the SingleNode with the data of the given node 
 */
template<typename Type>
structures::SingleNode<Type>::SingleNode(const structures::Node<Type>& node):structures::Node<Type>(node), right(0){}

/*
 * Function: deconstructor
 * Parameters: n/a
 * Return: n/a
 * Description: removes the reference from the right pointer 
 */
template<typename Type>
structures::SingleNode<Type>::~SingleNode(){

	this->right = 0x00;

}

#endif
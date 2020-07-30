#include "Structures.hpp"
#include "Node.hpp"

/// -----------------------------
/// Constructors - Implementation

/*
 * Function: Default Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Creates the node and calls the Type's default 
 * constructor
 */ 
template<typename Type>
structures::Node<Type>::Node(): data() {}

/*
 * Function: Default Constructor
 * Parameters: Immutable Reference to Type
 * Return: n/a
 * Description: Sets the value of type to the given value. If any
 */
template<typename Type>
structures::Node<Type>::Node(const Type& data): data() {

	this->data = data;

}

/* 
 * Function: Copy Constructor
 * Parameters: Immutable Reference to Node<Type>
 * Return: n/a
 * Description: Sets the value of data to the given ListNode's 
 * data
 */
template<typename Type>
structures::Node<Type>::Node(const Node<Type>& node): data() {

	this->data = node.data;

}

/*
 * Function: Destructor
 * Parameters: n/a
 * Return: n/a
 * Description: Explicitly calls the deconstructor of Type
 */
template<typename Type>
structures::Node<Type>::~Node() {

	this.data.~Type();

}

/// ------------------------
/// Methods - Implementation

/*
 * Function: Get Data
 * Parameters: n/a
 * Return: Reference to Immutable data of Type
 * Description: Returns the data stored in the Node<Type>
 */
template<typename Type>
const Type& structures::Node<Type>::getData() const {

	return this->data;

}

/*
 * Function: Set Data
 * Parameters: Referenct to Immutable data of Type
 * Return: n/a
 * Description: Sets the data stored in the Node<Type>
 */
template<typename Type>
void structures::Node<Type>::setData(const Type& type) {

	this->data = data;

}

#ifndef STRUCTURES_LINKED_LIST_HPP
#define STRUCTURES_LINKED_LIST_HPP

#include "Node.hpp"
#include "SingleNode.hpp"

template<typename Type>
class structures::LinkedList {

protected:

	structures::Node<Type>* head;
	structures::Node<Type>* tail;

public:

	/// -------------
	/// Rule of Three

	LinkedList();
	LinkedList(const structures::LinkedList<Type>&);
	~LinkedList();

    /// -------
	/// Methods

	bool isEmpty() const;
	bool isEqual(const structures::LinkedList<Type>&) const;

	/// --------
	/// Mutators

	void prepend(const Type&);
	void append(const Type&);

	void prepend(const structures::Node<Type>&);
	void append(const structures::Node<Type>&);

	void prepend(const structures::LinkedList<Type>&);
	void append(const structures::LinkedList<Type>&);

	void setTo(const structures::LinkedList<Type>&);
	void clear();

};

/// -----------------------------
/// Constructors - Implementation

template<typename Type>
structures::LinkedList<Type>::LinkedList(): head(0), tail(0) {}

template<typename Type>
structures::LinkedList<Type>::LinkedList(const structures::LinkedList<Type>& linkedList) {

	this->setTo(linkedList);

}

template<typename Type>
structures::LinkedList<Type>::~LinkedList() {

	this->clear();

}

/// ------------------------
/// Methods - Implementation

/*
 * Function: isEmpty()
 * Parameters: n/s
 * Return: Boolean Value denoting an empty list
 * Description: Checks to see if the given list is empty
 */
template<typename Type>
bool structures::LinkedList<Type>::isEmpty() const {

	return (this->head == 0) && (this->tail == 0);

}

/*
 * Function: isEqual
 * Parameters: Reference to an Immutable LinkedList of Type
 * Return: Boolean value denoting list equivalency 
 * Description: Traverses each list to check for equivalency in Type
 * as long as Type has the != operator
 */
template<typename Type>
bool structures::LinkedList<Type>::isEqual(const structures::LinkedList<Type>& linkedList) const {

	/// We want to set the traversal nodes
	structures::SingleNode<Type>* thisNode =
	static_cast<structures::SingleNode<Type>*> (this->head);

	structures::SingleNode<Type>* thatNode =
	static_cast<structures::SingleNode<Type>*> (linkedList.head);

	/// Traverse until either or both have gotten to the end
	while(thisNode && thatNode) {

		if(*thisNode != *thatNode) return false;

		// Traverse
		thisNode = static_cast<structures::SingleNode<Type>*> (thisNode->right);
		thatNode = static_cast<structures::SingleNode<Type>*> (thatNode->right);

	}

	// We mat have ran out of nodes to traverse in either list,
	// Or they're both at the end
	return !thisNode && !thatNode;

}

/*
 * Function: Prepend
 * Parameters: Reference to Immutable Type
 * Return: n/a
 * Description: Adds a new node with the given value to the beginning of the list 
 */
template<typename Type>
void structures::LinkedList<Type>::prepend(const Type& type) {

	// The list may be empty
	if(!this->head) {

		this->head = new structures::SingleNode<Type>(type);
		this->tail = this->head;

	// The list is not empty
	} else {

		structures::SingleNode<Type>* node = new structures::SingleNode<Type>(type);

		node->right = this->head;
		this->head = node;

	}

}

template<typename Type>
void structures::LinkedList<Type>::append(const Type& type) {

	
}

#endif
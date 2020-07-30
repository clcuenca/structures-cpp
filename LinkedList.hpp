
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

	/// --------------------
	/// Overloaded Operators

	bool operator == (const structures::LinkedList<Type>&) const;
	bool operator != (const structures::LinkedList<Type>&) const;

	LinkedList<Type>& operator  = (const structures::LinkedList<Type>&);
	LinkedList<Type>& operator += (const structures::LinkedList<Type>&);
	LinkedList<Type>& operator += (const structures::Node<Type>&);
	LinkedList<Type>& operator += (const Type&);

	const LinkedList<Type> operator + (const structures::LinkedList<Type>&);


	friend std::ostream& operator<< <Type>(std::ostream&, const structures::LinkedList<Type>&);

};

/// -----------------------------
/// Constructors - Implementation

/* 
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the LinkedList
 */
template<typename Type>
structures::LinkedList<Type>::LinkedList(): head(0x00), tail(0x00) {}

/* 
 * Function: Copy Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the LinkedList to the state of the given LinkedList
 */
template<typename Type>
structures::LinkedList<Type>::LinkedList(const structures::LinkedList<Type>& linkedList): head(0x00), tail(0x00) {

	this->setTo(linkedList);

}

/* 
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: clears the LinkedList and values
 */
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

	return (this->head == 0x00) && (this->tail == 0x00);

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

/*
 * Function: Append
 * Parameters: Reference to Immutable Type
 * Return: n/a
 * Description: Appends a new node with the given value of Type 
 */
template<typename Type>
void structures::LinkedList<Type>::append(const Type& type) {

	// If the list empty
	if(!this->head) {

		this->head = new structures::SingleNode<Type>(type);
		this->tail = this->head;

		// The list is not empty
	} else {

		structures::SingleNode<Type>* node = new structures::SingleNode<Type>(type);

		static_cast<structures::SingleNode<Type>*>(this->tail)->right = node;

		this->tail = node;

	}

}

/*
 * Function: prepend
 * Parameters: Reference to Immutable Node of Type
 * Return: n/a
 * Description: Adds the given Node to the beginning of the list
 */
template<typename Type>
void structures::LinkedList<Type>::prepend(const structures::Node<Type>& node) {

	// Create the head
	if(!this->head) {

		this->head = new structures::SingleNode<Type>(node);
		this->tail = this->head;

	} else {

		structures::SingleNode<Type>* node = new structures::SingleNode<Type>(node);

		node->right = this->head;
		this->head = node;

	}

}

/*
 * Function: Append
 * Parameters: Reference to Immutable Node of Type
 * Return: n/a
 * Description: Adds the given Node to the end of the list
 */
template<typename Type>
void structures::LinkedList<Type>::append(const structures::Node<Type>& node) {

	if(!this->head) {

		this->head = new structures::SingleNode<Type>(node);
		this->tail = this->head;

	} else {

		structures::SingleNode<Type>* node = new structures::SingleNode<Type>(node);

		static_cast<structures::SingleNode<Type>*>(this->tail)->right = node;

		this->tail = node;

	}

}

/*
 * Function: Prepend
 * Parameters: Reference to Immutable LinkedList of Type
 * Return: n/a
 * Description: Creates a copy of the given list, and adds it to
 * the beginning of the current list 
 */
template<typename Type>
void structures::LinkedList<Type>::prepend(const structures::LinkedList<Type>& list){

	if(!list.isEmpty()){

		// Create a copy of the current head, and start the traversal in the next node
		structures::SingleNode<Type>* node    = 
		new structures::SingleNode<Type>(*list.head);

		structures::SingleNode<Type>* current = 
			static_cast<structures::SingleNode<Type>*>(list.head)->right;

		structures::SingleNode<Type>* newHead = node;

		// We loop while there are intermediate nodes
		while(current){

			// Set the next value
			node->right = new structures::SingleNode<Type>(*current);

			// Set the new tail and traverse
			node    = 
			static_cast<structures::SingleNode<Type>*> (node->right);

			current = 
			static_cast<structures::SingleNode<Type>*> (current->right);

		}

		// If the current state is empty
		if(this->isEmpty()){

			// Resolve the head and the tail
			this->head = newHead;
			this->tail = node;

		// Otherwise, the tail is already resolved
		}else{

			// Just set the head
			node->right = this->head;
			this->head = newHead;

		}

	}

}

/*
 * Function: Append
 * Parameters: Reference to Immutable LinkedList of Type
 * Return: n/a
 * Description: Creates a copy of the given abstract list, and 
 * adds the copy to the end of the current list 
 */
template<typename Type>
void structures::LinkedList<Type>::append(const structures::LinkedList<Type>& list){

	if(!list.isEmpty()){

		// Create a copy of the current head, and start the traversal in the next node
		structures::SingleNode<Type>* node    = 
		new structures::SingleNode<Type>(*list.head);

		structures::SingleNode<Type>* current = 
			static_cast<structures::SingleNode<Type>*>(
				static_cast<structures::SingleNode<Type>*>(list.head)->right);

		structures::SingleNode<Type>* newHead = node;

		// We loop while there are intermediate nodes
		while(current){

			// Set the next value
			node->right = new structures::SingleNode<Type>(*current);

			// Set the new tail and traverse
			node    = 
			static_cast<structures::SingleNode<Type>*> (node->right);

			current = 
			static_cast<structures::SingleNode<Type>*> (current->right);

		}

		// If the current state is empty
		if(this->isEmpty()){

			this->head = newHead;
			this->tail = node;

		// Otherwise, the head is already resolved
		}else{

			// Set the proper values
			static_cast<structures::SingleNode<Type>*>(this->tail)
			->right = newHead;

			this->tail = node;

		}

	}

}

/*
 * Function: setTo
 * Parameters: Reference to Immutable Abstract List of Type
 * Return: n/a
 * Description: Sets the current state to the state of the given
 * list 
 */
template<typename Type>
void structures::LinkedList<Type>::setTo(const structures::LinkedList<Type>& list){

	// First, we call clear
	if(!this->isEmpty()) this->clear();

	// If we had an empty list, we already achieved what we wanted
	// and we will simply "append" a copy of the given list
	if(!list.isEmpty()) this->append(list);

}

/*
 * Function: Clear
 * Parameters: n/a
 * Return: n/a
 * Description: Releases the entire list 
 */
template<typename Type>
void structures::LinkedList<Type>::clear(){

	// Beginning with the Next node from the head
	structures::SingleNode<Type>* current = 
	static_cast<structures::SingleNode<Type>*> (this->head);

	while(current){

		// Set the traversal pointer
		current = static_cast<structures::SingleNode<Type>*>(current->right);

		// Release the memory
		delete this->head;

		// Reset the pointer
		this->head = current;

	}

	// Reset the head and the tail
	this->head = 0x00;
	this->tail = 0x00;

}

/// -------------------------------------
/// Overloaded Operators - Implementation

template<typename Type>
bool structures::LinkedList<Type>::operator == (const structures::LinkedList<Type>& linkedList) const {

	return this->isEqual(linkedList);

}

template<typename Type>
bool structures::LinkedList<Type>::operator != (const structures::LinkedList<Type>& linkedList) const {

	return !(this->isEqual(linkedList));

}

template<typename Type>
structures::LinkedList<Type>& structures::LinkedList<Type>::operator  = (const structures::LinkedList<Type>& linkedList) {

	this->setTo(linkedList);

	return *this;

}

template<typename Type>
structures::LinkedList<Type>& structures::LinkedList<Type>::operator += (const structures::LinkedList<Type>& linkedList) {

	this->append(linkedList);

	return *this;

}

template<typename Type>
structures::LinkedList<Type>& structures::LinkedList<Type>::operator += (const structures::Node<Type>& node) {

	this->append(node);

	return *this;

}

template<typename Type>
structures::LinkedList<Type>& structures::LinkedList<Type>::operator += (const Type& data) {

	this->append(data);

	return *this;

}

template<typename Type>
const structures::LinkedList<Type> structures::LinkedList<Type>::operator + (const structures::LinkedList<Type>& linkedList) {

	structures::LinkedList<Type> newList = *this;

	newList += linkedList;

	return newList;

}

/*
 * Function: Operator << (Stream insertion operator)
 * Parameters: output stream, reference to a LinkedList<Type>
 * Return: the modified output stream
 * Description: inserts the linked list's data to the output stream, if the data of Type
 * is supported by the stream insertion operator
 */
template<typename Type>
std::ostream& structures::operator<< (std::ostream& outputStream, const structures::LinkedList<Type>& linkedList) {

	structures::SingleNode<Type>* current = static_cast<structures::SingleNode<Type>*>(linkedList.head);

	while(current) {

		outputStream << *current << " ";

		current = static_cast<structures::SingleNode<Type>*>(current->right);

	}

    return outputStream; 

}

#endif
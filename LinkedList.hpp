
#ifndef STRUCTURES_LINKED_LIST_HPP
#define STRUCTURES_LINKED_LIST_HPP

#include "Node.hpp"
#include "SingleNode.hpp"

template<typename Type, typename Index>
class structures::LinkedList {

protected:

	structures::Node<Type>* head;
	structures::Node<Type>* tail;

public:

	/// -------------
	/// Rule of Three

	LinkedList();
	LinkedList(const structures::LinkedList<Type, Index>&);
	~LinkedList();

    /// -------
	/// Methods

	bool isEmpty() const;
	bool isEqual(const structures::LinkedList<Type, Index>&) const;

	/// --------
	/// Mutators

	void insert(Index&, const Type&);

	void prepend(const Type&);
	void append(const Type&);

	void prepend(const structures::Node<Type>&);
	void append(const structures::Node<Type>&);

	void prepend(const structures::LinkedList<Type, Index>&);
	void append(const structures::LinkedList<Type, Index>&);

	void setTo(const structures::LinkedList<Type, Index>&);
	void clear();

	/// --------------------
	/// Overloaded Operators

	bool operator == (const structures::LinkedList<Type, Index>&) const;
	bool operator != (const structures::LinkedList<Type, Index>&) const;

	LinkedList<Type, Index>& operator  = (const structures::LinkedList<Type, Index>&);
	LinkedList<Type, Index>& operator += (const structures::LinkedList<Type, Index>&);
	LinkedList<Type, Index>& operator += (const structures::Node<Type>&);
	LinkedList<Type, Index>& operator += (const Type&);

	const LinkedList<Type, Index> operator + (const structures::LinkedList<Type, Index>&);


	friend std::ostream& operator<< <Type, Index>(std::ostream&, const structures::LinkedList<Type, Index>&);

};

/// -----------------------------
/// Constructors - Implementation

/* 
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the LinkedList
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>::LinkedList(): head(0x00), tail(0x00) {}

/* 
 * Function: Copy Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the LinkedList to the state of the given LinkedList
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>::LinkedList(const structures::LinkedList<Type, Index>& linkedList): head(0x00), tail(0x00) {

	this->setTo(linkedList);

}

/* 
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: clears the LinkedList and values
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>::~LinkedList() {

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
template<typename Type, typename Index>
bool structures::LinkedList<Type, Index>::isEmpty() const {

	return (this->head == 0x00) && (this->tail == 0x00);

}

/*
 * Function: isEqual
 * Parameters: Reference to an Immutable LinkedList of Type
 * Return: Boolean value denoting list equivalency 
 * Description: Traverses each list to check for equivalency in Type
 * as long as Type has the != operator
 */
template<typename Type, typename Index>
bool structures::LinkedList<Type, Index>::isEqual(const structures::LinkedList<Type, Index>& linkedList) const {

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

template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::insert(Index& index, const Type& data) {

	if(!this->head) {

		this->head = new structures::SingleNode<Type>(data);
		this->tail = this->head;

	} else {

		structures::SingleNode<Type>* node = new structures::SingleNode<Type>(data);

		structures::SingleNode<Type>* trailer = 
			static_cast<structures::SingleNode<Type>*>(this->head);

		structures::SingleNode<Type>* current = 
			static_cast<structures::SingleNode<Type>*>(
				static_cast<structures::SingleNode<Type>*>(this->head)->right);

		while(index-- && current) {

			current = static_cast<structures::SingleNode<Type>*>(current->right);
			trailer = static_cast<structures::SingleNode<Type>*>(trailer->right);

		}

	}

}

/*
 * Function: Prepend
 * Parameters: Reference to Immutable Type
 * Return: n/a
 * Description: Adds a new node with the given value to the beginning of the list 
 */
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::prepend(const Type& type) {

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::append(const Type& type) {

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::prepend(const structures::Node<Type>& node) {

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::append(const structures::Node<Type>& node) {

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::prepend(const structures::LinkedList<Type, Index>& list){

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::append(const structures::LinkedList<Type, Index>& list){

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::setTo(const structures::LinkedList<Type, Index>& list){

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
template<typename Type, typename Index>
void structures::LinkedList<Type, Index>::clear(){

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

/*
 * Function: Operator == (Equality Operator)
 * Parameters: Reference to Immutable LinkedList<Type, Index>
 * Return: Boolean value denoting equivalency of lists
 * Description: Returns the result of the equality of the given
 * list
 */
template<typename Type, typename Index>
bool structures::LinkedList<Type, Index>::operator == (const structures::LinkedList<Type, Index>& linkedList) const {

	return this->isEqual(linkedList);

}

/*
 * Function: Operator != (Inequality Operator)
 * Parameters: Reference to Immutable LinkedList<Type, Index>
 * Return: Boolean value denoting inequivalency of List
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type, typename Index>
bool structures::LinkedList<Type, Index>::operator != (const structures::LinkedList<Type, Index>& linkedList) const {

	return !(this->isEqual(linkedList));

}

/*
 * Function: Operator = (Assignment Operator)
 * Parameters: Reference to Immutable LinkedList<Type, Index>
 * Return: Reference to Mutable Linked List<Type>
 * Description: Assigns the current state to the given state, if 
 * the right hand side is not the same instance
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>& structures::LinkedList<Type, Index>::operator  = (const structures::LinkedList<Type, Index>& linkedList) {

	if(this != linkedList) this->setTo(linkedList);

	return *this;

}

/*
 * Function: Operator += (Compound Assignment)
 * Parameters: Reference to Immutable LinkedList<Type, Index>
 * Return: Reference to Mutable LinkedList<Type, Index>
 * Description: Adds the data from the current state, to that
 * of the given instance
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>& structures::LinkedList<Type, Index>::operator += (const structures::LinkedList<Type, Index>& linkedList) {

	this->append(linkedList);

	return *this;

}

/*
 * Function: Operator += (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable LinkedList<Type, Index>
 * Description: Append the data to the list
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>& structures::LinkedList<Type, Index>::operator += (const structures::Node<Type>& node) {

	this->append(node);

	return *this;

}

/*
 * Function: Operator += (Compound Assignment)
 * Parameters: Reference to Immutable <Type>
 * Return: Reference to Mutable LinkedList<Type, Index>
 * Description: Append the data to the list
 */
template<typename Type, typename Index>
structures::LinkedList<Type, Index>& structures::LinkedList<Type, Index>::operator += (const Type& data) {

	this->append(data);

	return *this;

}

/*
 * Function: Operator + (Addition Operator)
 * Parameters: Reference to Immutable LinkedList<Type, Index>
 * Return: Instance of Immutable LinkedList<Type, Index>
 * Description: Creates a new instance of LinkedList<Type, Index>
 * and sets the data as the addition of this state and the given
 * state
 */
template<typename Type, typename Index>
const structures::LinkedList<Type, Index> structures::LinkedList<Type, Index>::operator + (const structures::LinkedList<Type, Index>& linkedList) {

	structures::LinkedList<Type, Index> newList = *this;

	newList += linkedList;

	return newList;

}

/*
 * Function: Operator << (Stream insertion operator)
 * Parameters: output stream, reference to a LinkedList<Type, Index>
 * Return: the modified output stream
 * Description: inserts the linked list's data to the output stream, if the data of Type
 * is supported by the stream insertion operator
 */
template<typename Type, typename Index>
std::ostream& structures::operator<< (std::ostream& outputStream, const structures::LinkedList<Type, Index>& linkedList) {

	structures::SingleNode<Type>* current = static_cast<structures::SingleNode<Type>*>(linkedList.head);

	while(current) {

		outputStream << *current << " ";

		current = static_cast<structures::SingleNode<Type>*>(current->right);

	}

    return outputStream; 

}

#endif
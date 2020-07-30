
#ifndef STRUCTURES_LINKED_LIST_HPP
#define STRUCTURES_LINKED_LIST_HPP

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



#endif
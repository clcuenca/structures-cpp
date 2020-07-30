#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

/// --------------------------------
/// DoubleNode<Type>
/// Type - Type of data to be stored
/// Double Node, contains one
/// reference to a sibling Node
template <typename Type>
class structures::DoubleNode: public structures::SingleNode<Type>{

public:

	// ------------
	// Constructors

	DoubleNode();
	DoubleNode(const Type&);
	DoubleNode(const structures::SingleNode<Type>&);
	~DoubleNode();

	/// -------
	/// Members

	structures::Node<Type>* left;

};

/// --------------------------
/// Constructor Implementation

/* 
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the Node and values
 */
template<typename Type>
structures::DoubleNode<Type>::DoubleNode():structures::SingleNode<Type>(), left(0){}

/*
 * Function: Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Initializes the Node and values; sets the value of the Type
 * from the given argument
 */
template<typename Type>
structures::DoubleNode<Type>::DoubleNode(const Type& type):structures::SingleNode<Type>(type), left(0){}

/* 
 * Function: Copy Constructor
 * Parameters: n/a
 * Return: n/a
 * Description: Sets the Node to the value 
 * of the given node
 */
template<typename Type>
structures::DoubleNode<Type>::DoubleNode(const structures::SingleNode<Type>& node):
structures::SingleNode<Type>(node), left(0){}

/*
 * Function: Destructor
 * Parameters: n/a
 * Return: n/a
 * Description: Releases the node and values
 */
template<typename Type>
structures::DoubleNode<Type>::~DoubleNode(){}

#endif
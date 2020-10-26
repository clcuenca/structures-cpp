/// Node 
/// Class Representing a Node of type Type with overloaded 
/// operators that can be used if Type has those operators supported
/// Author: Carlos L. Cuenca
/// Date 10/25/2020

#ifndef STRUCTURES_NODE_HPP
#define STRUCTURES_NODE_HPP

#include <iostream>
#include "structures.hpp"

template<typename Type>
class structures::Node {

protected:

	Type data;

public:

	/// ------------
	/// Constructors

	Node();
	Node(const Type&);
	Node(const Node&);
	~Node();

	/// ---------
	/// Accessors

	const Type& getData() const;

	/// --------
	/// Mutators

	void setData(const Type&);

    /// --------------------
	/// Overloaded Operators

	bool operator == (const Node<Type>&)const;
	bool operator != (const Node<Type>&)const;
	bool operator  < (const Node<Type>&)const;
	bool operator  > (const Node<Type>&)const;
	bool operator <= (const Node<Type>&)const;
	bool operator >= (const Node<Type>&)const;

	Node<Type>& operator  = (const Node<Type>&);
	Node<Type>& operator += (const Node<Type>&);
	Node<Type>& operator -= (const Node<Type>&);
	Node<Type>& operator *= (const Node<Type>&);
	Node<Type>& operator /= (const Node<Type>&);
	Node<Type>& operator %= (const Node<Type>&);

	const Node<Type> operator + (const Node<Type>&);
	const Node<Type> operator - (const Node<Type>&);
	const Node<Type> operator * (const Node<Type>&);
	const Node<Type> operator / (const Node<Type>&);
	const Node<Type> operator % (const Node<Type>&);

	bool operator == (const Type&)const;
	bool operator != (const Type&)const;
	bool operator  < (const Type&)const;
	bool operator  > (const Type&)const;
	bool operator <= (const Type&)const;
	bool operator >= (const Type&)const;

	Node<Type>& operator  = (const Type&);
	Node<Type>& operator += (const Type&);
	Node<Type>& operator -= (const Type&);
	Node<Type>& operator *= (const Type&);
	Node<Type>& operator /= (const Type&);
	Node<Type>& operator %= (const Type&);

	const Node<Type> operator + (const Type&);
	const Node<Type> operator - (const Type&);
	const Node<Type> operator * (const Type&);
	const Node<Type> operator / (const Type&);
	const Node<Type> operator % (const Type&);

	friend std::ostream& operator<< <Type>(std::ostream&, const Node<Type>&);
	friend std::istream& operator>> <Type>(std::istream&, Node<Type>&);

};

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

	this->data.~Type();

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

/// -----------------------------------------------------------
/// Overloaded Operators - Implementation

/*
 * Function: Operator == (Equality Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator==(const structures::Node<Type>& right) const{

	return this->data == right.data;

}

/*
 * Function: Operator == (Equality Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator==(const Type& right) const{

	return this->data == right;

}

/*
 * Function: Operator != (Inequality Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting inequivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator!=(const structures::Node<Type>& right) const{

	return !(this->data == right.data);

}

/*
 * Function: Operator != (Inequality Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting inequivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator!=(const Type& right) const{

	return !(this->data == right);

}

/*
 * Function: Operator < (Less than Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator<(const structures::Node<Type>& right) const{

	return this->data < right.data;

}

/*
 * Function: Operator < (Less than Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator<(const Type& right) const{

	return this->data < right;

}

/*
 * Function: Operator > (Greater than Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator>(const structures::Node<Type>& right) const{

	return this->data > right.data;

}

/*
 * Function: Operator > (Greater than Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator>(const Type& right) const{

	return this->data > right;

}

/*
 * Function: Operator <=(Less than equivalency Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator<=(const structures::Node<Type>& right) const{

	return (this->data < right.data) && (this->data == right.data);

}

/*
 * Function: Operator <=(Less than equivalency Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator<=(const Type& right) const{

	return (this->data < right) && (this->data == right);

}

/* 
 * Function: Operator >=(Greater than equivalency Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator>=(const structures::Node<Type>& right) const{

	return (this->data > right.data) && (this->data == right.data);

}

/*
 * Function: Operator >=(Greater than equivalency Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Boolean value denoting equivalency of Type
 * Description: Returns the result of the equality of the given
 * type
 */
template<typename Type>
bool structures::Node<Type>::operator>=(const Type& right) const{

	return (this->data > right) && (this->data == right);

}

/*
 * Function: Operator = (Assignment Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Assigns the current state to the given state, if 
 * the right hand side is not the same instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator=(const structures::Node<Type>& right){

	// Assign the state as long as the Type has a viable operator
	if(this != right) this->data = right.data;

	return *this;

}

/*
 * Function: Operator = (Assignment Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Assigns the current state to the given state, if 
 * the right hand side is not the same instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator=(const Type& right){

	// Assign the state as long as the Type has a viable operator
	this->data = right;

	return *this;

}

/*
 * Function: Operator += (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Adds the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator+=(const structures::Node<Type>& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data += right.data;

	return *this;

}

/*
 * Function: Operator += (Compound Assignment)
 * Parameters: Reference to Type
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Adds the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator+=(const Type& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data += right;

	return *this;

}

/*
 * Function: Operator -= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Subtracts the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator-=(const structures::Node<Type>& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data -= right.data;

	return *this;

}

/* 
 * Function: Operator -= (Compound Assignment)
 * Parameters: Reference to Type
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Subtracts the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator-=(const Type& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data -= right;

	return *this;

}

/*
 * Function: Operator *= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Multiplies the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator*=(const structures::Node<Type>& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data *= right.data;

	return *this;

}

/*
 * Function: Operator *= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Type
 * Description: Multiplies the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator*=(const Type& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data *= right;

	return *this;

}

/* 
 * Function: Operator /= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Divides the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator/=(const structures::Node<Type>& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data /= right.data;

	return *this;

}

/*
 * Function: Operator /= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Divides the data from the current state, to that
 * of the given instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator/=(const Type& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data /= right;

	return *this;

}

/*
 * Function: Operator /= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Divides the data from the current state, and sets
 * the result to the remainder of that instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator%=(const structures::Node<Type>& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data %= right.data;

	return *this;

}

/*
 * Function: Operator /= (Compound Assignment)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Reference to Mutable Abstract Node<Type>
 * Description: Divides the data from the current state, and sets
 * the result to the remainder of that instance
 */
template<typename Type>
structures::Node<Type>&
structures::Node<Type>::operator%=(const Type& right){

	// Since we don't care about the right hand side,
	// We modify the current state
	this->data %= right;

	return *this;

}

/*
 * Function: Operator + (Additon Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the addition of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator+(const structures::Node<Type>& right){

	structures::Node<Type> listNode = *this;

	listNode += right;

	return listNode;

}

/*
 * Function: Operator + (Additon Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the addition of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator+(const Type& right){

	structures::Node<Type> listNode = *this;

	listNode += right;

	return listNode;

}

/*
 * Function: Operator - (Subtraction Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the subtraction of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator-(const structures::Node<Type>& right){

	structures::Node<Type> listNode = *this;

	listNode -= right;

	return listNode;
	
}

/*
 * Function: Operator - (Subtraction Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the subtraction of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator-(const Type& right){

	structures::Node<Type> listNode = *this;

	listNode -= right;

	return listNode;
	
}

/*
 * Function: Operator * (Multiplication Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the multiplicaton of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator*(const structures::Node<Type>& right){

	structures::Node<Type> listNode = *this;

	listNode *= right;

	return listNode;
	
}

/*
 * Function: Operator * (Multiplication Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the multiplicaton of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator*(const Type& right){

	structures::Node<Type> listNode = *this;

	listNode *= right;

	return listNode;
	
}

/*
 * Function: Operator / (Division Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the division of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator/(const structures::Node<Type>& right){

	structures::Node<Type> listNode = *this;

	listNode /= right;

	return listNode;
	
}

/*
 * Function: Operator / (Division Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the division of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator/(const Type& right){

	structures::Node<Type> listNode = *this;

	listNode /= right;

	return listNode;
	
}

/* 
 * Function: Operator % (Modulous Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the addition of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator%(const structures::Node<Type>& right){

	structures::Node<Type> listNode = *this;

	listNode %= right;

	return listNode;
	
}

/*
 * Function: Operator % (Modulous Operator)
 * Parameters: Reference to Immutable Abstract Node<Type>
 * Return: Instance of Immutable Abstract Node<Type>
 * Description: Creates a new instance of Abstract Node<Type>
 * and sets the data as the addition of this state and the given
 * state
 */
template<typename Type>
const structures::Node<Type>
structures::Node<Type>::operator%(const Type& right){

	structures::Node<Type> listNode = *this;

	listNode %= right;

	return listNode;
	
}

/*
 * Function: Operator << (Stream insertion operator)
 * Parameters: output stream, reference to a Node<Type>
 * Return: the modified output stream
 * Description: inserts the node's data to the output stream, if the data of Type
 * is supported by the stream insertion operator
 */
template<typename Type>
std::ostream& structures::operator<< (std::ostream& outputStream, const structures::Node<Type>& node) {

    outputStream << node.data;

    return outputStream; 

}

/*
 * Function: Operator >> (Stream extraction operator)
 * Parameters: input stream, reference to a Node<Type>
 * Return: the modified input stream
 * Description: extracts the data from the output stream to the node, if the data of Type
 * is supported by the stream extraction operator
 */
template<typename Type>
std::istream& structures::operator>> (std::istream& inputStream,  structures::Node<Type>& node) {

	inputStream >> node.data;

    return inputStream; 

}

#endif
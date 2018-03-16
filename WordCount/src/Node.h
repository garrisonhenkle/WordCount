/*
 * Node.h
 *
 *  Created on: Jan 8, 2018
 *      Author: Hani Z. Girgis
 *      Purpose: A tree node, which holds an element and two
 *      sub-trees.
 */

#ifndef NODE_H_
#define NODE_H_

template<typename T>
class Node {
private:
	T elm;
	// Left subtree
	Node<T> * lt;
	// Right subtree
	Node<T> * rt;

public:
	Node(T);
	Node(T, Node<T> *, Node<T> *);
	virtual ~Node();

	T getElm();
	Node<T> * getLt();
	Node<T> * getRt();

	void setElm(T);
	void setLt(Node<T> *);
	void setRt(Node<T> *);
	// Return the number of children
	int getChildrenCount();

};

#include "Node.cpp"

#endif /* NODE_H_ */

/*
 * Tree.h
 *
 *  Created on: Jan 10, 2018
 *      Author: Hani Z Girgis
 *      Purpose: This is a BST. It should have the following
 *      	operations: (i) insert, (ii) find, (iii) remove, (iv) inOrder
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class Tree {
private:
	Node<T> * root;
	void insert(T, Node<T> *);

	// This is a helper method to the public inOrder
	void inOrder(Node<T> *);

	// This method find the minimum element and returns it
	T min(Node<T> *);

	// Helper to the public remove
	// T is the key, and the parent
	void remove(T, Node<T> *);

	// Free memory used by the nodes of the tree
	void cleanUp(Node<T> *);

public:
	Tree(T);
	virtual ~Tree();
	// Insert an item in the binary search tree
	void insert(T);

	// Print the contents of the tree in order
	// left subtree, element, right subtree
	void inOrder();
	/**
	 * Reference: http://www.algolist.net/Data_structures/Binary_search_tree/Removal
	 * Three cases:
	 * 1. If the node has no children:
	 * 		a. Set the appropriate child to nullptr in the parent and
	 * 		b. Delete the node
	 * 2. If the node to be deleted has one child:
	 * 		a. Connect this child to the parent directly
	 * 		b. Delete the node
	 * 3. If the node has two children:
	 * 		a. Find the minimum value in the right subtree
	 * 		b. Set the element in the node to the minimum
	 * 		c. Remove the node containing the minimum
	 */
	void remove(T);

	// Find the element and return the node that has it and its parent
	// Called on the root only
	pair<Node<T> *, Node<T> *> find(T elm);

	// Find the elelment and return the node that has it and its parent
	pair<Node<T> *, Node<T> *> find(T elm, Node<T> * parent);

	T min();
};

#include "Tree.cpp"

#endif /* TREE_H_ */

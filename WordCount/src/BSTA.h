/*
 * BSTA.h
 *
 * Basic AVL tree
 *
 * Contains methods that allow for the use of an AVL datastructure, such as insert, delete, and find
 *
 * Also contains methods to maintain the structure properties of an AVL tree
 *
 *  Created on: Mar 16, 2018
 *      Author: garrison
 */

#ifndef BSTA_H_
#define BSTA_H_

using namespace std;

#include <string>
#include <vector>
#include "NodeA.h"

class BSTA {
public:
	BSTA();
	virtual ~BSTA();

	/**
	 * Inserts the input string into the AVL tree
	 */
	void insert(string);
	/**
	 * Searches a specified subtree to insert the input string
	 */
	NodeA * insert(string, NodeA*);
	/**
	 * Removes the input string from the AVL tree
	 */
	void remove(string);
	/**
	 * Searches a specified subtree to remove the input string
	 */
	NodeA * remove(string, NodeA*);

	/**
	 * Finds the node containing the input string
	 */
	NodeA * find(string);
	/**
	 * Searches the specified subtree for the node containing the input string
	 */
	NodeA * find(string, NodeA*);

	/**
	 * Gets the current height of a specified node
	 */
	int getHeight(NodeA*);
	/**
	 * Finds the inorder successor of the specified node
	 *
	 * This node will be the minimum of the right subtree of the input node
	 */
	NodeA * findInorderSuccessor(NodeA *);

	/**
	 * Single rotation to the right that rotates up the input node
	 */
	NodeA * zigRight(NodeA* &n);
	/**
	 * Single rotation to the left that rotates up the input node
	 */
	NodeA * zigLeft(NodeA* &n);
	/**
	 * Double rotation to the left that rotates up the input node
	 */
	NodeA * zigzigRight(NodeA* &n);
	/**
	 * Double rotation to the right that rotates up the input node
	 */
	NodeA * zigzigLeft(NodeA* &n);

	/**
	 * Returns the list holding all the values in the BSTA
	 */
	string getList(int);
	/**
	 * Gets the amount of items in the BSTA
	 */
	int getListSize();

	/**
	 * Contains the size of the BSTA
	 */
	int size;

	//List containing every string element in the BSTA for convenience
	vector<string> * list;
private:
	//Root node of the tree
	NodeA * root;
};

#endif /* BSTA_H_ */

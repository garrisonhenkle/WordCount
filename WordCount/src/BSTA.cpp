/*
 * BSTA.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: garrison
 */

#include "BSTA.h"

BSTA::BSTA() {
	root = nullptr;
	size = 0;
	list = new vector<string>;
}

BSTA::~BSTA() {
	delete root;
	list->clear();
	delete list;
}

NodeA * BSTA::findInorderSuccessor(NodeA * n) {

	NodeA * out;

	if (n == nullptr) {
		return nullptr;
	} else if (n->leftChild == nullptr) {
		out = n;
	} else {
		out = findInorderSuccessor(n->leftChild);
	}

	return out;
}

int BSTA::getHeight(NodeA * n) {
	return n->height;
}

void BSTA::insert(string elm) {
	root = insert(elm, root);
	list->push_back(elm);
	size++;
}

NodeA * BSTA::find(string elm) {
	NodeA * out;

	//if the root is it, return the root, otherwise if it is smaller go left, if it is larger go right
	if (root->element == elm) {
		out = root->element;
	} else if (elm.compare(root->element) < 0) {
		out = find(elm, root->leftChild);
	} else {
		out = find(elm, root->rightChild);
	}

	return out;
}

NodeA * BSTA::find(string elm, NodeA * n) {
	NodeA * out;

	if(n->element == elm){
		out = n;
	} else if(elm.compare(n->element) < 0){
		out = find(elm, n->leftChild);
	}else{
		out = find(elm, n->rightChild);
	}

	return out;
}

NodeA * BSTA::insert(string elm, NodeA * n) {
	//if the position is found, create a node for the input data and place it
	if (n == nullptr) {
		n = new NodeA();
		n->element = elm;
		n->height = 0; //initialize height, will be rewritten below
		n->leftChild = nullptr;
		n->rightChild = nullptr;
		n->parent = nullptr;
		//if the input is less than n's element, search on left
	} else if (elm.compare(n->element) < 0) {
		//recursively call insert until it is inserted
		n->leftChild = insert(elm, n->leftChild);
		//if the height difference is greater than 2, rotate
		//maintain structure condition
		if (getHeight(n->leftChild) - getHeight(n->rightChild) == 2) {
			//if the data being inserted is less than the data of the left child,
			//perform a single rotation, otherwise perform a double rotation
			if (elm.compare(n->leftChild->element) < 0) {
				n = zigRight(n);
			} else {
				n = zigzigRight(n);
			}
		}
		//if the input is greater than n's element, search on right
	} else if (elm.compare(n->element) > 0) {
		//recursively call insert until it is inserted
		n->rightChild = insert(elm, n->rightChild);
		//if the height different is greater than 2, rotate
		//maintain structure condition
		if (getHeight(n->rightChild) - getHeight(n->leftChild) == 2) {
			//if the data being inserted is greater than the data of the right child,
			//perform a single rotation, otherwise perform a double rotation
			if (elm.compare(n->rightChild->element) > 0) {
				n = zigLeft(n);
			} else {
				n = zigzigLeft(n);
			}
		}
	}

	//set the height of the inserted node
	//(height of the highest child + 1 for the parent n)
	n->height = max(getHeight(n->leftChild), getHeight(n->rightChild)) + 1;

	//since n has been set by a zig or zigzig function, it already has its correct location
	//so it can just be returned
	return n;
}

void BSTA::remove(string elm) {
	root = remove(elm, root);
	size--;
}

NodeA * BSTA::remove(string elm, NodeA * n) {
	NodeA * forDeletion;

	//if the input is null, return null
	//otherwise if the input is < node n's data, search the left tree
	//otherwise if the input is > node n's data, search the right tree
	if (n == nullptr) {
		return nullptr;
	} else if (elm.compare(n->element) < 0) {
		n->leftChild = remove(elm, n->leftChild);
	} else if (elm.compare(n->element) > 0) {
		n->rightChild = remove(elm, n->rightChild);
	}

	//element is found

	//if the node has 2 children, find the inorder successor
	//and replace n with it, then delete n
	else if (n->leftChild && n->rightChild) {
		forDeletion = findInorderSuccessor(n->rightChild);
		n->element = forDeletion->element;
		n->rightChild = remove(n->element, n->rightChild);
	}
	//if the node has 1 or 0 children, move up the child if it exists and delete the node
	else {
		forDeletion = n;

		//if the child exists, replace the node with the child
		if (n->leftChild == nullptr) {
			n = n->rightChild;
		} else if (n->rightChild == nullptr) {
			n = n->leftChild;
		}
		delete forDeletion;
	}

	//if the node has been deleted, exit and return nullptr
	if (n == nullptr) {
		return n;
	}

	//reset the height
	n->height = max(getHeight(n->leftChild), getHeight(n->rightChild)) + 1;

	//Check to see if the node is imbalanced

	// If the left child was deleted
	if (getHeight(n->leftChild) - getHeight(n->rightChild) == 2) {
		//check to see if the right or left subtrees needs to be rotated
		if (getHeight(n->leftChild->leftChild) - getHeight(n->leftChild->rightChild) == 1) {
			return zigLeft(n);
		} else {
			return zigzigLeft(n);
		}
	}

	// If the right child was deleted
	else if (getHeight(n->rightChild) - getHeight(n->leftChild) == 2) {
		//check to see if the right or left subtrees needs to be rotated
		if (getHeight(n->rightChild->rightChild) - getHeight(n->rightChild->leftChild) == 1) {
			return zigRight(n);
		} else {
			return zigzigRight(n);
		}
	}

	//return the correctly balanced node
	return n;
}

NodeA * BSTA::zigRight(NodeA * &n) {
	//rotate nodes
	NodeA * out = n->leftChild;
	n->leftChild = out->rightChild;
	out->rightChild = n;

	//reset the heights
	n->height = max(n->leftChild->height, n->rightChild->height) + 1;
	out->height = max(out->leftChild->height, n->height) + 1;

	//return the node with correct positioning
	return out;
}

NodeA * BSTA::zigLeft(NodeA * &n) {
	//rotate nodes
	NodeA * out = n->rightChild;
	n->rightChild = out->leftChild;
	out->leftChild = n;

	//reset the heights
	n->height = max(n->rightChild->height, n->leftChild->height) + 1;
	out->height = max(out->rightChild->height, n->height) + 1;
	//**********MAYBE WRONG, MIGHT BE n AND NOT OUT********************
	//**********MAYBE WRONG, MIGHT BE n AND NOT OUT********************
	//**********MAYBE WRONG, MIGHT BE n AND NOT OUT********************

	//return the node with correct positioning
	return out;
}

NodeA * BSTA::zigzigRight(NodeA * &n) {
	n->leftChild = zigLeft(n->leftChild);
	return zigRight(n);
}

NodeA * BSTA::zigzigLeft(NodeA * &n) {
	n->rightChild = zigRight(n->rightChild);
	return zigLeft(n);
}


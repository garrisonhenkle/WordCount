/*
 * BSTA.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: garrison
 */

#include "BSTA.h"

BSTA::BSTA() {
	// TODO Auto-generated constructor stub

}

BSTA::~BSTA() {
	// TODO Auto-generated destructor stub
}

NodeA * BSTA::insert(string elm, NodeA * n) {
	//if there is no root, create one
	if (n == nullptr) {
		n = new NodeA();
		n->element = elm;
		n->leftChild = nullptr;
		n->rightChild = nullptr;
		n->parent = nullptr;
		//if the input is less than n, place on the left
	} else if (elm.compare(n->element) < 0) {
		n->leftChild = insert(elm, n->leftChild);
		//if the height difference is greater than 2
		if (getHeight(n->leftChild) - getHeight(n->rightChild) == 2) {
			if(elm.compare(n->leftChild->element) < 0){
				n = zigRight(n);
			}else{
				n = zigzigRight(n);
			}
	}
}
}

int getHeight(NodeA * n) {
return n->height;
}

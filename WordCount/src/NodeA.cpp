/*
 * NodeA.cpp
 *
 *  Created on: Mar 16, 2018
 *      Author: garrison
 */

#include "NodeA.h"

NodeA::NodeA() {
	height = 0;
	leftChild = nullptr;;
	rightChild =nullptr;
	root = nullptr;;
	parent = nullptr;

}

NodeA::~NodeA() {
	delete root;
}




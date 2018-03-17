/*
 * NodeA.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#include "NodeA.h"

NodeA::NodeA() {
	height = 0;
	leftChild = nullptr;
	rightChild = nullptr;
	parent = nullptr;
	monoCount = 0;
	biCount = 0;
	prob = 0;

}

NodeA::~NodeA() {
	delete leftChild;
	delete rightChild;
	delete parent;
}


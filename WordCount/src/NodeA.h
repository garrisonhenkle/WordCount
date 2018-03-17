/*
 * NodeA.h
 *
 * Node for the AVL tree BSTA
 *
 * Contains the data stored in each node of a BSTA tree, such as the count of mono- and bigrams, probabilites, height, and th
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#ifndef NODEA_H_
#define NODEA_H_

using namespace std;

#include <string>

class NodeA {
public:
	NodeA();
	virtual ~NodeA();

	string element;

	NodeA * leftChild;
	NodeA * rightChild;
	NodeA * parent;

	int height;
	int monoCount;
	int biCount;
	double prob;
private:

};
#endif /* NODEA_H_ */

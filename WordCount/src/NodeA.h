/*
 * NodeA.h
 *
 *  Created on: Mar 16, 2018
 *      Author: garrison
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

	NodeA * root;
	int monoCount;
	int biCount;
	double prob;
private:

};
#endif /* NODEA_H_ */

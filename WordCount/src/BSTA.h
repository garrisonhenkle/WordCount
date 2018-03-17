/*
 * BSTA.h
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

	void insert(string);
	NodeA * insert(string, NodeA*);
	void remove(string);
	NodeA * remove(string, NodeA*);

	NodeA * find(string);
	NodeA * find(string, NodeA*);

	int getHeight(NodeA*);
	NodeA * findInorderSuccessor(NodeA *);

	NodeA * zigRight(NodeA* &n);
	NodeA * zigLeft(NodeA* &n);
	NodeA * zigzigRight(NodeA* &n);
	NodeA * zigzigLeft(NodeA* &n);

	int size;
private:
	NodeA * root;
	vector<string> * list;

};

#endif /* BSTA_H_ */

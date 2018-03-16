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
#include "NodeA.h"

class BSTA {
public:
	BSTA();
	virtual ~BSTA();
	NodeA * insert(string, NodeA*);
	int getHeight(NodeA*);

	NodeA *

};

#endif /* BSTA_H_ */

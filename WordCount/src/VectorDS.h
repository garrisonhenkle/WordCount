/*
 * VectorDS.h
 *
 *  Created on: Mar 14, 2018
 *      Author: garrison
 */

#ifndef VECTORDS_H_
#define VECTORDS_H_

using namespace std;

#include "DataStructure.h";

class VectorDS: public DataStructure {
public:
	VectorDS();
	virtual ~VectorDS();
	void addWord(string);

private:
	vector<pair<string, int>> mono;
	vector<pair<string, int>> bi;
	vector<pair<string, int>> prob;
};

#endif /* VECTORDS_H_ */

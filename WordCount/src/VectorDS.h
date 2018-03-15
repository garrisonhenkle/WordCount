/*
 * VectorDS.h
 *
 *  Created on: Mar 10, 2018
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
	void addTwoWords(string, string);
	void addCondProb(string, string, double);
	int getWord(string);
	int getTwoWords(string, string);
	double getCondProb(string, string);
	pair<string, string> split(string);

private:
	vector<pair<string, int>> mono;
	vector<pair<string, int>> bi;
	vector<pair<string, double>> prob;
};

#endif /* VECTORDS_H_ */

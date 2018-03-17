/*
 * AvlDS.h
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#ifndef AVLDS_H_
#define AVLDS_H_

using namespace std;

#include "DataStructure.h"
#include "BSTA.h";

class AvlDS : public DataStructure{
public:
	AvlDS();
	virtual ~AvlDS();

	void addWord(string);
	void addTwoWords(string, string);
	void printGrams();
	int getWord(string);
	int getTwoWords(string, string);
	pair<string, string> split(string);
	void calcCondProb();
	int& operator[](string);
	int& operator()(string, string);
	double& operator()(string, string, int);
	void incrementFileSize(long);
	long getFileSize();
	string toLowerCase(string);
private:
	BSTA * mono;
	BSTA * bi;
	BSTA * prob;
};

#endif /* AVLDS_H_ */

/*
 * AvlDS.h
 *
 *Contains the AVL structure built off of the DataStructure interface
 *
 *Allows for the storage and printing of monograms, bigrams, and probabilities in an AVL tree
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#ifndef AVLDS_H_
#define AVLDS_H_

using namespace std;

#include "DataStructure.h"
#include "BSTA.h"
#include <vector>

class AvlDS: public DataStructure {
public:

	//see DataStructure.h for descriptions
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
	//holds monograms
	BSTA * mono;
	//holds bigrams
	BSTA * bi;
	//holds probabilities
	BSTA * prob;
};

#endif /* AVLDS_H_ */

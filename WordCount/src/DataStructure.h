/*
 * DataStructure.h
 *
 *  Created on: Mar 14, 2018
 *      Author: Garrison Henke
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

using namespace std;

#include <string>;
#include <vector>;

class DataStructure {
public:
	DataStructure();
	virtual ~DataStructure();
	virtual void addWord(string) = 0;
	virtual void addTwoWords(string, string) = 0;
	virtual void printGrams() = 0;
	virtual void addCondProb(string, string, int) = 0;
	virtual int getWord(string) = 0;
	virtual int getTwoWords(string, string) = 0;
	virtual pair<string, string> split(string) = 0;
};

#endif /* DATASTRUCTURE_H_ */

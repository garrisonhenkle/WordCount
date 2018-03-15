/*
 * DataStructure.h
 *
 *  Created on: Mar 14, 2018
 *      Author: garrison
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

using namespace std;

#include <string>;

class DataStructure {
public:
	DataStructure();
	virtual ~DataStructure();
	virtual void addWord(string) = 0;
	virtual void addTwoWords(string, string) = 0;
	virtual void printGrams() = 0;
	virtual int getWord(string) = 0;
	virtual int getTwoWords(string, string) = 0;
	virtual int& operator[](string) override = 0;
	virtual int& operator()(string) override = 0;
};

#endif /* DATASTRUCTURE_H_ */

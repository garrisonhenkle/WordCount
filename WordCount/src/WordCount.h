/*
 * WordCount.h
 *
 * Main file for the program that contains the main() function
 *
 * Contains methods to process lines of text, such as reading and storage
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#ifndef WORDCOUNT_H_
#define WORDCOUNT_H_

using namespace std;

#include "VectorDS.h"
#include "AvlDS.h"
#include "HashDS.h"

class WordCount {
public:
	/**
	 * Processes the vectorDS datastructure by calculating the probabilties of each bigram and outputs the results to the files text.uni and text.bi
	 */
	void processDS(string, DataStructure *);

	/**
	 * Converts a line into a vector of words (strings)
	 */
	vector<string> processLine(string);
};

#endif /* WORDCOUNT_H_ */

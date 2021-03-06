/*
 * DataStructure.h
 *
 * Interface for datastructures
 *
 * Allows for the storage and printing of monograms, bigrams,
 *  and probabilities from a set of input data
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henke
 */

#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

using namespace std;

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>

class DataStructure {
public:
	/**
	 * Increments the count of a monogram input in the datastructure
	 *
	 * Tries to find the monogram in the datastructure.  If the word is present, the monogram's count is incremented.
	 * If the monogram is not present, the monogram is added to the datastructure with count = 1.
	 */
	virtual void addWord(string) = 0;

	/**
	 * Increments the count of a bigram input in the datastructure
	 *
	 * Tries to find the bigram in the datastrucutre.  If the word is present, the bigram's count is incremented.
	 * If the bigram is not present, the bigram is added to the datastructure with count = 1.
	 */
	virtual void addTwoWords(string, string) = 0;

	/**
	 * Prints the contents of the datastructure to files text.uni and text.bi
	 */
	virtual void printGrams() = 0;

	/**
	 * Adds input probability to the bigram
	 */
	//virtual void addCondProb(string, string, double) = 0;
	/**
	 * Returns the integer value for the count of the input monogram
	 *
	 * Returns -1 if the monogram is not found
	 */
	virtual int getWord(string) = 0;

	/**
	 * Returns the integer value for the count of the input bigram
	 *
	 * Returns -1 if the bigram is not found
	 */
	virtual int getTwoWords(string, string) = 0;

	/**
	 * Returns the double value for the probability of the bigram
	 */
	//virtual double getCondProb(string, string) = 0;
	/**
	 * Splits two words separated by a space
	 *
	 * Returns a pair containing the two separated words
	 *
	 * For example, the input "hello world" would give an output pair with first = "hello" and second = "world"
	 */
	virtual pair<string, string> split(string) = 0;

	/**
	 * Calculates the probabilities for all bigrams
	 */
	virtual void calcCondProb();

	/**
	 * Returns the reference to the count variable for the monograms
	 */
	virtual int& operator[](string) = 0;

	/**
	 * Returns the reference to the count variable for the bigrams
	 */
	virtual int& operator()(string, string) = 0;

	/**
	 * Returns the reference to the probability variable for the bigrams
	 *
	 * The integer is just for distinction, so it be any integer
	 */
	virtual double& operator()(string, string, int) = 0;

	/**
	 *Increments the file size by the input long
	 */
	virtual void incrementFileSize(long) = 0;

	/**
	 * Returns the current fileSize variable
	 */
	virtual long getFileSize() = 0;
};

#endif /* DATASTRUCTURE_H_ */

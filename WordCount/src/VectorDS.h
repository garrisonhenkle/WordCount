/*
 * VectorDS.h
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison henkle
 */

#ifndef VECTORDS_H_
#define VECTORDS_H_

//using namespace std; already in Datastructure.h

#include "DataStructure.h";

class VectorDS: public DataStructure {
public:
	/**
	 * Default constructor
	 *
	 * Initializes the vectors mono, bi, and prob
	 */
	VectorDS();

	/**
	 * Default deconstructor
	 *
	 * Clears and deletes the vectors
	 */
	virtual ~VectorDS();

	/**
	 * Increments the count of a monogram or adds a monogram to the vector if it is not found
	 */
	void addWord(string);

	/**
	 * Increments the count of a bigram or adds a bigram to the vector if it is not found
	 */
	void addTwoWords(string, string);

	/**
	 * Assigns the input probability to the bigram
	 */
	void addCondProb(string, string, double);

	/**
	 * Returns the count of the monogram
	 *
	 * Returns -1 if the monogram is not found
	 */
	int getWord(string);

	/**
	 * Returns the count of the bigram
	 *
	 * Returns -1 if the bigram is not found
	 */
	int getTwoWords(string, string);

	/**
	 * Returns the probability of the bigram
	 *
	 * Returns -1 if the bigram is not found
	 */
	double getCondProb(string, string);

	/**
	 * Prints the contents of the datastructure to the files text.uni and text.bi
	 */
	void printGrams();

	/**
	 *Calculates the probability of a bigram
	 */
	double calcProb(string, string);

	/**
	 * Calculates the probability for all bigrams and automatically populates the prob vector
	 */
	void calcCondProb();

	/**
	 * Splits a string containing two words separated by a space into two distinct strings
	 */
	pair<string, string> split(string);

	/**
	 *Returns the input string in lower case
	 */
	string toLowerCase(string);

	/**
	 * operator that returns the probability of an input bigram
	 */
	double& operator[](string, string) override;

	/**
	 * operator that returns the count of an input monogram
	 */
	int& operator()(string) override;

	/**
	 * operator that returns the count of an input bigram
	 */
	int& operator()(string, string) override;

private:
	//contains the monograms
	vector<pair<string, int>> mono;
	//contains the bigrams
	vector<pair<string, int>> bi;
	//contains the probabilities
	vector<pair<string, double>> prob;
};

#endif /* VECTORDS_H_ */

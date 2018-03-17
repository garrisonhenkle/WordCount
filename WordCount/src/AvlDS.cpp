/*
 * AvlDS.cpp

 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

//see header for description

#include "AvlDS.h"

AvlDS::AvlDS() {
	mono = new BSTA();
	bi = new BSTA();
	prob = new BSTA();

}

AvlDS::~AvlDS() {
	delete mono;
	delete bi;
	delete prob;
}


string AvlDS::toLowerCase(string word) {
	string out = word;

//calls the toLower() function on each character and returns the string
	for (int i = 0; i < out.length(); i++) {
		out[i] = tolower(out[i]);
	}

	return out;
} //end toLowerCase

void AvlDS::addWord(string wordOne) {

	string word = toLowerCase(wordOne);

	mono->insert(word);
	mono->find(word)->monoCount++;
}

void AvlDS::addTwoWords(string wordOne, string wordTwo) {

	string word = toLowerCase((wordOne + ' ' + wordTwo));

	bi->insert(word);
	prob->insert(word);
	bi->find(word)->biCount++;
}

void AvlDS::printGrams() {
//not used because it is already in vector
}

int AvlDS::getWord(string wordOne) {
	int out;

	string word = toLowerCase(wordOne);

	out = mono->find(word)->monoCount;

	return out;
}

int AvlDS::getTwoWords(string wordOne, string wordTwo) {
	int out;

	string word = toLowerCase((wordOne + ' ' + wordTwo));

	out = bi->find(word)->biCount;

	return out;
}

pair<string, string> AvlDS::split(string words) {

	//holds output
	pair<string, string> out;

	//temporary holding variables
	int firstWord = 0;
	int secondWord;
	//iterates until the space character is found, then the string is split into the two words with substr
	for (int i = 0; i < words.length(); i++) {
		if (!words[i] == ' ') {
			firstWord++;
		} else if (words[i] == ' ') {
			//first word is the characters up to the space
			out.first = words.substr(0, firstWord);
			//second word is the total characters - (the first word's characters + 1 for the space)
			secondWord = words.length() - (firstWord + 1);
			out.second = words.substr(i + 1, secondWord);
			break;
		}
	}

	return out;
} //end split(string, string)

void AvlDS::calcCondProb() {

	double prob1;
	int size;

	string tempString;
	string tempMono;

	NodeA * temp;
	NodeA * temp2;
	pair<string, string> tempSplit;

	int bigramCount;
	int monogramCount;

	size = bi->list->size();

	//for every word in bi, calculate the probability
	for (int i = 0; i < size; i++) {
		//get bigram count
		tempString = bi->getList(i);
		temp = bi->find(tempString);
		bigramCount = temp->biCount;
		//get monogram count
		tempSplit = split(tempString);
		tempMono = tempSplit.first;
		temp2 = mono->find(tempMono);
		monogramCount = temp2->monoCount;

		//calculate prob
		prob1 = bigramCount / monogramCount;
		//store prob
		prob->find(tempString)->prob = prob1;
	}
	//clean up
	delete temp;
	delete temp2;
}

int& AvlDS::operator[](string wordOne) {

	string word = toLowerCase(wordOne);

	return mono->find(word)->monoCount;
}

int& AvlDS::operator()(string wordOne, string wordTwo) {

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	return bi->find(word)->biCount;
}

double& AvlDS::operator()(string wordOne, string wordTwo, int) {

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	return prob->find(word)->prob;
}

void AvlDS::incrementFileSize(long) {
	//implemented in vector
	int i = 0;
}

long getFileSize() {
	//implemented in vector
	long temp = 1;
	return temp;
}

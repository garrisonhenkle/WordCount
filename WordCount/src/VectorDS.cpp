/*
 * VectorDS.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#include "VectorDS.h"

//see header for description
VectorDS::VectorDS() {
	fileSize = 0;
} //end constructor VectorDS

//see header for description
VectorDS::~VectorDS() {

	mono.clear();
	bi.clear();
	prob.clear();
} //end deconstructor VectorDS

//see header for description
void VectorDS::addWord(string in) {
	//flag that indicates whether a pair is found in the vector, with found = 1
	int flag = 0;

	//makes lower case
	string word = toLowerCase(in);

	//searches the mono vector searching for a match.  If a match is found, the count is incremented and the flag is thrown
	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == word) {
			mono[i].second++;
			flag = 1;
			break;
		}
	} //end for

	//if the monogram was not found in the array, push it to the back
	if (flag == 0) {
		mono.push_back(make_pair(word, 1));
	}
} //end addWord(string)

//see header for description
void VectorDS::addTwoWords(string wordOne, string wordTwo) {
	//flag that indicates whether the current word has been found, where found = 1
	int flag = 0;

	//combines the two words into one string and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the bi vector for the bigram.  If the word is found, the count is incremented and flag thrown
	for (int i = 0; i < bi.size(); i++) {
		if (bi[i].first == word) {
			bi[i].second++;
			flag = 1;
			break;
		}
	} //end for

	//if the word is not found, it is pushed on the back
	if (flag == 0) {
		bi.push_back(make_pair(word, 1));
	}
} //end addTwoWords(string, string)

//see header for description
void VectorDS::addCondProb(string wordOne, string wordTwo, double probability) {
	//flag that indicates whether a probability has been found, where found = 1
	int flag = 0;

	//combines the words into one string and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the prob vector for the bigram.  If found, the probability is set to the input and the flag thrown
	for (int i = 0; i < prob.size(); i++) {
		if (prob[i].first == word) {
			prob[i].second = probability;
			flag = 1;
			break;
		}
	} //end for

	/*if the bigram is not
	 if (flag == 0) {
	 prob.push_back(make_pair(word, probability));
	 } */
} //end addCondProb(string, string, int)

//see header for description
int VectorDS::getWord(string in) {
	int out = -1;

	//sends to lower case
	string word = toLowerCase(in);

	//searches for the word in the mono vector.  Returns the count if found, -1 is not found
	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == word) {
			out = mono[i].second;
			break;
		}
	}

	return out;
} //end getWord(string)

int& VectorDS::getWordRef(string in) {

	//searches the mono vector for the monogram.  Returns the reference or creates a reference.
	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == in) {
			return mono[i].second;
		}
	}

	//isn't in mono, so add it
	mono.push_back(make_pair(in, 0));

	return mono[mono.size() - 1].second;
} //end getWordRef(string)

//see header for description
int VectorDS::getTwoWords(string wordOne, string wordTwo) {
	int out = -1;

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the bi vector for the bigram.  Returns the count if found, -1 otherwise
	for (int i = 0; i < bi.size(); i++) {
		if (bi[i].first == word) {
			out = bi[i].second;
			break;
		}
	}

	return out;
} //end getTwoWords(string, string)

//see header for description
int& VectorDS::getTwoWordsRef(string wordOne, string wordTwo) {

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the bi vector for the bigram.  Returns the reference or creates a reference.
	for (int i = 0; i < bi.size(); i++) {
		if (bi[i].first == word) {
			return bi[i].second;
		}
	}

	//isn't in bi, so add it
	bi.push_back(make_pair(word, 0));

	return bi[bi.size() - 1].second;
} //end getTwoWordsRed(string, string)

//see header for description
double VectorDS::getCondProb(string wordOne, string wordTwo) {
	double out = -1;

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the prob vector for the bigram.  If found, the probability is returned, otherwise -1 is returned
	for (int i = 0; i < prob.size(); i++) {
		if (prob[i].first == word) {
			out = prob[i].second;
			break;
		}
	}

	return out;
} //end getCondProb

//see header for description
double& VectorDS::getCondProbRef(string wordOne, string wordTwo) {

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//search for the probability in the vector
	for (int i = 0; i < prob.size(); i++) {
		if (prob[i].first == word) {
			return prob[i].second;
		}
	}

	//if its not there, add it
	prob.push_back(make_pair(word, 1));

	return prob[prob.size() - 1].second;

} //end getCondProbRef(string, string)

//see header for description
pair<string, string> VectorDS::split(string words) {

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

//see header for description
void VectorDS::printGrams() {
	//output file locations
	string monoOut = "text.uni";
	string biOut = "text.bi";

	//output file stream
	ofstream file;
	ofstream file2;

	calcCondProb();

	//
	//uni file
	//

	//try to open the file, exits if the file fails to open
	file.open(monoOut);
	if (!file) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	cout << "mono size is " << mono.size() << endl;

	//prints the monogram followed by a space followed by the monogram's count
	for (int i = 0; i < mono.size(); i++) {
		file << mono[i].first << ' ' << mono[i].second << endl;
	} //end for

	//closes the uni file
	file.close();

	//
	//bi file
	//

	//tries to open the file, exits if the file fails to open
	file2.open(biOut);
	if (!file2) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	//prints the bigram, a space, the bigram's count, a space, and the probability of the bigram
	for (int i = 0; i < bi.size(); i++) {
		file2 << bi[i].first << ' ' << bi[i].second << ' ' << prob[i].second << endl;
	} //end for

	//closes the bi file
	file2.close();
} //end printGrams()

//see header for description
string VectorDS::toLowerCase(string word) {
	string out = word;

	//calls the toLower() function on each character and returns the string
	for (int i = 0; i < out.length(); i++) {
		out[i] = tolower(out[i]);
	}

	return out;
} //end toLowerCase

//see header for description
void VectorDS::calcCondProb() {

	//size of the bi vector
	int size = bi.size();
	//count of the first word
	int wordCount;
	//probability of the first word followed by the second word
	double condProb;

	//holds the bigram's two words in two separate strings
	pair<string, string> splitWords;

	//if one of the counts is not calculated, throw an error
	if (bi.size() == 0 || mono.size() == 0) {
		size = -1;
	}

	//for all the bigrams in the bi vector, calculate the probability of the bigram and store in the prob vector
	for (int i = 0; i < size; i++) {

		//split the bigram into separate strings
		splitWords = split(bi[i].first);
		//find the count of the first word
		wordCount = getWord(splitWords.first);

		//calculate the probability by dividing the bigram count by the count of the first word of the bigram
		condProb = bi[i].second / wordCount;

		//set the corresponding position in the prob vector to the probability
		prob.push_back(make_pair(bi[i].first, condProb));
	} //end for

	//throw error for invalid input
	if (size == -1) {
		cerr << "Both the monograms and bigrams should be calculated becfore trying to calculate the probabilities." << endl;
	}

} //end calcCondProb()

//see header for description
double VectorDS::calcProb(string wordOne, string wordTwo) {

	double probability;
	//finds the count of a bigram
	int num = getTwoWords(wordOne, wordTwo);
	//finds the count of the bigram's first word
	int den = getWord(wordOne);

	//find the probability by dividing the bigram by the count of its first word
	probability = num / den;

	return probability;
} //end calcProb(string, string)

//see header for description
int& VectorDS::operator[](string word) {

	//returns the count of the monogram
	int& out = getWordRef(word);

	return out;
} //end operator[](string, string)

//see header for description
double& VectorDS::operator()(string wordOne, string wordTwo, int distinction) {

	//returns the count of the monogram
	double& out = getCondProbRef(wordOne, wordTwo);

	return out;
} //end operator()(string)

//see header for description
int& VectorDS::operator()(string wordOne, string wordTwo) {

	//returns the count of the bigram
	int& out = getTwoWordsRef(wordOne, wordTwo);

	return out;
} //end operator()(string, string)

void VectorDS::incrementFileSize(long x){
	fileSize+= x;
}

long VectorDS::getFileSize(){
	return fileSize;
}

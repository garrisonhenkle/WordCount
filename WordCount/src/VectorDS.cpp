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
	mono = new vector<pair<string, int>>;
	bi = new vector<pair<string, int>>;
	prob = new vector<pair<string, double>>;
} //end constructor VectorDS

//see header for description
VectorDS::~VectorDS() {

	mono->clear();
	delete mono;
	bi->clear();
	delete bi;
	prob->clear();
	delete prob;
} //end deconstructor VectorDS

//see header for description
void VectorDS::addWord(string in) {
	//flag that indicates whether a pair is found in the vector, with found = 1
	int flag = 0;

	//makes lower case
	string word = toLowerCase(in);

	//searches the mono vector searching for a match.  If a match is found, the count is incremented and the flag is thrown
	for (int i = 0; i < mono->size(); i++) {
		if (mono->at(i).first == word) {
			mono->at(i).second++;
			flag = 1;
			break;
		}
	} //end for

	//if the monogram was not found in the array, push it to the back
	if (flag == 0) {
		mono->push_back(make_pair(word, 1));
	}
} //end addWord(string)

//see header for description
void VectorDS::addTwoWords(string wordOne, string wordTwo) {
	//flag that indicates whether the current word has been found, where found = 1
	int flag = 0;

	//combines the two words into one string and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the bi vector for the bigram.  If the word is found, the count is incremented and flag thrown
	for (int i = 0; i < bi->size(); i++) {
		if (bi->at(i).first == word) {
			bi->at(i).second++;
			flag = 1;
			break;
		}
	} //end for

	//if the word is not found, it is pushed on the back
	if (flag == 0) {
		bi->push_back(make_pair(word, 1));
	}
} //end addTwoWords(string, string)

//see header for description
void VectorDS::addCondProb(string wordOne, string wordTwo, double probability) {
	//flag that indicates whether a probability has been found, where found = 1
	int flag = 0;

	//combines the words into one string and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the prob vector for the bigram.  If found, the probability is set to the input and the flag thrown
	for (int i = 0; i < prob->size(); i++) {
		if (prob->at(i).first == word) {
			prob->at(i).second = probability;
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
	for (int i = 0; i < mono->size(); i++) {
		if (mono->at(i).first == word) {
			out = mono->at(i).second;
			break;
		}
	}

	return out;
} //end getWord(string)

/*
 //see header for description
 int& VectorDS::getWordRef(string in) {

 //searches the mono vector for the monogram.  Returns the reference or creates a reference.
 for (int i = 0; i < mono->size(); i++) {
 if (mono->at(i).first == in) {
 return mono->at(i).second;
 }
 }

 //isn't in mono, so add it
 mono->push_back(make_pair(in, 0));

 return mono[mono.size() - 1].second;
 } //end getWordRef(string)
 */

//see header for description
int VectorDS::getTwoWords(string wordOne, string wordTwo) {
	int out = -1;

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the bi vector for the bigram.  Returns the count if found, -1 otherwise
	for (int i = 0; i < bi->size(); i++) {
		if (bi->at(i).first == word) {
			out = bi->at(i).second;
			break;
		}
	}

	return out;
} //end getTwoWords(string, string)

/*
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
 */

//see header for description
double VectorDS::getCondProb(string wordOne, string wordTwo) {
	double out = -1;

	//combines the two words into one and sends to lower case
	string word = toLowerCase(wordOne + ' ' + wordTwo);

	//searches the prob vector for the bigram.  If found, the probability is returned, otherwise -1 is returned
	for (int i = 0; i < prob->size(); i++) {
		if (prob->at(i).first == word) {
			out = prob->at(i).second;
			break;
		}
	}

	return out;
} //end getCondProb

/*
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
 */

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

	//calculate the probabilities
	calcCondProb();

	//
	//uni file
	//

	//try to open the file, exits if the file fails to open
	file.open(monoOut, ios_base::app);
	if (!file) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	//Creates separation in case multiple files are processed
	//Since all data is written to the same text.uni and text.bi files
	file << "\n\n";

	//prints the monogram followed by a space followed by the monogram's count
	for (int i = 0; i < mono->size(); i++) {
		file << mono->at(i).first << ' ' << mono->at(i).second << endl;
	} //end for

	//closes the uni file
	file.close();

	//
	//bi file
	//

	//tries to open the file, exits if the file fails to open
	file2.open(biOut, ios_base::app);
	if (!file2) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	//Creates separation in case multiple files are processed
	//Since all data is written to the same text.uni and text.bi files
	file2 << "\n\n";

	//prints the bigram, a space, the bigram's count, a space, and the probability of the bigram
	for (int i = 0; i < bi->size(); i++) {
		file2 << bi->at(i).first << ' ' << bi->at(i).second << ' ' << prob->at(i).second << endl;
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
	int size = bi->size();
	//count of the first word
	int wordCount;
	//probability of the first word followed by the second word
	double condProb;

	//holds the bigram's two words in two separate strings
	pair<string, string> splitWords;

	//if one of the counts is not calculated, throw an error
	if (bi->size() == 0 || mono->size() == 0) {
		size = -1;
	}

	//for all the bigrams in the bi vector, calculate the probability of the bigram and store in the prob vector
	for (int i = 0; i < size; i++) {

		//split the bigram into separate strings
		splitWords = split(bi->at(i).first);
		//find the count of the first word
		wordCount = getWord(splitWords.first);

		//calculate the probability by dividing the bigram count by the count of the first word of the bigram
		condProb = bi->at(i).second / wordCount;

		//set the corresponding position in the prob vector to the probability
		prob->push_back(make_pair(bi->at(i).first, condProb));
	} //end for

	//throw error for invalid input
	if (size == -1) {
		cerr << "Both the monograms and bigrams should be calculated becfore trying to calculate the probabilities." << endl;
		exit(1);
	}

} //end calcCondProb()

//see header for description
double VectorDS::calcProb(string wordOne, string wordTwo) {

	double probability = -1;

	//finds the count of a bigram
	int num = getTwoWords(wordOne, wordTwo);
	//finds the count of the bigram's first word
	int den = getWord(wordOne);

	//find the probability by dividing the bigram by the count of its first word if the counts exist
	if (num != -1 && den != -1) {
		probability = num / den;
	}

	return probability;
} //end calcProb(string, string)

//see header for description
int& VectorDS::operator[](string wordIn) {

	int pos = -1;

	//put the input in lower case
	string word = toLowerCase(wordIn);

	//search the vector for the word and set the index position if found
	for (int i = 0; i < mono->size(); i++) {
		if (mono->at(i).first == word) {
			pos = i;
			break;
		}
	}

	//if the word is not found, add it to the vector and set the index position to the last index of the vector
	if (pos == -1) {
		mono->push_back(make_pair(word, 0));
		pos = mono->size() - 1;
	}

	return mono->at(pos).second;
} //end operator[](string, string)

//see header for description
double& VectorDS::operator()(string wordOne, string wordTwo, int distinction) {

	int pos = -1;

	//combine the input words and send to lower case
	string word = toLowerCase((wordOne + ' ' + wordTwo));

	//search the vector for the word and set the index position if found
	for (int i = 0; i < prob->size(); i++) {
		if (prob->at(i).first == word) {
			pos = i;
			break;
		}
	}

	//if the word is not found, add it to the vector and set the index position to the last index of the vector
	if (pos == -1) {
		prob->push_back(make_pair(word, 0));
		pos = prob->size() - 1;
	}

	return prob->at(pos).second;
} //end operator()(string)

//see header for description
int& VectorDS::operator()(string wordOne, string wordTwo) {

	int pos = -1;

	//combine the input words and send to lower case
	string word = toLowerCase((wordOne + ' ' + wordTwo));

	//search the vector for the word and set the index position if found
	for (int i = 0; i < bi->size(); i++) {
		if (bi->at(i).first == word) {
			pos = i;
			break;
		}
	}

	//if the word is not found, add it to the vector and set the index position to the last index of the vector
	if (pos == -1) {
		bi->push_back(make_pair(word, 0));
		pos = bi->size() - 1;
	}

	return bi->at(pos).second;
} //end operator()(string, string)

void VectorDS::incrementFileSize(long x) {
	fileSize += x;
}

long VectorDS::getFileSize() {
	return fileSize;
}

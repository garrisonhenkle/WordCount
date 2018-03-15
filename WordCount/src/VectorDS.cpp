/*
 * VectorDS.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#include "VectorDS.h"

VectorDS::VectorDS() {
	mono = new vector<pair<string, int>>;
	bi = new vector<pair<string, int>>;
	prob = new vector<pair<string, double>>;
}

VectorDS::~VectorDS() {
	mono.clear();
	delete mono;
	bi.clear();
	delete bi;
	prob.clear();
	delete prob;
}

void VectorDS::addWord(string in) {
	int flag = 0;

	string word = toLowerCase(in);

	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == word) {
			mono[i].second++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		mono.push_back(make_pair(word, 1));
	}
}

void VectorDS::addTwoWords(string wordOne, string wordTwo) {

	int flag = 0;

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	for (int i = 0; i < bi.size(); i++) {
		if (bi[i].first == word) {
			bi[i].second++;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		bi.push_back(make_pair(word, 1));
	}
}

void VectorDS::addCondProb(string wordOne, string wordTwo, double probability) {

	int flag = 0;

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	for (int i = 0; i < prob.size(); i++) {
		if (prob[i].first == word) {
			prob[i] = probability;
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		prob.push_back(make_pair(word, probability));
	}
}

int VectorDS::getWord(string in) {
	int out = -1;

	string word = toLowerCase(in);

	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == word) {
			out = mono[i].second;
			break;
		}
	}

	return out;
}

int VectorDS::getTwoWords(string wordOne, string wordTwo) {
	int out = -1;

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	for (int i = 0; i < bi.size(); i++) {
		if (bi[i].first == word) {
			out = bi[i].second;
			break;
		}
	}

	return out;
}

double VectorDS::getCondProb(string wordOne, string wordTwo) {
	double out = -1;

	string word = toLowerCase(wordOne + ' ' + wordTwo);

	for (int i = 0; i < prob.size(); i++) {
		if (prob[i].first == word) {
			out = prob[i].second;
			break;
		}
	}

	return out;
}

pair<string, string> VectorDS::split(string words) {

	pair<string, string> out;

	int firstWord = 0;
	int secondWord;

	for (int i = 0; i < words.length(); i++) {
		if (!words[i] == ' ') {
			firstWord++;
		} else if (words[i] == ' ') {
			out.first = words.substr(0, firstWord);
			secondWord = words.length() - (firstWord + 1);
			out.second = words.substr(i + 1, secondWord);
			break;
		}
	}

	return out;
}

void VectorDS::printGrams() {
	string monoOut = "text.uni";
	string biOut = "text.bi";

	ofstream file;
	pair<string, string> splitWords;

	file.open(monoOut);
	if (!file) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	for (int i = 0; i < mono.size(); i++) {
		file << mono[i].first << ' ' << mono[i].second << endl;
	}

	file.close();

	file.open(biOut);
	if (!file) {
		cerr << "Can't write the output files.";
		exit(1);
	}

	for (int i = 0; i < bi.size(); i++) {
		splitWords = split(bi[i].first);
		file << splitWords.first << ' ' << splitWords.second << ' '
				<< bi[i].second << ' ' << prob[i] << endl;
	}
}

string toLowerCase(string word) {
	string out = word;

	for (int i = 0; i < out.length; i++) {
		out[i] = tolower(out[i]);
	}

	return out;
}
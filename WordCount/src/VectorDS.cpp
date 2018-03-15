/*
 * VectorDS.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: garrison
 */

#include "VectorDS.h"

VectorDS::VectorDS() {
	mono = new vector<pair<string, int>>;
	bi = new vector<pair<string, int>>;
}

VectorDS::~VectorDS() {
	mono.clear();
	delete mono;
	bi.clear();
	delete bi;
	prob.clear();
	delete prob;
}

void VectorDS::addWord(string word) {
	for (int i = 0; i < mono.size(); i++) {
		if (mono[i].first == word) {
			mono[i].second++;
			break;
		}
	}
	mono.push_back(make_pair(word, 1));
}

void VectorDS::split(){

}

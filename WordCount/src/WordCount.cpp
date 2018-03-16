/*
 * WordCount.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: garrison
 */

#include "WordCount.h"

int main(int argc, char* argv[]) {

}

vector<string> VectorDS::processLine(string line) {
	vector<string> out;

	for (int i = 0; i < line.length(); i++) {

	}

	return out;
}

void WordCount::processVectorDS(string fileLoc, VectorDS& inputDS) {
	string input;
	ifstream file;
	VectorDS ds = inputDS;

	file.open(fileLoc);
	if (!file) {
		cerr << "Unable to open input file";
		exit(1);
	}

	while (getline(file, input)) {

	}
}

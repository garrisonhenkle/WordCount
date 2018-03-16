/*
 * WordCount.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: garrison
 */

#include "WordCount.h"

int main(int argc, char* argv[]) {

}

vector<string> WordCount::processLine(string line) {
	vector<string> out;

	string temp = "";

	for (int i = 0; i < line.length(); i++) {
		if ((97 <= line[i] && line[i] = 122) || (65 <= line[i] && line[i] <= 90)
				|| line[i] == 39) {
			temp += line[i];
		} else {
			out.push_back(temp);
			temp = "";
		}
	}
	if (temp != "") {
		out.push_back(temp);
	}

	return out;
}

void WordCount::processVectorDS(string fileLoc, VectorDS& inputDS) {
	VectorDS ds = inputDS;

	ifstream file;
	string input;

	vector<string> words;

	string current = nullptr;
	string last = nullptr;

	file.open(fileLoc);
	if (!file) {
		cerr << "Unable to open input file";
		exit(1);
	}

	while (getline(file, input)) {
		words = processLine(input);

		current = words[0];
		ds(current)++;

		for (int i = 1; i < words.size(); i++) {
			last = current;
			current = words[i];

			if(current)
			ds(current)++;
			ds(last, current)++;
		}
	}
}

/*
 * WordCount.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Garrison Henkle
 */

#include "WordCount.h"

int main(int argc, char* argv[]) {

	//holds the time it takes for the three data structures to read and print
	long time;

	vector<long> vectorTime;
	vector<long> avlTime;
	vector<long> hashTime;

	ofstream file;

	string fileName;

	VectorDS * ds = new VectorDS();

	WordCount wc = WordCount();

	//for (int i = 0; i < argc; i++) {

	//fileName = argv[i];

	fileName = "text1.txt";

	auto startTime = chrono::high_resolution_clock::now();

	//Count using the vector
	//Count placed inside a nanosecond timer
	wc.processVectorDS(fileName, ds);
	auto finishTime = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::nanoseconds>(finishTime - startTime).count();
	vectorTime.push_back(time);
	avlTime.push_back(0);
	hashTime.push_back(0);

//	}

	file.open("text.time");
	if (!file) {
		cerr << "couldn't open the file";
		exit(1);
	}

	file << '\t' << "Vector\t" << "AVL\t" << "Hash\t" << endl;
	for (int i = 0; i < vectorTime.size(); i++) {
		file << ds->getFileSize() << '\t' << vectorTime[i] << '\t' << avlTime[i] << '\t' << hashTime[i] << endl;
	}

	delete ds;
	cout << "Finished: output in files text.uni, text.bi, " << endl;
	return 0;
} //end main(int, char*)

//see header for description
vector<string> WordCount::processLine(string line) {
	vector<string> out;

	//temorary word holder
	string temp = "";

	//creates words made up of lower- and upper-case letters and '
	//once a word is created, it is pushed to the back of the output vector
	for (int i = 0; i < line.length(); i++) {
		if ((97 <= line[i] && line[i] <= 122) || (65 <= line[i] && line[i] <= 90) || line[i] == 39) {
			temp += line[i];
		} else {
			out.push_back(temp);
			temp = "";
		}
	} //end for loop

	//if the loop ends and the temp variable still contains letters (i.e. the line ended without a next line character)
	//Then push the word to the back of the vector
	if (temp != "") {
		out.push_back(temp);
	}

	return out;
} //end processLine(string)

//see header for description
void WordCount::processVectorDS(string fileLoc, VectorDS * dsIn) {
	//datastructure being used to process the text
	VectorDS* ds = dsIn;

	//input file stream
	ifstream file;
	//string that holds lines of input text
	string input;

	//vector that holds all the words in a line
	vector<string> words;

	//current word of the iterator
	string current;
	//last word of the iterator
	string last = "!";

	//tries to open the file, exits if it cannot open it
	file.open(fileLoc);
	if (!file) {
		cerr << "Unable to open input file";
		exit(1);
	}

	//for every avaliable line, the line is first turned into a vector of words, which are used to increase the count of
	//monograms and bigrams in the datastructure
	while (getline(file, input)) {

		//put every word in the line into a vector of strings
		words = processLine(input);

		//increment the fileSize for each word
		ds->incrementFileSize(words.size());

		//set current to the first word in the new line
		current = words[0];

		//if there is a word from the last line, increment the count of its bigram
		if (last != "!") {
			ds->operator()(last, current)++;}

			//increment the current's monogram
		ds->operator[](current)++;

		//increment all the monograms and bigrams of the line
		for
(		int i = 1; i < words.size (); i++) {
			last = current;
			current = words[i];

			ds->operator[] (current)++;
			ds->operator() (last, current)++;
		}
		//end for

		//set the current to last so it can be carried over to the next line
		last = current;
	} //end while

	//calclulates all the probabilies for all the bigrams
	ds->calcCondProb();
	//prints all the data to the .uni and .bi files

	ds->printGrams();

	//close the input stream
	file.close();

} //end processVectorDS(string, VectorDS)

//============================================================================
// Name        : BST.cpp
// Author      : Hani Z. Girgis
// Version     :
// Description : BST in C++. This is the entry point to the program
//============================================================================

#include <iostream>
#include <string>

#include "Tree.h"
using namespace std;

int main() {
	cout << "Tree demonstration" << endl;
	Tree<string> tree("G");
	tree.insert("A");
	tree.insert("Z");
	tree.insert("B");
	tree.insert("S");
	tree.inOrder();
	cout << "The minimum is: " << tree.min() << endl;

	auto result = tree.find("B");
	cout << "Child is: " << result.first->getElm() << endl;
	cout << "Parent is: " << result.second->getElm() << endl;

	cout << "About to delete B" << endl;
	tree.remove("B");
	tree.inOrder();

	return 0;
}

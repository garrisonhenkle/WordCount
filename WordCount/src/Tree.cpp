/*
 * Tree.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: Hani Zakaria Girgis
 */

template<typename T>
Tree<T>::Tree(T elm) {
	root = new Node<T>(elm);
}

template<typename T>
Tree<T>::~Tree() {
	cleanUp(root);
}

template<typename T>
void Tree<T>::cleanUp(Node<T> * subtree) {
	if (subtree->getLt() != nullptr) {
		cleanUp(subtree->getLt());
	}

	if (subtree->getRt() != nullptr) {
		cleanUp(subtree->getRt());
	}
	delete subtree;
}

template<typename T>
void Tree<T>::insert(T elm) {
	insert(elm, root);
}

template<typename T>
void Tree<T>::insert(T elm, Node<T> * subtree) {
	T treeElm = subtree->getElm();
	if (elm != treeElm) {

		if (elm < treeElm) {
		        auto ltTree = subtree->getLt();
			if (ltTree == nullptr) {
				subtree->setLt(new Node<T>(elm));
			} else {
				insert(elm, ltTree);
			}
		} else {
			auto rtTree = subtree->getRt();
			if (rtTree == nullptr) {
				subtree->setRt(new Node<T>(elm));
			} else {
				insert(elm, rtTree);
			}
		}
	}

}

template<typename T>
void Tree<T>::inOrder() {
	inOrder(root);
}

template<typename T>
void Tree<T>::inOrder(Node<T> * subtree) {
	auto ltChild = subtree->getLt();
	if (ltChild != nullptr) {
		inOrder(ltChild);
	}
	cout << subtree->getElm() << endl;
	auto rtChild = subtree->getRt();
	if (rtChild != nullptr) {
		inOrder(rtChild);
	}
}

template<typename T>
T Tree<T>::min() {
	return min(root);
}

template<typename T>
T Tree<T>::min(Node<T> * subtree) {
	T minimum = subtree->getElm();
	if (subtree->getLt() != nullptr) {
		minimum = min(subtree->getLt());
	}
	return minimum;
}

template<typename T>
void Tree<T>::remove(T elm) {
	if (root->getElm() == elm) {
		if (root->getChildrenCount() == 0) {
			root = nullptr;
		} else if (root->getChildrenCount() == 1) {
			auto ltChild = root->getLt();
			auto rtChild = root->getRt();
			delete root;
			if (ltChild != nullptr) {
				root = ltChild;
			} else {
				root = rtChild;
			}
		} else if (root->getChildrenCount() == 2) {
			remove(elm, root);
		}
	} else {
		remove(elm, root);
	}
}

template<typename T>
void Tree<T>::remove(T elm, Node<T> * subtree) {
// Case 1
	auto childAndParent = find(elm, subtree);
	auto child = childAndParent.first;
	auto parent = childAndParent.second;
	auto ltGrandChild = child->getLt();
	auto rtGrandChild = child->getRt();

	if (child->getChildrenCount() == 0) {
		if (parent->getLt() == child) {
			parent->setLt(nullptr);
		} else if (parent->getRt() == child) {
			parent->setRt(nullptr);
		}
		delete child;
	} else if (child->getChildrenCount() == 1) {
		if (parent->getLt() == child) {
			if (ltGrandChild != nullptr) {
				parent->setLt(ltGrandChild);
			} else {
				parent->setLt(rtGrandChild);
			}
		} else {
			if (rtGrandChild != nullptr) {
				parent->setRt(rtGrandChild);
			} else {
				parent->setRt(ltGrandChild);
			}
		}
		delete child;
	} else if (child->getChildrenCount() == 2) {
       		T m = min(rtGrandChild);
		remove(m, child);
		child->setElm(m);
	} else {
		cerr << "Invalid number of children: " << child->getChildrenCount()
				<< endl;
	}
}

template<typename T>
pair<Node<T> *, Node<T> *> Tree<T>::find(T elm) {
	return find(elm, root);
}

template<typename T>
pair<Node<T> *, Node<T> *> Tree<T>::find(T elm, Node<T> * parent) {
	auto lt = parent->getLt();
	auto rt = parent->getRt();

	pair<Node<T> *, Node<T> *> result;
	if (parent->getElm() == elm) {
		result = make_pair(parent, nullptr);
	} else if (lt != nullptr && lt->getElm() == elm) {
		result = make_pair(lt, parent);
	} else if (rt != nullptr && rt->getElm() == elm) {
		result = make_pair(rt, parent);
	} else if (lt != nullptr && elm < parent->getElm()) {
		result = find(elm, lt);
	} else if (rt != nullptr && elm > parent->getElm()) {
		result = find(elm, rt);
	}
	return result;

}

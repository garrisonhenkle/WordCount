/*
 * Node.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Hani Zakaria Girgis
 */

template<typename T>
Node<T>::Node(T element) {
	elm = element;
	lt = nullptr;
	rt = nullptr;
}

template<typename T>
Node<T>::Node(T element, Node<T> * left, Node<T> * right) {
	elm = element;
	lt = left;
	rt = right;

}

template<typename T>
Node<T>::~Node() {
  // Nothing was allocated on the heap
}

template<typename T>
T Node<T>::getElm() {
	return elm;
}

template<typename T>
Node<T> * Node<T>::getLt() {
	return lt;
}

template<typename T>
Node<T> * Node<T>::getRt() {
	return rt;
}

template<typename T>
void Node<T>::setElm(T newElm) {
	elm = newElm;
}

template<typename T>
void Node<T>::setLt(Node<T> * newLt) {
	lt = newLt;
}

template<typename T>
void Node<T>::setRt(Node<T> * newRt) {
	rt = newRt;
}

template<typename T>
int Node<T>::getChildrenCount() {
	int count = 0;
	if (lt != nullptr) {
		count++;
	}
	if (rt != nullptr) {
		count++;
	}
	return count;
}

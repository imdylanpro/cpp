/*
Dylan Nelson
October 08, 2025
Linked_List_Full_Implementation_Template_Project\\LinkedList.h
*/

/*
Create a Linked List template class with a default Constructor and a Destructor.
The linked list class should support:
Prepending a new node (to the beginning) of the list.
Postpending a new node (to the end) of the list.
Deleting a node at a given index.
Deleting all occurances of a value.
Sorting the list in ascending or descending order.
The node class should hold an integer data type and a pointer to the next node.

class Node{};
class LinkedList{};
*/

// Implementation of the LinkedList header file
#include "LinkedList.h"
#include <iostream>

// Node Constructor
template <typename Type>
LinkedList<Type>::Node::Node(const Type& value) : data(value), next(nullptr) {}

// LinkedList Constructor
template <typename Type>
LinkedList<Type>::LinkedList() : head(nullptr) {}

// Destructor
template <typename Type>
LinkedList<Type>::~LinkedList() {
	Node* current = head;
	while (current) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

// Add item to beginning of list.
template <typename Type>
void LinkedList<Type>::prepend(const Type& value) {
	Node* newNode = new Node(value);
	newNode->next = head;
	head = newNode;
}

template <typename Type>
void LinkedList<Type>::postpend(const Type& value) {
	Node* current = head;

	if (!current) {
		prepend(value);
		return;
	}

	while (current->next) {
		current = current->next;
	}
	Node* newNode = new Node(value);
	current->next = newNode;
}

template <typename Type>
void LinkedList<Type>::printList() {
	Node* current = head;
	while (current) {
		if (current->next) std::cout << current->data << ", ";
		else std::cout << current->data;
		current = current->next;
	}
	std::cout << std::endl;
}

template <typename Type>
void LinkedList<Type>::deleteAtIndex(const int index) {

	if (index < 0) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	Node* curr = head;

	if (!curr) {
		std::cout << "List is empty!" << std::endl;
		return;
	}

	if (index == 0) {
		Node* next = curr->next;
		delete curr;
		head = next;
		return;
	}

	for (int j = 0; j < index - 1; j++) {
		if (!curr->next) {
			std::cout << "Invalid index!" << std::endl;
			return;
		}
		curr = curr->next;
	}

	Node* temp = curr->next;
	if (!temp) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	curr->next = temp->next;
	delete temp;
}
/*
Dylan Nelson
October 08, 2025
Linked_List_Header_Source_Implementation\\LinkedList.cpp
*/

// Implementation of the LinkedList header file
#include "LinkedList.h"
#include <iostream>

// Node Constructor
LinkedList::Node::Node(const int i) {
	data = i;
	next = nullptr;
}

// Constructor
LinkedList::LinkedList() {
	head = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
	Node* current = head;
	while (current) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

// Add item to beginning of list.
void LinkedList::prepend(const int i) {
	Node* newNode = new Node(i);
	newNode->next = head;
	head = newNode;
}

void LinkedList::postpend(const int i) {
	Node* current = head;

	if (!current) {
		prepend(i);
		return;
	}

	while (current->next) {
		current = current->next;
	}
	Node* newNode = new Node(i);
	current->next = newNode;
}

void LinkedList::printList() {
	Node* current = head;
	while (current) {
		if (current->next) std::cout << current->data << ", ";
		else std::cout << current->data;
		current = current->next;
	}
	std::cout << std::endl;
}

void LinkedList::deleteAtIndex(const int index) {

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
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
The node class should hold any data type and a pointer to the next node.

class Node{};
class LinkedList{};
*/

#pragma once
#include <iostream>

// Templates can be "class" or "typename".
template <class Type>
class LinkedList {
private:
	struct Node {
		Type data;
		Node* next;
		Node(const Type& value);
	};
public:
	LinkedList();							// Constructor
	~LinkedList();							// Destructor
	void prepend(const Type& value);
	void postpend(const Type& value);
	void deleteAtIndex(const int index);
	void deleteAllOf(const Type& value);
	void sort(bool order = true);			// Sorting Algorithm. True = Ascending, False = Descending
	void printList();
private:
	Node* head;
};

/*
IMPORTANT CLARIFICATION:
Because Templates are resolved at runtime, they MUST be defined in the header file. This is because they are
compiled when used not when defined. The compiler will not have access to the template definitions when using 
LinkedList<sometype> in main.cpp

Templates can be included separately, if a .tpp file (template implementation file) is included at the bottom of the 
header.
*/

// Node Constructor with initializer list.
template <typename Type>
LinkedList<Type>::Node::Node(const Type& value) : data(value), next(nullptr) {}

// LinkedList Constructor with initializer list.
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
void LinkedList<Type>::deleteAllOf(const Type& value) {

	
	// Special case: LinkedList is empty
	if (!head) return;
	
	// Special case: head nodes need to be deleted.
	while (head && head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	Node* curr = head;
	while (curr && curr->next) {
		if (curr->next->data == value) {
			Node* temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		else {
			curr = curr->next;
		}
	}
}

template <typename Type>
void LinkedList<Type>::sort(bool order) {

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
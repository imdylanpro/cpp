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
	LinkedList(const LinkedList& source);	// Copy-Constructor
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

// Here the entirety of LinkedList.tpp is placed inline. Helping separate the implementation from the declaration.
#include "LinkedList.tpp"
/*
Dylan Nelson
October 08, 2025
Linked_List_Header_Source_Implementation\\LinkedList.h
*/

/*
Create a Linked List class with a default Constructor and a Destructor. The linked list class should support:
Prepending a new node (to the beginning) of the list
The node class should hold an integer data type and a pointer to the next node.

class Node{};
class LinkedList{};
*/

class LinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node(const int i);
	};
public:
	LinkedList();						// Constructor
	~LinkedList();						// Destructor
	void prepend(const int i);
	void postpend(const int i);
	void printList();
	void deleteAtIndex(const int index);
private:
	Node* head;
};
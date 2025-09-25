/*
Create a Linked List class with a default Constructor and a Destructor.The linked list class should support :
Prepending a new node (to the beginning) of the list
The node class should hold an integer data type and a pointer to the next node.

class Node{};
class LinkedList{};
*/

#include <iostream>

class LinkedList {
public:
	class Node {
	public:
		int val;
		Node* next;
		Node(int i);
	};
public:
	LinkedList();						// constructor
	~LinkedList();						// destructor
	LinkedList(const LinkedList& source);		// copy constructor
public:
	void prepend(int i);
	void printList() const;
	void postpend(int i);
private:
	Node* head;
};

LinkedList::Node::Node(int i) : val(i), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
	Node* curr = head;
	while (curr) {
		Node* nextNode = curr->next;
		delete curr;
		curr = nextNode;
	}
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr) {
	// Leave if source is empty.
	if (!source.head) return;

	// Assign the head to the value of the source LinkedList.
	head = new Node(source.head->val);

	// Create two pointers, one to the head. 
	//	The other to the source's next value.
	Node* currNew = head;
	Node* currSource = source.head->next;


	while (currSource) {
		// Create the new node based on the value of the current of source.
		currNew->next = new Node(currSource->val);
		// Advance the current newNode.
		currNew = currNew->next;
		// advance the source's node.
		currSource = currSource->next;
	}
}

void LinkedList::prepend(int i) {
	Node* newNode = new Node(i);
	newNode->next = head;
	head = newNode;
}

void LinkedList::printList() const {
	Node* curr = head;
	while (curr) {
		std::cout << curr->val << ", ";
		curr = curr->next;
	}
	std::cout << "\n";
}

void LinkedList::postpend(int i) {

	Node* newNode = new Node(i);
	if (!head) {
		head = newNode;
		return;
	}

	Node* curr = head;
	while (curr->next) {
		curr = curr->next;
	}

	curr->next = newNode;
}

int main() {

	LinkedList myLL = LinkedList();
	myLL.postpend(99);
	for (int i = 1; i <= 10; i++) {
		myLL.prepend(i);
		myLL.postpend(i * 5);
	}
	std::cout << "First Linked List: " << std::endl;
	myLL.printList();

	// Use the copy constructor we just made to create a new linkedlist based on the first one.
	LinkedList mySecondLL = myLL;

	std::cout << "Adding new elements to second linked list." << std::endl;
	for (int i = 40; i >= 30; i--) mySecondLL.prepend(i);

	std::cout << "Second (Copied) Linked List: " << std::endl;
	mySecondLL.printList();

	std::cout << "First Linked List: " << std::endl;
	myLL.printList();

	return 0;
}
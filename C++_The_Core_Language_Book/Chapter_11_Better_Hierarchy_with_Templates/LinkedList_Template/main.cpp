// Dylan Nelson
// October 03, 2025
// LinkedList_Template\\main.cpp

#include <iostream>

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;

		Node(const T& value) : data(value), next(nullptr) {}
	};

	Node* head;

public:
	LinkedList() : head(nullptr) {}

	~LinkedList() {
		Node* curr = head;
		while (curr) {
			Node* nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
	}

	void prepend(const T& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void printList() {
		Node* curr = head;
		while (curr) {
			std::cout << curr->data << ", ";
			curr = curr->next;
		}
	}
};

int main() {
	
	LinkedList<int> myIntLL;
	for (int i = 1; i <= 10; i++)
		myIntLL.prepend(i);
	myIntLL.printList();

	LinkedList<char> myCharLL;
	myCharLL.prepend('a');
	myCharLL.prepend('b');
	myCharLL.prepend('c');
	myCharLL.prepend('d');
	myCharLL.printList();

	return 0;
}
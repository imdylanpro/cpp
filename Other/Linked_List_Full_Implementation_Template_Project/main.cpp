/*
Dylan Nelson
October 08, 2025
Linked_List_Header_Source_Implementation\\main.cpp
*/

#include "LinkedList.h"
#include <iostream>

using namespace std;

void intLinkedList() {
	LinkedList<int> myintLL;

	cout << "Working with int Linked List" << endl;

	myintLL.deleteAtIndex(0);

	for (int i = 0; i < 5; i++) {
		myintLL.prepend(45);
	}

	for (int i = 1; i <= 5; i++) {
		myintLL.prepend(i);
		myintLL.postpend(i * 10);
	}

	for (int i = 0; i < 5; i++) {
		myintLL.prepend(45);
	}

	myintLL.printList();

	myintLL.deleteAllOf(45);
	myintLL.deleteAtIndex(20);
	myintLL.deleteAtIndex(19);
	myintLL.deleteAtIndex(0);
	myintLL.deleteAtIndex(5);
	myintLL.deleteAtIndex(100);

	myintLL.printList();
}

void charLinkedList() {

	LinkedList<char> mycharLL;

	cout << "Working with char Linked List" << endl;

	mycharLL.deleteAtIndex(0);

	mycharLL.prepend('a');
	mycharLL.postpend('b');
	mycharLL.prepend('c');
	mycharLL.postpend('d');
	mycharLL.prepend('e');

	mycharLL.deleteAtIndex(5);
	mycharLL.deleteAtIndex(4);
	mycharLL.deleteAtIndex(100);

	mycharLL.printList();
}

int main() {

	intLinkedList();
	charLinkedList();

	return 0;
}
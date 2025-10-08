/*
Dylan Nelson
October 08, 2025
Linked_List_Header_Source_Implementation\\main.cpp
*/

#include "LinkedList.h"

int main() {
	
	LinkedList myLL;

	myLL.deleteAtIndex(0);

	for (int i = 1; i <= 10; i++) {
		myLL.prepend(i);
		myLL.postpend(i * 10);
	}

	myLL.printList();

	myLL.deleteAtIndex(20);
	myLL.deleteAtIndex(19);
	myLL.deleteAtIndex(0);
	myLL.deleteAtIndex(5);
	myLL.deleteAtIndex(100);

	myLL.printList();
	return 0;
}
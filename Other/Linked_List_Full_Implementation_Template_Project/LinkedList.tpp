/*
Dylan Nelson
October 08, 2025
Linked_List_Full_Implementation_Template_Project\\LinkedList.h
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

// Copy-Constructor
template <typename Type>
LinkedList<Type>::LinkedList(const LinkedList& source) : head(nullptr) {

	if (!source.head) return;

	head = new Node(source.head->data);

	// Create two pointers one to the head,
	// Other to the source's next value.
	// Both used to advance through the two LinkedLists.
	Node* currNew = head;
	Node* currSource = source.head->next;

	while (currSource) {
		currNew->next = new Node(currSource->data);
		currSource = currSource->next;
		currNew = currNew->next;
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

template <class Type>
void LinkedList<Type>::sort(bool order) {
	if (!head || !head->next) return; // List is empty or has one element

	bool swapped;
	do {
		swapped = false;
		Node* current = head;
		while (current->next) {
			bool shouldSwap = order ? (current->data > current->next->data)
									: (current->data < current->next->data);
			if (shouldSwap) {
				std::swap(current->data, current->next->data);
				swapped = true;
			}
			current = current->next;
		}
	} while (swapped);
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
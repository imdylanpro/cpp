// Dylan Nelson
// September 12, 2025
// StackClass.cpp

#include <iostream>

// Class members are private by default.
class Stack {
// Public members can be accessed by anything. 
public:		

	void push(int i) {		// push() method, used to add things to top of the stack.
		if (size < 5) {
			items[size++] = i;
		}
		else {
			std::cerr << "Stack overflow" << std::endl;
		}
		
	}

	int pop() {				// pop() method, used to remove things from the top of the stack.
		if (size > 0) {
			return items[--size];
		}
		else {
			std::cerr << "Stack underflow" << std::endl;
			return -1;
		}
	}
	
	Stack() {				// Constructor, executes when the object is instantiated.
		size = 0;
	}

	~Stack() {}				// Destructor, executes when the class object goes out of scope.
	

// Private members can be accessed only by the object of the class itself.
private:
	int items[5];
	int size;
};

int main() {
	
	Stack myStack = Stack();

	myStack.push(1);
	myStack.push(23);
	myStack.push(40);
	myStack.push(17);
	myStack.push(25);
	myStack.push(14);

	std::cout << "Element 1: " << myStack.pop() << std::endl;
	std::cout << "Element 2: " << myStack.pop() << std::endl;
	std::cout << "Element 3: " << myStack.pop() << std::endl;
	std::cout << "Element 4: " << myStack.pop() << std::endl;
	std::cout << "Element 5: " << myStack.pop() << std::endl;
	std::cout << "Element 6: " << myStack.pop() << std::endl;

	return 0;
}
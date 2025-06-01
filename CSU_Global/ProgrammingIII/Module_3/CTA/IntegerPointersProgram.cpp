// Dylan Nelson
// May 01, 2025
// IntegerPointers.cpp

#include <iostream>

using namespace std;

int main() {

	// Create the new int variables and instantiate to 0.
	int* number1 = new int(0);
	int* number2 = new int(0);
	int* number3 = new int(0);

	// Gather the int values from the user.
	cout << "Please enter three values for the integers." << endl;

	// Number 1.
	cout << "Number 1: ";
	cin >> *number1;
	// Print the value for the pointer and the variable.
	cout << "The variable value for Number 1 is: " << *number1 << endl;
	cout << "The memory address for Number 1 is: " << number1 << endl;

	// Number 2.
	cout << "Number 2: ";
	cin >> *number2;
	cout << "The variable value for Number 2 is: " << *number2 << endl;
	cout << "The memory address for Number 2 is: " << number2 << endl;

	// Number 3
	cout << "Number 3: ";
	cin >> *number3;
	cout << "The variable value for Number 3 is: " << *number3 << endl;
	cout << "The memory address for Number 3 is: " << number3 << endl;

	// Delete the pointers.
	delete number1;
	delete number2;
	delete number3;

	return 0;

}

//============================================================================
// Name        : fictional_person.cpp
// Author      : Dylan Nelson
// Date		   : May 18, 2025
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string firstName = "Marygold";
	string lastName = "Johnson";
	string streetAddress = "123 Royal Ln";
	string city = "Austin";
	int zipCode = 68754;

	cout << "Here is some information for a fictional person!" << endl;
	// Using the system insertion operator the first name and string can be on the same line.
	cout << "The fictional person's name is " << firstName << " " << lastName << "." << endl;
	cout << "They live in " << city << "at " << streetAddress << ". ";
	cout << "With zip code: " << zipCode << endl;
	return 0;
}

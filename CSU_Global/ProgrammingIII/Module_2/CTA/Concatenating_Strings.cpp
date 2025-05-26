//============================================================================
// Name        : Concatenating_Strings.cpp
// Author      : Dylan Nelson
// Date		   : May 25, 2025
//============================================================================

#include <iostream>
using namespace std;

void conStrings() {

	string firstString;
	string secondString;
	string concatenatedString;

	cout << "Please enter the first string: " << endl;
	// Using getline(), the whitespace wont be ignored. This means that we can get strings that are multiple words.
	getline(cin, firstString);

	// Get the second string.
	cout << "Please enter the second string: " << endl;
	getline(cin, secondString);

	// Concatenate the strings and put them to the terminal.
	concatenatedString = firstString + secondString;
	cout << "The concatenation of the strings is: " << concatenatedString << endl;

}

int main() {

	// Call the function created three times.
	conStrings();
	conStrings();
	conStrings();

	return 0;
}

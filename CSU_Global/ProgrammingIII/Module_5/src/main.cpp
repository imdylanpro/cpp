/*
 * main.cpp
 *
 *  Created on: Jun 15, 2025
 *      Author: dylan
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Function declarations
string getUserInput();
string getFileContents();
string reverseFileContents();
void appendToFile(string);
void saveToFile(string);

string getUserInput() {

	string input = "";

	cout << "Please enter some information: " << endl;
	getline(cin, input);
	cout << "You entered: " << input << endl;

	return input;
}

string getFileContents() {
	string output, line;

	ifstream f("CSC450_CT5_mod5.txt");

	if (!f.is_open()) {
		cout << "Error: File is not open.";
	}

	// Open the file and print the contents to the string that was delcared
	while (getline(f , line)) {
		output += line + "\n";

	}

	return output;
}

string reverseFileContents() {

	string fileString;

	fileString = getFileContents();
	reverse(fileString.begin(), fileString.end());
	saveToFile(fileString);

	return fileString;
}

void appendToFile(string input) {

	ofstream f("CSC450_CT5_mod5.txt", ios::app);

	f << input << endl;
	f.close();
	cout << "Successfully appended to file!" << endl;

	return;
}

void saveToFile(string input) {

	ofstream f("CSC450-mod5-reverse.txt");

	f << input << endl;
	f.close();
	cout << "Successfully wrote to file!" << endl;

	return;
}

int main() {

	string userInput = "";
	string fileContents = "";
	string reverseStringContents = "";

	// Print out the original contents.
	fileContents = getFileContents();
	cout << "Original file contents: \n" << fileContents << endl;

	// Get user input and append to the file.
	userInput = getUserInput();
	appendToFile(userInput);

	// Print out the contents of the file now that it has user input appended.
	fileContents = getFileContents();
	cout << "Updated file contents: \n" << fileContents << endl;

	// Reverse the file contents and save it to the txt file.
	reverseStringContents = reverseFileContents();
	cout << "Reversed file contents: \n" << reverseStringContents << endl;

	return 0;
}

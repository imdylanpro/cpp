// Dylan Nelson
// September 25, 2025
// IntIdClass\\main.cpp
// Adapted from: C++ The Core Language

#include <iostream>

class Id {
public:
	Id();						// Default constructor
	~Id();						// Default destructor
	void operator=(Id& src);	// Assignment operator
	Id(Id& src);				// Copy constructor

public:
	void print(std::ostream* os);	// Printing member function.
	void set(char& idStr);		// Sets value.

private:

};
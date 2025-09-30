// Dylan Nelson
// September 25, 2025
// IntIdClass\\main.cpp
// Adapted from: C++ The Core Language

#include <iostream>
#include <cstdlib>

class Id {
public:
	Id();							// Default constructor
	// ~Id();						// Uses implicit default destructor
	// void operator=(Id& src);		// uses implicit assignment operator
	// Id(Id& src);					// uses implicit copy constructor

public:
	void print(std::ostream* os);	// Printing member function.
	void set(char *idStr);		// Sets value.

private:
	int value;
};

Id::Id() {
	value = 0;
}

void Id::print(std::ostream* os) {
	*os << "Id{" << value << '}';
}

void Id::set(char *idStr) {
	if (idStr == 0) {
		std::cerr << "bad id" << std::endl;
		return;
	}
	value = std::atoi(idStr);
}

int main() {
	
	Id myID = Id();

	char* input = const_cast<char*>("42");
	myID.set(input);
	
	Id myID2 = myID;
	
	myID.print(&std::cout);
	myID2.print(&std::cout);


	std::cout << std::endl;


	
	return 0;
}
// Dylan Nelson
// September 30, 2025
// DynamicArrayIdClass\\main.cpp

#include <iostream>

static void error(const char* msg) {
	std::cerr << "Error: " << msg;
	exit(1);
}

class Id {
public:
	Id();							// Constructor
	~Id();							// Destructor
	Id& operator=(const Id& src);	// Assignment-operator
	Id(const Id& src);					// Copy-constructor

public:
	void print(std::ostream *os);
	void set(char *idStr);

private:
	void newVal(const char* val);
	void deleteVal();

private:
	char* value;
};

void Id::newVal(const char* val) {
	if (val == 0)
		error("bad id");
	value = new char[strlen(val) + 1];
	strcpy_s(value, strlen(val) + 1, val);
}

void Id::deleteVal() {
	delete[] value;
}

Id::Id() {
	newVal("0");
}

Id::~Id() {
	deleteVal();
}

Id& Id::operator=(const Id& src) {
	if (this == &src) return *this; // Don't assign to self.
	deleteVal();
	newVal(src.value);
	return *this;
}

Id::Id(const Id& src) {
	newVal(src.value);
}

void Id::print(std::ostream *os) {
	*os << "Id{" << value << '}';
}

void Id::set(char* idStr) {
	deleteVal();
	newVal(idStr);
}

int main() {

	Id myID = Id();

	char* input = const_cast<char*>("42");
	myID.set(input);

	Id myID2 = myID;

	myID.print(&std::cout);
	std::cout << std::endl;
	myID2.print(&std::cout);
	std::cout << std::endl;

	return 0;
}
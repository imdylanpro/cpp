// Dylan Nelson
// September 30, 2025
// StaticArrayIdClass\\main.cpp

#include <iostream>
#define MAX_ID_LEN 16

void error(const char* msg) {
	std::cerr << "error: " << msg << '\n';
	exit(1);
}

class Id {
public:
	Id();
	// implicit ~Id();
	// implicit void operator=(Id &src);
	// implicit Id(Id &src);

public:
	void print(std::ostream* os);
	void set(char* idStr);

private:
	// Set value to size of MAX_ID_LEN + 1 for null terminator.
	char value[MAX_ID_LEN + 1];
};

Id::Id() {
	value[0] = '0';
	value[1] = '\0';
}

void Id::print(std::ostream* os) {
	*os << "Id{" << value << '}';
}

void Id::set(char* idStr) {
	if (idStr == 0 || strlen(idStr) > MAX_ID_LEN)
		error("bad id");
	strcpy_s(value, idStr);
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
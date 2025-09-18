// Dylan Nelson
// September 17, 2025
// StructArray.cpp

// This header file contains the standard C library (defines malloc and free).
#include <cstdlib>

// Create a struct for an IntArray, with two attributes.
struct IntArray {
	int* elems;
	size_t numElems;
};

int main() {
	// Using an initializer list will automatically assign 0 to elems and numElems.
	IntArray powersOf2 = { 0, 0 };
	// Because elems is a pointer (int *) 0 is treated as nullptr.

	// struct attributes are public by default, can directly access them.
	powersOf2.numElems = 8;

	// This line dynamically allocates memory for 8 integers the size of which was defined in previous line.
	powersOf2.elems = (int*)malloc(powersOf2.numElems * sizeof(int));
	// malloc returns a void* pointer, so it is casted to an int* pointer.
	
	// elems is still a pointer to the first slot in memory for an int. Pointer indexing and array indexing are interchangable.
	powersOf2.elems[0] = 1;
	
	
	// This line is equivalent to:
	//	*(powersOf2.elems + 1);
	// Array indexing essentially points to the first value in the array: elems[0] then adds 1, which advances the memory access 
	//	to be the next integer sized slot of data accessing the 1th value in the array.
	powersOf2.elems[1] = 2 * powersOf2.elems[0];
	powersOf2.elems[2] = 2 * powersOf2.elems[1];

	// This frees all of the memory associated with elems.
	free(powersOf2.elems);
	
	return 0;
}
// Dylan Nelson
// October 01, 2025
// ArrayTemplate\\main.cpp

#include <iostream>

template<class Type>
class Array {
public:
	Array();
	~Array();
	void setSize(size_t value);
	size_t getSize() const;
	void setElem(size_t index, Type Value);
	Type getElem(size_t index) const;
	void printArray() const;

private:
	Type* elems;
	size_t numElems;
};

template<class Type> 
Array<Type>::Array() : elems(nullptr), numElems(0) {
	setSize(0);
}

template<class Type>
Array<Type>::~Array() {
	delete[] elems;
}

template<class Type>
void Array<Type>::setElem(size_t index, Type value) {
	if (index >= numElems) throw std::out_of_range("Index out of bounds");
	elems[index] = value;
}

template<class Type>
size_t Array<Type>::getSize() const {
	return numElems;
}

template<class Type>
Type Array<Type>::getElem(size_t index) const {
	if (index >= numElems) throw std::out_of_range("Index out of bounds");
	return elems[index];
}

template<class Type>
void Array<Type>::setSize(size_t value) {
	delete[] elems;
	numElems = value;
	elems = (value > 0) ? new Type[value] : nullptr;
}

template<class Type>
void Array<Type>::printArray() const {

	for (size_t i = 0; i < getSize(); ++i) {
		std::cout << "Element " << i << ": " << getElem(i) << std::endl;
	}

}

int main() {

	Array<int> myArray;
	myArray.setSize(5);

	for (size_t i = 0; i < myArray.getSize(); ++i) {
		myArray.setElem(i, static_cast<int>(i * 10));
	}

	myArray.printArray();

	return 0;
}
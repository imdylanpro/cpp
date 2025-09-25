// Dylan Nelson
// September 24, 2025
// main.cpp

#include <iostream>;

// Vehicle is purely declared, nothing implemented.
class Vehicle {
public:
	Vehicle(int y, double m);
	~Vehicle();
	void startVehicle();
	const char* gasType();
	std::string brandName();
	int getYear();
	double getMiles();
	void setMiles(int i);
private:
	int year;
	double miles;
};

// Now the member functions can be implemented.
void Vehicle::startVehicle() {
	std::cout << "*Rumble*" << std::endl;
}

const char* Vehicle::gasType() {
	return "Diesel";
}

std::string Vehicle::brandName() {
	return "Mazda";
}

int Vehicle::getYear() {
	return this->year;
}

double Vehicle::getMiles() {
	return miles;
}

void Vehicle::setMiles(int i) {
	miles = i;
}

// Define the constructor using an initializer list.
Vehicle::Vehicle(int y, double m) : year(y), miles(m) {}

/* // This is also valid.
Vehicle::Vehicle(int y, double m) {
	this->year = y;
	this->miles = m;
}
*/

// Even though there is nothing needed for the destructor, it still needs to be 
//	implemented as it is defined in the class declaration. Here it is implemented 
//	as an empty member fucntion, which is fine.
Vehicle::~Vehicle() {}

int main() {
	
	Vehicle car = Vehicle(2020, 1234.56);

	std::cout << "Car brand: " << car.brandName() << std::endl;
	std::cout << "Car gas type: " << car.gasType() << std::endl;
	std::cout << "Starting car: "; 
	car.startVehicle();
	std::cout << "The car is a " << car.getYear() << " " << car.brandName() << " with " << car.getMiles() << " miles.";
	
	return 0;
}
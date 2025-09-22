// Dylan Nelson
// September 22, 2025
// FriendClass.cpp

#include <iostream>

using namespace std;

class Citizen {
	// Sets government as a friend class. This allows government to access private member values.
	friend class Government;

public:
	// Constructor, sets savings and sn to 0 by default unless supplied with values.
	Citizen(string n, int i, int s=0, int sn = 0) {
		name = n;
		age = i;
		savings = s;
		ssn = sn;
	}

	int getAge() {
		return age;
	}

	string getName() {
		return name;
	}

private:
	string name;
	int age;
	int ssn;
	int savings;

	int getSSN() {
		return ssn;
	}

	int getSavings() {
		return savings;
	}

	void setSSN(int s) {
		ssn = s;
	}
	
	void setSavings(double s) {
		savings = s;
	}

	void setName(string n) {
		name = n;
	}

	void setAge(int a) {
		age = a;
	}
};

class Government {
public:
	void printCitizenInformation(Citizen c) {
		cout << "Citizen name: " << c.getName() << endl;
		cout << "Citizen age: " << c.getAge() << endl;
		cout << "Citizen Social Security Number: " << c.getSSN() << endl;
		cout << "Citizen Savings: " << c.getSavings() << endl;
	}

	void taxCitizen(Citizen& c) {
		//				   ^ Utilize pass-by-reference to pass the actual citizen object in.
		double taxAmount, newSavings;
		double taxPercent = .2;

		// Take the citizens money.
		taxAmount = c.getSavings() * taxPercent; // Take 20% of the citizens money.
		cout << "Taxing " << c.getName() << " by " << taxPercent * 100 << "%." << endl;
		taxCollections += taxAmount;
		cout << taxAmount << " added to tax collections." << endl;
		
		newSavings = c.getSavings() - taxAmount;
		c.setSavings(newSavings);
		cout << "Savings after taxing: " << c.getSavings() << endl;

	}

private:
	double taxCollections = 0;
};

int main() {

	// Create objects.
	Citizen citizen1 = Citizen("Michael", 34, 1000, 123456789);
	Government USGovernment = Government();

	// Print out citizens private information.
	USGovernment.printCitizenInformation(citizen1);

	// Tax the citizen.
	USGovernment.taxCitizen(citizen1);

	// Print out private info.
	USGovernment.printCitizenInformation(citizen1);
}
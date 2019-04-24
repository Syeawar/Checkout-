#include "person.h"
/*string firstName;
	string lastName;
	int    cardID;
	bool   active;*/
Person::Person(int cardNo, bool act, string fName, string lName) {
	firstName = fName;
	lastName = lName;
	cardID = cardNo;
	active = act;
}

string Person::getFirstName() {
	return firstName;
}

string Person::getLastName() {
	return lastName;
		
}

int Person::getId() {
	return cardID;
}

void Person::setActive(bool act) {
	active = act;
} 

bool Person::isActive() {
	if (active == true) {
		return true;
	}
	else {
		return false;
	}
}

string Person::fullName() {
	return firstName + "" + lastName;
}

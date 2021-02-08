/*
 * Person.cpp
 *
 *  Created on: 11 Jul 2014
 *      Author: johnwpurcell
 */

#include "Person.h"
#include <sstream>


Person::Person() {
	name = "George";

}

/// ////////////////////
Person::Person(string newName, int newAge) {
	name = newName;
	age = newAge;
}
/// ///////////

/*
string Person::toString() {
	return "Person's name is: " + name;
}
*/
// stringstream
string Person::toString() {
	stringstream ss;
	ss << "Name: ";
	ss << name;
	ss << "; age: ";
	ss << age;

	return ss.str(); //!!
}


/*
void Person::setName(string newName) {
	name = newName;
}

string Person::getName() {
	return name;
}
*/
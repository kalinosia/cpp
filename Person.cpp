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
	age = 0;
}

/// 
/*Usuñ t¹ linikê, usuñ #3
Person::Person(string newName, int newAge) {
	name = newName;
	age = newAge;
}
/// *///////////
///#3 SAME UP 
Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
	cout << "Memory location: " << this << endl;
}
/// #3
/*
* LUB WOGÓLE MO¯NA TO ROZWI¥ZAÆ TAK!
Person::Person(string name, int age): name(name), age(age){
}
LUB
Person::Person(): name("unnamed), age(0){
}
!!!!!!
*/








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
#pragma once
/*
 * Person.h
 *
 *  Created on: 11 Jul 2014
 *      Author: johnwpurcell
 */


#include <iostream>

using namespace std;

class Person {
private:
	string name;

public:
	Person();
	string toString();
	void setName(string newName);
	string getName();
};


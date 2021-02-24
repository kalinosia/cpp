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
	int age;

public:
	Person();
	//LUB TUTAJ MO¯EMY INICJOWAÆ 
	//Person::Person(): name("unnamed), age(0){};
	///!!!!!
	///tak samo z drugim

	Person(string newName) { name = newName; age = 0; }//
	//#3 Person(string newName, int newAge);//
	Person(string name, int age); //#3

	string toString();
	//void setName(string newName);
	//string getName();
};


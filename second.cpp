#include <iostream>

#include "headers.h"

using namespace std;

Cat::Cat() {
	cout << "Cat created." << endl;
	//happy=true;
}
Cat::~Cat() {//NA KONIEC PROGRAMU PEWNIE ZWALNIANIE PAMIÊCI
	cout << "destroy cat" << endl;
}


void Cat::speak() {
	if (happy) {
		cout << "Meouwww!!!" << endl;
	}
	else {
		cout << "Grrry!!!" << endl;
	}
	if (hungry) {
		cout << "Hungry!" << endl;
	}
}

void Cat::jump() {
	cout << "Jumping to top of bookcase" << endl;
}

void Cat::feed() {
	hungry = false;
}
void Cat::hunger() {
	hungry = true;
}

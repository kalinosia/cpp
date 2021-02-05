#include <iostream>

#include "headers.h"

using namespace std;

int main() {
	{
		Cat cat3;
		cat3.happy = true;
		cat3.feed();
		cat3.speak();
		cat3.jump();
	}

	Cat cat1;
	cat1.happy = false;
	cat1.hunger();
	cat1.speak();
	cat1.jump();

	Cat catBob;
	catBob.happy = true;
	catBob.feed();
	catBob.speak();
	catBob.jump();

	{
		Cat cat3;
		cat3.happy = true;
		cat3.feed();
		cat3.speak();
		cat3.jump();
	}
}
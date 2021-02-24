#pragma once

class Cat {
private:
	bool hungry;
public:
	bool happy;
	void speak();
	void jump();

	void feed();
	void hunger();

	Cat(); //CONSTRUCTOR
	~Cat(); //DESTRUCTOR
};

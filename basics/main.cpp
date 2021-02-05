#include<iostream>
#include <iomanip> //setprecision()

#include "headers.h"

using namespace std;

//void login_pssword(); // not here a lot of headers but in other file

string ask() { //not void ! 
	string name;
	cout << "Your name is : " << flush;
	cin >> name;
	//co_return name;
	return name;
}
void yourName(string name) {
	cout << "Your name is " << endl;
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << endl;
	}
}
///////////////////////////////////////////////////////////////MAIN
int main() {

	string user = ask();
	yourName(user);
	cout << "function sizeof: " << sizeof(user) << " function .size(): " << user.size() << endl;
	
	
	/* 
	//COUT CIN FLUSH SETPRECISION() FLOAT FIXED SCIENTIFIC INT <->CHAR
	
	std::cout << "Hello world!" << std::endl;
	std::cout << "Hello world second!" << flush;
	std::cout << "Hello world third!";
	cout << "Hello world end !" << std::endl;

	float fValue = 123.456;
	double dValue = 123.456;
	long double ldValue = 123.456;

	cout << setprecision(20) << fixed << fValue << endl;
	cout << setprecision(20) << fixed << dValue << endl;
	cout << setprecision(20) << fixed << ldValue << endl;
	cout << setprecision(20) << scientific << fValue << endl;
	cout << setprecision(20) << scientific << dValue << endl;


	cout << "int: " << sizeof(int) << " float: " << sizeof(float) << " double: " << sizeof(double) << " long double: "
		<< sizeof(long double) << endl;

	bool bValue = true;
	cout << "value of true bool " << bValue << endl;

	char cValue = 7; //BELL!!!!
	char cChar = '7';
	wchar_t wcValue = '7';
	cout << "char = 7 : " << cValue << endl << "char = '7' : " << cChar << endl
		<< "int char = '7' :  " << int(cChar) << endl << "wchar_t = 7 : " << wcValue << endl;

	cout << "size od char= " << sizeof(char) << " size of wchar= " << sizeof(wchar_t) << endl;
	*/
	////////////////////////////////////////////////////////////////////////////////////////////
	/*
	//sizeof, loops
	char tekst[] = "hello";

	for (int i = 0; i < sizeof(tekst); i++) {
		cout << int(tekst[i]) << "\t"; //last will be tekst[i]==0
	}

	for (int i = 0; i < 9; i++) {
		cout << i << endl;
		if (i == 3) {
			break; //continue np. if input==password break
			cout << "break" << endl;
		}
		cout << "Go go " << i << endl;
	}

	// JE¯ELI JAKIEJŒ DANEJ NIE MA S¥ LOSOWE DANE!!! np.1643527896
	int values[3] = { 2, 3, 1 };
	double numbers[4];
	cout << numbers[2] << endl;
	int zeros[3] = {};//better
	cout << zeros[1] << endl;

	string fruits[] = { "apple", "banana", "pinapple","mango" };
	*/


	//TABLE - two dimention array
	string table[2][3] = {
		{"glass", "plate", "fork" },
		{"pad", "flowers", "cookies"}
	};
	cout << sizeof(table)<<endl;
	cout << sizeof(string) << endl;
	cout << sizeof(table) / sizeof(string) << " czy równa siê 2x3=6?" << endl;

	//cout << table[1][4]; //CA£KIEM WYKRZACZY£O KONSOLÊ WIÊC JAK SPRAWDZIÆ KIEDY KONIEC RZÊDU?
	cout << "size y: " << sizeof(table[0]) / sizeof(string) << "size of x: " << sizeof(table) / sizeof(table[0]) << endl;;
	
	
	/*
	char name[2];
	cin.get(name, 2);

	cout << "'"<< name << "'"<< endl;
	int num = int(name[0]) - 48;
	cout << num;
	*/

	//login_pssword;    //<------------
	std::cin.get();

	return 0;

}

//function 
void login_pssword() {
	string login = "Jack";
	const string password = "hello";
	string input_login;
	string input_password;

	bool loop = true;

	while (loop) {

		cout << "1.\tWrite your login." << endl;
		cout << "2.\tWrie your password" << endl;
		cout << "3.\tConfirm and check" << endl;
		cout << "4.\tEnd" << endl;
		int choise;
		cin >> choise;

		switch (choise) {
		case 1:
			cout << "Enter your login here > ";
			cin >> input_login;
			break;
		case 2:
			cout << "Enter your password here > "; //flush?
			cin >> input_password;
			break;
		case 3:
			if ((input_password == password) && (input_login == login)) {
				cout << "OK. End checking!";
				loop = false;
			}
			else if ((input_password != password) || (input_login != login)) {
				cout << "Login or password is incorrect! Change date." << endl;
			}
			else {
				cout << "Incorrect date. Try change something." << endl;
			}
			break;
		case 4:
			loop = false;
			break;
		default:
			cout << "Incorrect choise" << endl;
		}
	}
}

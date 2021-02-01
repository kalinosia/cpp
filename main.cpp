#include<iostream>
#include <iomanip> //setprecision()
using namespace std;

int main() {
	std::cout << "Hello world!" << std::endl;
	std::cout << "Hello world second!" << flush;
	std::cout << "Hello world third!" ;
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
		<< sizeof(long double) <<endl;

	bool bValue = true;
	cout << "value of true bool " << bValue << endl;

	char cValue = 7; //BELL!!!!
	char cChar = '7';
	wchar_t wcValue = '7';
	cout << "char = 7 : " << cValue  << endl << "char = '7' : " << cChar << endl 
		<<"int char = '7' :  " << int(cChar) << endl << "wchar_t = 7 : " << wcValue << endl;
	
	cout << "size od char= " << sizeof(char) << " size of wchar= " << sizeof(wchar_t) << endl;
	
	std::cin.get();
	
	return 0;
}
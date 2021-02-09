#include<iostream>
#include <iomanip> //setprecision()



using namespace std;

void manipulatonValue(double value) {
	cout << "FUNCTION Value before manipulation: " << value << endl;
	value = 10;
	cout << "FUNCTION Value after manipulation: " << value << endl;
}
void manipulatonValuePointer(double *value) {
	cout << "FUNCTION Value before manipulation: " << *value << endl;
	*value = 10;
	cout << "FUNCTION Value after manipulation: " << *value << endl;
}
///////////////////////////////////////////////////////////////MAIN
int main() {

	int nValue = 8;
	int* pnValue = &nValue;
	cout << "Value: " << nValue << endl<< 
		" Pointer value=place value: " << pnValue <<endl<<
		" Pointer place value: "<< &pnValue<<endl;
	cout << "*pointer=value of point value: " << *pnValue << endl;
	cout << "&nValue: " << &nValue << endl;

	
	cout << "=========================================" << endl;
	double value = 123.4;
	cout << "value begin: " << value << endl;
	manipulatonValue(value);
	cout << "value after function: " << value << endl;

	cout << "=========================================" << endl;
	double pvalue = 123.4;
	cout << "value begin: " << pvalue << endl;
	manipulatonValuePointer(&pvalue);
	cout << "value after function: " << pvalue << endl;

	return 0;
}
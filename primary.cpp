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
		" Pointer value=place value(pointer): " << pnValue <<endl<<
		" Pointer place value(&pointer): "<< &pnValue<<endl;
	cout << "*pointer=value of point value(*pointer): " << *pnValue << endl;
	cout << "&nValue: " << &nValue << endl;
	cout << "--------------------------------------------------" << endl;

	string texts[] = { "one", "two", "three" };
	string* pTexts = texts;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++) {
		cout << pTexts[i] << flush;
	}
	cout << endl<<"--------------"<<endl;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++, pTexts++) {
		cout << *pTexts << endl;
		//pTexts++;
		cout << pTexts << endl;
	}

	cout << "-----------------------------------------------" << endl;

	//texts[0].size();
	string* pElement = &texts[0];
	string* endElement = &texts[sizeof(texts)/sizeof(texts[0])-1]; 

	while (true) {
		cout << *pElement << " " << flush;
		if (pElement == endElement) {
			cout << endl;
			break;
		}
		pElement++;
	}





	cout << endl << "===================================================" << endl << endl;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	
	cout << "--------------------------------------------------" << endl;
	double value = 123.4;
	cout << "value begin: " << value << endl;
	manipulatonValue(value);
	cout << "value after function: " << value << endl;

	cout << "=========================================" << endl;
	double pvalue = 123.4;
	cout << "value begin: " << pvalue << endl;
	manipulatonValuePointer(&pvalue);
	cout << "value after function: " << pvalue << endl;
	//===========================================================================
	//ARITHMIC
	double value1 = 7 / 2;
	double vaule2 = 7 / 2.0;
	double value3 = (double)7 / 2;
	int value4 = 15 % 3;
	value4 += 1;
	value4 /= 3;
	cout << "-------------------------------------------" << endl;
	int seconds = 247678;
	int input_sec = seconds;
	int minutes = seconds / 60;
	seconds = seconds - minutes*60;
	int hours = minutes / 60;
	minutes = minutes - hours * 60;
	cout << input_sec << " sec = " << hours << ":" << minutes << ":" << seconds<<endl;
	cout << "-------------------------------------------" << endl;
/*
	for (int i = 0; i < 10000; i++) {
		if (i - ((i / 100) * 100) == 0){ //(i%100 == 0)
			cout << i << flush; //i=="."
		}
	}
	cout << endl;
*/
	for (int i = 0; i < 10000; i++) {
		if (i%100 == 0){
			cout << "." << flush; 
		}
	}
	cout << endl;
	cout << "-------------------------------------------" << endl;
	//mod %
	int x = 5;
	int y = 2;
	cout << "x%y: " << x % y << " y%x: " << y % x << endl;
	cout << "-------------------------------------------" << endl;

	return 0;
}
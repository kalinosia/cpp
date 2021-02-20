#include<iostream>
#include <iomanip> //setprecision()



using namespace std;
//--------------------------------------------------------------------
//pointer and change oryginal value
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
//-------------------------------------------------------------------
//reference and changing oryginal value
void changeSomething(double& value) {
	value = 123.4;
}//USE: changeSomething(value);!!!!!!!!!!!!!!!!!!!
//----------------------------------------------------------------ANIMAL
//class and const.
class Animal {
private:
	string name;

public:
	Animal() { cout << "Animal created. Constructor." << endl; }//not have that one when copy animal2
	Animal(const Animal& other) :name(other.name) { /*other.speak();*/ cout << "Animal created by coping. Copy constr." << endl; }
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is: " << name << endl; }
};
//-----------------------------------------------------------------------
///////////////////////////////////////////////////////////////MAIN
///////////////////////////////////////////////////////////////MAIN
int main() {
	//######################	INT		###########################
	//REFERENCE
	int valueOne = 8;
	int valueTwo = valueOne;
	int& valueThree = valueOne;
	valueTwo = 10;//this not change value one, only value two
	valueThree = 12;//this change valueOne
	
	//function with change value without return
	//everithing normal but in declatation &!!
	//vloid changefunction(double &value){...
	//-----

	int nValue = 8;
	int* pnValue = &nValue;
	cout << "Value: " << nValue << endl<< 
		" Pointer value=place value(pointer): " << pnValue <<endl<<
		" Pointer place value(&pointer): "<< &pnValue<<endl;
	cout << "*pointer=value of point value(*pointer): " << *pnValue << endl;
	cout << "&nValue: " << &nValue << endl;
	cout << "------------------CONST.----------------------------" << endl;
	// const int * const pValue = &value;
	int* pValue = &nValue;
	cout << *pValue << endl;
	int number = 11;
	pValue = &number; // Error with this: int * const pValue = &value;
	*pValue = 12; // Error with this: const int *pValue = &value;
	cout << *pValue << endl;

	//########################################################################
	cout << "###################	DOUBLE	########################" << endl;
	double value = 123.4;
	cout << "value begin: " << value << endl;
	manipulatonValue(value);
	cout << "value after function: " << value << endl;
	cout << "---------------------------------------------" << endl;
	double pvalue = 123.4;
	cout << "value begin: " << pvalue << endl;
	manipulatonValuePointer(&pvalue);
	cout << "value after function: " << pvalue << endl;
	cout << "---------------------------------------------" << endl;
	//ARITHMIC
	double value1 = 7 / 2;
	double vaule2 = 7 / 2.0;
	double value3 = (double)7 / 2;
	int value4 = 15 % 3;
	value4 += 1;
	value4 /= 3;
	//########################################################################
	cout<<"###################	CHAR	########################"<<endl;
	char text[] = "hello";
	for (int i = 0; i < sizeof(text); i++) {
		cout << i << ": " << text[i] << endl;
	}
	cout << "---------------------------------------------" << endl;
	int k = 0;
	while (text[k] != 0) {
		cout << text[k] << flush;
		k++;
	}
	cout << endl;
	cout << "----------	REVERSING STRING <char>	-------------" << endl;
	
	char* pStart = text;
	char* pEnd = text + sizeof(text) - 1 -1; //-1 because start 0 not 1, -1 because size end /0 not in end of text

	while (pStart < pEnd) {
		char save = *pStart;
		//cout << save <<" " <<pStart<<" "<<pEnd<<endl;//why only two times?
		*pStart = *pEnd;
		*pEnd = save;
		//cout << save << " " << pStart << " " << pEnd << endl;//why only two times?
		pStart++;
		pEnd--;
	}
	cout << text << endl;

	//########################################################################
	cout<<"#####################		STRING	####################"<<endl;
	string texts[] = { "one", "two", "three" };
	string* pTexts = texts;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++) {
		cout << pTexts[i] << flush;
	}
	cout << endl<<"---------------------------------"<<endl;
	for (int i = 0; i < sizeof(texts) / sizeof(string); i++, pTexts++) {
		cout << *pTexts << endl;
		//pTexts++;
		cout << pTexts << endl;
	}
	cout << "------------------------------------" << endl;

	//texts[0].size();
	string* pElement = &texts[0]; //deklaracja konkretnego elementu w tablicy to adres czyli z &, deklaracja tablicy bez &!!!!!!!!!!!!!!!!!!
	string* endElement = &texts[sizeof(texts)/sizeof(texts[0])-1]; 

	while (true) {
		cout << *pElement << " " << flush;
		if (pElement == endElement) {
			cout << endl;
			break;
		}
		pElement++;
	}





	//##################	FUNCTION, exercise	#######################
	cout << endl << "=======================	FUNCT	==========================" << endl << endl;
	int seconds = 247678;
	int input_sec = seconds;
	int minutes = seconds / 60;
	seconds = seconds - minutes*60;
	int hours = minutes / 60;
	minutes = minutes - hours * 60;
	cout << input_sec << " sec = " << hours << ":" << minutes << ":" << seconds<<endl;

	cout << "----------------	MOD	---------------------------" << endl;
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
	cout << "------------------MOd-------------------------" << endl;
	//mod %
	int x = 5;
	int y = 2;
	cout << "x%y: " << x % y << " y%x: " << y % x << endl;
	cout << "-------------------------------------------" << endl;

	cout << "===================================================" << endl;


	//+++++++++++++++++++CLASSES+++++++++++++++++++++++++++++++
	cout << "======================== CLASS =======================" << endl;

	Animal animal1;
	animal1.setName("Freddy");
	Animal animal2 = animal1;	//name=Freddy when constructor, name="", when add :name(other.name)-Freddy back
	animal2.speak();
	animal2.setName("Bob");	//change name a2
	animal1.speak();
	animal2.speak();
	Animal animal3(animal1);
	animal3.speak();

	//------------------------------------
	char c = 'a';
	c++;
	string wale(5, c);
	cout << wale << endl;
	return 0;
}
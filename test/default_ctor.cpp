#include <iostream>
#include <cstring>
using namespace std;

class Word {
private:
	int frequency; char* str;
	void set(int f, const char* s) { frequency = f; str = new char [strlen(s)+1]; strcpy(str, s); }
public:
	Word(const char* s, int k = 1) { set(k, s); cout << "\nImplicit const char* conversion\n"; }
	Word(const Word& w) { set(w.frequency, w.str); cout << "\nCopy\n"; }
	Word() {set(0, "d"); cout << "default\n";}
	void print() const { cout << str << " : " << frequency << " ; " 
		<< reinterpret_cast<void*>(str) << endl; } // Also prints the address of object’s str array
};

int main() {
	//Word w0();	// function declaration with name "w0" and return type Word
	Word w1{};	// initialize with default constructor
	Word w2;	// initialize with default constructor

    //w0.print(); // Compilation Error: request for member 'print' in 'w0', which is of non-class type 'Word ()'
	w1.print();
	w2.print();
}

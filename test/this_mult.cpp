#include <iostream>

using namespace std;

class A {
public:
	A* print_this() { return this; }
	// A* print_this_mult(int n) { return this * n; }
	A* print_this_mult(int n) { return reinterpret_cast<A*>(reinterpret_cast<int>(this) * n); }
};

int main() {
	A a;
	cout << a.print_this() << endl;
	cout << a.print_this_mult(2) << endl;
}
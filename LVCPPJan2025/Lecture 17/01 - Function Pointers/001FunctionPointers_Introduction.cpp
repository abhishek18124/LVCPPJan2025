#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << " " << (void*)greet << endl;
	cout << (void*)&add << " " << (void*)add << endl;
	cout << (void*)&ascending << " " << (void*)ascending << endl;

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	greet();
	(*gptr)();
	gptr();
	(*greet)();

	cout << add(5, 7) << endl;
	cout << (*add)(5, 7) << endl;
	cout << (*aptr)(5, 7) << endl;
	cout << aptr(5, 7) << endl;

	cout << ascending(10, 5) << endl;
	cout << (*ascending)(10, 5) << endl;
	cout << (*ascptr)(10, 5) << endl;
	cout << ascptr(10, 5) << endl;

	return 0;
}
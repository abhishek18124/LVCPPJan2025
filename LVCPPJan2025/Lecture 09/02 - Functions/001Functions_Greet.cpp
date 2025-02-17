#include<iostream>

using namespace std;

void greet() {

	cout << "hi" << endl;
	return; // optional

}

int main() {

	cout << "I am inside the main(), before greet()" << endl;

	greet(); // fn call / invocation

	cout << "I am inside the main(), after greet()" << endl;

	return 0;
}
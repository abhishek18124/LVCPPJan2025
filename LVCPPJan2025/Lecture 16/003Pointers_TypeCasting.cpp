#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	int* ptr = (int*)&ch;
	// cout << &ch << endl;
	cout << ptr << endl;

	return 0;
}
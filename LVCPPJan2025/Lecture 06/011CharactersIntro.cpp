#include<iostream>

using namespace std;

int main() {


	char ch1 = 'A';
	cout << ch1 << endl;
	cout << (int)ch1 << endl;

	char ch2 = 'z';
	cout << ch2 << endl;
	cout << (int)ch2 << endl;

	char ch3 = 'B';
	ch3++;
	cout << ch3 << endl;

	char ch4 = 'x';
	cout << ch4 << endl;
	cout << (int)ch4 << endl;
	ch4--;
	cout << ch4 << endl;
	cout << (int)ch4 << endl;

	char ch5 = '7';
	cout << ch5 << endl;
	cout << (int)ch5 << endl;
	cout << ch5 - '0' << endl;

	int x = ch5 - '0';
	cout << x << endl;

	// int y = (int)ch5;
	// cout << y << endl;

	return 0;
}
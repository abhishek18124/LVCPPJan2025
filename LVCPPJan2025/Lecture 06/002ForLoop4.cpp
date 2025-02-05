#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 0;

	for (; i < n; i++) {
		cout << i << " ";
	}

	cout << endl;

	cout << i << endl; // error, i is out of scope

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << i << " ";
	}

	cout << endl;

	cout << i << endl; // error, i is out of scope

	return 0;
}
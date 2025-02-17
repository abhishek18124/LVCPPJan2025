#include<iostream>

using namespace std;

// bool isEven(int n) {

// 	if (n % 2 == 0) {
// 		return true;
// 	} else {
// 		return false;
// 	}

// }

// bool isEven(int n) {

// 	if (n % 2 == 0) {
// 		return true;
// 	}

// 	return false;

// }

// bool isEven(int n) {

// 	return n % 2 == 0 ? true : false;

// }

bool isEven(int n) {

	return n % 2 == 0;

}

int main() {

	// if a fn call returns a value
	// you can treat that fn call
	// like an expr

	bool ans = isEven(2);

	if (ans) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	cout << isEven(5) << endl;

	if (isEven(10)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	isEven(7) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
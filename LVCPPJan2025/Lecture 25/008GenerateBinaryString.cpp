#include<iostream>

using namespace std;

string f(int n) {

	// base case

	if (n == 0) {

		// f(0) : generate the binary string for 0

		return "0";
	}

	// if(n == 1) {

	// 	// f(1) : generate the binary string for 1

	// 	return "1";

	// }

	// recursive case

	// f(n) : generate the binary string for n

	// 1. ask your friend to generate the binary string for n/2

	string binaryStringFromMyFriend = f(n / 2);

	return binaryStringFromMyFriend + to_string(n % 2);

}

int main() {

	int n = 20;

	cout << f(n) << endl;

	return 0;
}
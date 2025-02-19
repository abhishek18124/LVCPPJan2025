#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int rn = sqrt(n);
	for (int i = 2; i <= rn; i++) {
		if (n % i == 0) {
			// you've found a factor of n in the range [2, rn]
			return false;
		}
	}

	return true; // n is prime

}

/*

adv. of fn

1. reability will improve
2. code becomes modular so debuggin becomes easier
3. reusuability

*/

void printPrimes(int m) { // time : m^(3/2)

	for (int n = 2; n <= m; n++) {

		// check if n is prime or not

		if (isPrime(n)) {
			cout << n << " ";
		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}
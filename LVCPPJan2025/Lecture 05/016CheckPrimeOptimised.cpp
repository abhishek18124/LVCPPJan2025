#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;

	while (i <= sqrt(n)) { // i * i <= n

		if (n % i == 0) {

			// you've found a factor of n in the range [2, n-1] therefore n is a composite i.e. not a prime no.

			cout << "not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i > sqrt(n)) {
		cout << "prime" << endl;
	}

	return 0;
}
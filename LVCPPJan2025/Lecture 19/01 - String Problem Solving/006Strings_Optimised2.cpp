#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "ababbaab";
	int n = str.size();

	// time : O(n)
	// space: O(1)

	int rudeness = 0;
	int cnt_b = 0; // to track no. of b's we've seen in the suffix scanned so far
	for (int i = n - 1; i >= 0; i--) {
		char ch = str[i];
		if (ch == 'a') {
			// find out no. of b's in str[i+1...n-1]
			rudeness += cnt_b;
		} else {
			// ch == 'b'
			cnt_b++;
		}
	}

	cout << rudeness << endl;


	return 0;
}
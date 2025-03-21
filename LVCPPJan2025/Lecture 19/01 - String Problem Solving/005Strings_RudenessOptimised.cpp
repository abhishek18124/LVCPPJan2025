#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

	string str = "ababbaab";
	int n = str.size();

	// time : O(n)
	// space: O(n)

	vector<int> suffixBCnt(n + 1);
	suffixBCnt[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		suffixBCnt[i] = suffixBCnt[i + 1] + (str[i] == 'b' ? 1 : 0);
	}

	for (int i = 0; i < n; i++) {
		cout << suffixBCnt[i] << " ";
	}

	cout << endl;

	int rudeness = 0;
	for (int i = 0; i < n; i++) {
		char ch = str[i];
		if (ch == 'a') {
			// find out no. of b's in str[i+1...n-1] using suffixBCnt[]
			rudeness += suffixBCnt[i + 1];
		}
	}

	cout << rudeness << endl;

	return 0;
}
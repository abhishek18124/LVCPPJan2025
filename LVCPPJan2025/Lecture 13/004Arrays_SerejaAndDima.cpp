#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	bool serejaTurn = true;

	int i = 0;
	int j = n - 1;

	while (i <= j) {

		if (serejaTurn) { // its Sereja's turn

			if (v[i] > v[j]) {

				// Sereja will pick ith card

				serejaScore += v[i];
				i++;

			} else {

				// Sereja will pick jth card

				serejaScore += v[j];
				j--;

			}

			serejaTurn = false;

		} else { // its Dima's turn

			if (v[i] > v[j]) {

				// Dima will pick ith card

				dimaScore += v[i];
				i++;

			} else {

				// Dima will pick jth card

				dimaScore += v[j];
				j--;

			}

			serejaTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}
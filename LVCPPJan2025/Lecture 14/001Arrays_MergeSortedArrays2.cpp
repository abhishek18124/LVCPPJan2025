#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> a = {10, 30, 50, 70};
	vector<int> b = {20, 40, 60};

	int n = a.size();
	int m = b.size();

	// time : O(n+m)

	vector<int> c;

	int i = 0; // to iterate over a[]
	int j = 0; // to iterate over b[]

	while (i <= n - 1 and j <= m - 1) {

		if (a[i] < b[j]) {

			c.push_back(a[i]);
			i++;

		} else {

			c.push_back(b[j]);
			j++;

		}

	}

	while (i <= n - 1) {

		c.push_back(a[i]);
		i++;

	}

	while (j <= m - 1) {

		c.push_back(b[j]);
		j++;

	}

	for (int x : c) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}


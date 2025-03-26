#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<vector<int>> v;

	// int m, n;
	// cin >> m >> n;

	// vector<vector<int>> v(m, vector<int>(n));
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cin >> v[i][j];
	// 	}
	// }

	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << v.size() << endl;
	// cout << v[0].size() << endl;

	vector<vector<int>> v = {
		{10, 15, 20, 25},
		{30, 35, 40, 45},
		{50, 55, 60, 65}
	};

	int m = v.size(); // # rows
	int n = v[0].size(); // # cols

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
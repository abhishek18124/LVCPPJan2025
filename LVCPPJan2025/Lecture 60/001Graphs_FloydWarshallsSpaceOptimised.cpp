/*

note : nodes are numbered from 1 to n

floyd-warshall's algorithm

e.g.

input :

4 5
1 2 8
1 3 1
1 4 5
2 4 2
3 4 3

output :

0 6	1 4
6 0	5 2
1 5	0 3
4 2	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges; // we are representing each edge using a 3-sized vector

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
		// edges.push_back({v, u, w}); // comment this out if graph is directed
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));


	for (vector<int> e : edges) {
		int i = e[0];
		int j = e[1];
		int w = e[2];
		dp[i][j] = min(dp[i][j], w); // min() ensures we choose the best edge i.e. least cost edge b/w i and j
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0; // dist b/w node i and itself is zero
	}

	// at this point dp[i][j] represents dp[i][j][0]

	// time : O(n^3)
	// space: O(n^2)

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j],
				               dp[i][k] + dp[k][j]);
			}
		}
	}

	// at this point dp[i][j] represents dp[i][j][n]

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 1; i <= n; i++) {
		if (dp[i][i] < 0) {
			// dist b/w node i to itself is -ve
			cout << "negative weight cycle found" << endl;
			break;
		}
	}

	return 0;
}
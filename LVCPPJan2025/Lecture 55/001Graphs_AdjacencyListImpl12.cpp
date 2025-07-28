/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (1 <= u, v <= n) where u, v are edge endpoints .

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1); // 0th index is not used

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	for (int i = 1; i <= n; i++) {
		cout << "ngb(" << i << ") = ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}
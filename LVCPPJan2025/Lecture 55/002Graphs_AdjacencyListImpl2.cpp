/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (0 <= u, v < n) where u, v are edge endpoints .

input :

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<set<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u); // comment this out if graph is directed
	}


	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") = ";
		set<int> ngblist = adj[i];
		for (int ngb : ngblist) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "ngb(" << i << ") = ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	// for (int i = 0; i < n; i++) {
	// 	cout << "ngb(" << i << ") = ";
	// 	for (auto& ngb : adj[i]) {
	// 		cout << ngb << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;


	return 0;

}
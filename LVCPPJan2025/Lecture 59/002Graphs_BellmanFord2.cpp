/*

note : nodes are numbered from 0 to n - 1

bellman-ford's algorithm

e.g.

input :

5 7
0 1 2
0 2 5
1 2 1
1 3 6
1 4 4
2 4 1
4 3 1

output :

0 2 3 5 4

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
		edges.push_back({u, v, w}); // u to v is directed edge of weight w
	}

	// time : (V-1)E.const ~ O(VE)
	// space: O(V) for prev[] and cur[]

	int src = 0; // assume node 0 is the src node

	vector<int> prev(n, INF);
	prev[src] = 0;

	for (int i = 1; i <= n - 1; i++) {

		// do ith round of relaxations

		vector<int> cur = prev;

		for (vector<int> e : edges) {
			int u = e[0];
			int v = e[1];
			int w = e[2];
			if (prev[u] != INF and cur[v] > prev[u] + w) { // prev != INF makes sure we avoid integer overflow while doing prev[u] + w
				// edge from u to v is tensed
				cur[v] = prev[u] + w; // const
			}
		}

		prev = cur;

	}

	// do one more round of relaxation

	vector<int> cur = prev;

	for (vector<int> e : edges) {
		int u = e[0];
		int v = e[1];
		int w = e[2];
		if (prev[u] != INF and cur[v] > prev[u] + w) {
			cout << "negative weight cycle found" << endl;
			exit(0);
		}
	}

	// prev stores result of the last round of relaxation

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << prev[i] << endl;
	}

	cout << endl;

	return 0;
}
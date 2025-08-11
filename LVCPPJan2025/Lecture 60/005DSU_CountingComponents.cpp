/*

counting no. of componenets in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 7

1 2
1 4
2 3
3 4
5 6
6 7

output :

2

*/

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

public:

	vector<int> parMap; // map that encodes the disjoint forest
	vector<int> rankMap; // map that encodes rank of each tree in the disjoint forest

	disjointSet(int n) {
		parMap.resize(n + 1);
		rankMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		rankMap[x] = 0;
	}

	int findSet(int x) {
		// base case
		if (parMap[x] == x) {
			return x;
		}

		// recurive case
		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) { // union by rank

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (rankMap[lx] == rankMap[ly]) {
				rankMap[lx]++;
			}

			if (rankMap[lx] > rankMap[ly]) {
				parMap[ly] = lx;
			} else {
				// rankMap[lx] < rankMap[ly]
				parMap[lx] = ly;
			}

		}
	}

};



int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges; // each edge can be represented by a 2-sized vector
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) { // O(V)
		ds.createSet(i);
	}

	int numComponents = n;

	for (vector<int> e : edges) { // O(E)
		int u = e[0];
		int v = e[1];
		if (ds.findSet(u) != ds.findSet(v)) {
			ds.unionSet(u, v);
			numComponents--;
		}
	}

	cout << numComponents << endl;

	// time : O(V+E)
	// space: O(V) due to disjointSet

	return 0;
}
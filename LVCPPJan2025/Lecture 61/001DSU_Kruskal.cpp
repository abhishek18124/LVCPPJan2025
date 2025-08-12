/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<algorithm>

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

	vector<vector<int>> edges; // each edge is represented by a 3-sized vector
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	// time : O(ElogE)
	// space: O(V) due to disjointSet

	// time for sorting : ElogE ~ O(ElogE)

	sort(edges.begin(), edges.end()); // by default sorting is done based on element at the 0th index of  the vector<>, here that element is edge weight

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	// time for picking safe edge : E.const ~ O(E)

	int mstSum = 0;
	vector<vector<int>> ans;
	for (vector<int> e : edges) {
		int w = e[0];
		int u = e[1];
		int v = e[2];
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge
			mstSum += w;
			ds.unionSet(u, v);
			ans.push_back(e);
			if (ans.size() == n - 1) {
				break;
			}
		}
	}

	for (vector<int> e : ans) {
		int w = e[0];
		int u = e[1];
		int v = e[2];
		cout << u << " " << v << " : " << w << endl;
	}

	cout << mstSum << endl;

	return 0;
}
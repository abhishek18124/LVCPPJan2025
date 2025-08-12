/*

prims algorithm

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
#include<set>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	int src = 1; // assume node 1 is the src

	set<pair<int, int>> minHeap; // set<{wt, node}>
	minHeap.insert({0, src}); // cost to entre src is zero

	vector<bool> inMST(n + 1, false);

	// time : O(ElogE)
	// space: O(V) due to inMST and O(E) due to minHeap ~ O(E) assuming E > V

	int mstSum = 0;

	while (!minHeap.empty()) {

		// cout << ".";

		// pair<int, int> p = *minHeap.begin();
		// int wt = p.first;
		// int cur = p.second;

		auto [wt, cur] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		if (inMST[cur]) continue; // cur is already in MST so need to iterate over its ngbs

		inMST[cur] = true;
		mstSum += wt;

		for (auto [ngb, edgeWt] : adj[cur]) {
			if (!inMST[ngb]) {
				minHeap.insert({edgeWt, ngb});
			}
		}

	}

	cout << mstSum << endl;

	return 0;
}
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

const int INF = 1e9;

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

	vector<int> bestCostToEnter(n + 1, INF);
	bestCostToEnter[src] = 0;

	int mstSum = 0;

	// time : O(ElogV)
	// space: V due to inMST, V due to bestCostToEnter, V due minHeap ~ O(V)

	while (!minHeap.empty()) {

		// cout << ".";

		auto [wt, cur] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		// if (inMST[cur]) continue; // no longer needed since we make a single entry for each node in the minHeap

		inMST[cur] = true;
		mstSum += wt;

		for (auto [ngb, edgeWgt] : adj[cur]) {
			if (!inMST[ngb] and edgeWgt < bestCostToEnter[ngb]) {
				minHeap.erase({bestCostToEnter[ngb], ngb});
				minHeap.insert({edgeWgt, ngb});
				bestCostToEnter[ngb] = edgeWgt;
			}
		}

	}

	cout << mstSum << endl;

	return 0;
}
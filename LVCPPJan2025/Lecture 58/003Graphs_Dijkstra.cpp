/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int src = 0; // assume node 0 to be the src vertex

	vector<int> distMap(n, INF);
	distMap[src] = 0;

	vector<bool> ex(n, false);

	set<pair<int, int>> minHeap;
	for (int i = 0; i < n; i++) {
		minHeap.insert({distMap[i], i});
	}

	// time : O(ElogV) // each relaxation takes logV time // at max we can do E relaxation // each edge can be relaxed atmost once
	// space: O(V)

	while (!minHeap.empty()) {

		// pair<int, int> p = *minHeap.begin();
		// int dist = p.first;
		// int cur = p.second;
		// minHeap.erase(minHeap.begin());

		auto [dist, cur] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		// for(pair<int, int> pp : adj[cur]) {
		// 	int ngb = pp.first;
		// 	int edgeWgt = pp.second;
		// }

		for (auto [ngb, edgeWgt] : adj[cur]) {

			if (!ex[ngb] and distMap[ngb] > distMap[cur] + edgeWgt) {

				// relax the edge b/w cur and ngb

				auto it = minHeap.find({distMap[ngb], ngb}); // logV
				minHeap.erase(it); // logV
				distMap[ngb] = distMap[cur] + edgeWgt; // const
				minHeap.insert({distMap[ngb], ngb}); // logV

			}
		}

		ex[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << distMap[i] << endl;
	}

	cout << endl;

	return 0;
}
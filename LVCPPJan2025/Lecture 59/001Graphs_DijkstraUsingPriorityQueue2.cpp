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
#include<queue>

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

	priority_queue<pair<int, int>,
	               vector<pair<int, int>>,
	               greater<pair<int, int>>> minHeap;

	minHeap.push({distMap[src], src});

	// time : O(ElogE)

	// sparse graph E ~ V time : O(ElogV)
	// dense graph E ~ V^2 time : O(ElogV^2) ~ O(2ElogV) ~ O(ElogV)

	// space: O(E) due to minHeap

	while (!minHeap.empty()) {

		// pair<int, int> p = minHeap.top();
		// int dis_cur = p.first;
		// int cur = p.second;
		// minHeap.pop();

		auto [dis_cur, cur] = minHeap.top();
		minHeap.pop();

		if (dis_cur > distMap[cur]) continue; // dis_cur is outdated

		// for(pair<int, int> pp : adj[cur]) {
		// 	int ngb = pp.first;
		// 	int edgeWgt = pp.second;
		// }

		for (auto [ngb, edgeWgt] : adj[cur]) {

			if (distMap[ngb] > distMap[cur] + edgeWgt) {

				// relax the edge b/w cur and ngb
				distMap[ngb] = distMap[cur] + edgeWgt;
				minHeap.push({distMap[ngb], ngb});

			}

		}

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << distMap[i] << endl;
	}

	cout << endl;

	return 0;
}
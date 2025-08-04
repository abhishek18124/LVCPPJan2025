/*

Given an directed graph do its topological sorting

input :

8 14

0 1
0 2
0 3
1 3
1 4
3 2
3 4
3 5
3 6
3 7
4 6
5 2
6 7
7 5

output :

0 1 3 4 6 7 5 2

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; // u -> v is a directed edge
		adj[u].push_back(v);
	}

	vector<int> indegMap(n, 0);
	for (int i = 0; i < n; i++) {
		for (int ngb : adj[i]) {
			indegMap[ngb]++;
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "indeg(" << i << ") = " << indegMap[i] << endl;
	// }

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (indegMap[i] == 0) {
			// node i has an indeg of zero i.e.
			// node i doesn't depend on any other
			// node
			q.push(i);
		}
	}

	vector<int> ans; // to store the topological ordering for the given dag

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		// cout << cur << " ";
		ans.push_back(cur);

		for (int ngb : adj[cur]) {
			indegMap[ngb]--;
			if (indegMap[ngb] == 0) {
				q.push(ngb);
			}
		}

	}

	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;


	return 0;
}
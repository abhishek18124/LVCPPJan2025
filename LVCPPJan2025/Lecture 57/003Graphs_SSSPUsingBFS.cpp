/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> generatePath(int dst, const vector<int>& parMap) {

	vector<int> path = {dst};

	while (parMap[dst] != -1) {
		dst = parMap[dst];
		path.push_back(dst);
	}

	reverse(path.begin(), path.end());

	return path;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	vector<int> distMap(n);
	int src = 0; // assume node 0 is the src vertex

	distMap[src] = 0;

	queue<int> q;
	q.push(src);

	vector<bool> vis(n, false);
	vis[src] = true;

	vector<int> parMap(n);
	parMap[src] = -1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				// vis the ngb
				vis[ngb] = true;
				q.push(ngb);
				distMap[ngb] = distMap[cur] + 1; // since we are visiting ngb due to cur it means in the bfs tree cur is the parent of ngb
				parMap[ngb] = cur;
			}
		}

	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "dist(" << i << ") = " << distMap[i] << endl;
	// }

	// cout << endl << endl;

	// for (int i = 0; i < n; i++) {
	// 	cout << "par(" << i << ") = " << parMap[i] << endl;
	// }

	for (int i = 0; i < n; i++) {
		vector<int> path = generatePath(i, parMap);
		cout << "path(" << i << ") = ";
		for (int x : path) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
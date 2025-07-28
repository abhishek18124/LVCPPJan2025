/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v and w where u, v are edge endpoints and w is weight of the edge.

input :

5 6
A B 7
A C 1
B D 2
C D 9
C E 6
D E 5

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<char, vector<pair<char, int>>> adj;
	for (int i = 0; i < m; i++) {
		char u, v;
		cin >> u >> v;
		int w;
		cin >> w;
		adj[u].push_back({v, w}); // adj[u].push_back(make_pair(v, w));
		adj[v].push_back({u, w}); // adj[v].push_back(make_pair(u, w));
	}

	for (pair<char, vector<pair<char, int>>> p : adj) {
		char nodeLabel = p.first;
		vector<pair<char, int>> ngblist = p.second;
		cout << "ngb(" << nodeLabel << ") = ";
		for (pair<char, int> pp : ngblist) {
			char ngb = pp.first;
			int edgeWgt = pp.second;
			cout << "(" << ngb << ", " << edgeWgt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [nodeLabel, ngblist] : adj) {
		cout << "ngb(" << nodeLabel << ") = ";
		for (auto [ngb, edgeWgt] : ngblist) {
			cout << "(" << ngb << ", " << edgeWgt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}
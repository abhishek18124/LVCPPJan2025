// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// appr1 - multi-src bfs
// time : O(mn)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX)); // we are init distMat with INT_MAX to use that info. to know if a cell is vis or not otherwise we will need to create a vis[][] as well which will take more space
	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell corr. to a source node
				distMat[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};


	while (!q.empty()) {

		pair<int, int> p = q.front();
		q.pop();

		int i = p.first;
		int j = p.second;

		for (int k = 0; k < 4; k++) {

			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
				// (nx, ny) is not yet visited
				q.push({nx, ny});
				distMat[nx][ny] = distMat[i][j] + 1;
			}

		}

	}

	return distMat;


}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	vector<vector<int>> distMat = updateMatrix(mat);

	int m = distMat.size();
	int n = distMat[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << distMat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}
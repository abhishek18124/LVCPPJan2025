// https://leetcode.com/problems/n-queens/description/

class Solution {
public:

	bool isValid(vector<string>& board, int n, int r, int j) {

		// check if you can place Qr in the jth column of row 'r'

		for (int i = r - 1; i >= 0; i--) {
			if (board[i][j] == 'Q') {
				// previously place Qi is already in the jth column
				// so you cannot place Qr in the
				// jth column
				return false;
			}
		}

		int step = 1;
		for (int i = r - 1; i >= 0 and j + step < n; i--) {
			if (board[i][j + step] == 'Q') {
				// previously placed Qi is present along the right diagonal
				// of jth column therefore you cannot place Qr in the jth
				// column of row r
				return false;
			}
			step++;
		}

		step = 1;
		for (int i = r - 1; i >= 0 and j - step >= 0; i--) {
			if (board[i][j - step] == 'Q') {
				// previously placed Qi is present along the left diagonal
				// of jth column therefore you cannot place Qr in the jth
				// column of row r
				return false;
			}
			step++;
		}

		// you can place Qr in the jth column of row r
		return true;

	}

	void f(int n, int r, vector<string>& board, vector<vector<string>>& ans) {

		// base case

		if (r == n) {
			ans.push_back(board);
			return;
		}

		// recursive case

		// f(r) : take decisions for remaining queens Qr to Qn-1

		// decide for Qr

		for (int j = 0; j < n; j++) {

			// can I place Qr in the jth column of row 'r'

			if (isValid(board, n, r, j)) {
				board[r][j] = 'Q';
				f(n, r + 1, board, ans);
				board[r][j] = '.';
			}

		}

	}

	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> ans;

		vector<string> board;
		for (int i = 0; i < n; i++) {
			board.push_back(string(n, '.'));
		}

		f(n, 0, board, ans);

		return ans;
	}
};
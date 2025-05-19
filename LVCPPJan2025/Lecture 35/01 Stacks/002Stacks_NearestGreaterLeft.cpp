#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f2(vector<int> A) {

	stack<int> s; // monotonic stack
	int n = A.size();
	vector<int> ans;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			// s.top() cannot be the nearest greater element to
			// the left of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any greater element to its left
			ans.push_back(-1);
		} else {
			// s.top() is the nearest greater element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 2, 0, 4, 1, 3, 6};

	vector<int> ans = f2(A);

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
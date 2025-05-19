#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f1(vector<int> A) {

	stack<int> s; // monotonic stack
	int n = A.size();
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			// s.top() cannot be the nearest greater element to
			// the right of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any greater element to its right
			ans.push_back(-1);
		} else {
			// s.top() is the nearest greater element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f1(A);

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
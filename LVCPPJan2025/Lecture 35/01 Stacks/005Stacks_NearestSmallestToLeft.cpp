#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f2(vector<int> A) {

	stack<int> s; // monotonic stack // <index>
	int n = A.size();
	vector<int> ans;

	for (int i = 0; i <= n - 1; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			// A[s.top()] cannot be the nearest smaller element to
			// the left of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller element to its left
			ans.push_back(-1);
		} else {
			//  A[s.top()] is the nearest smaller element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {0, 3, 5, 4, 1, 6, 2};

	vector<int> ans = f2(A);
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
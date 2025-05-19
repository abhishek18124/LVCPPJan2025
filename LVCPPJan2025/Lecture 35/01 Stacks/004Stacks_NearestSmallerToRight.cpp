#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f1(vector<int> A) {

	stack<int> s; // monotonic stack // <index>
	int n = A.size();
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			// A[s.top()] cannot be the nearest smaller element to
			// the right of A[i] so we can safely pop them
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any smaller element to its right
			ans.push_back(n);
		} else {
			//  A[s.top()] is the nearest smaller element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}


int main() {

	vector<int> A = {2, 5, 1, 3, 6, 4, 0};

	vector<int> ans = f1(A);
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
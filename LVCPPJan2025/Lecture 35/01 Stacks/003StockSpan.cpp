#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n)

vector<int> f(vector<int> A) {

	int n = A.size();

	stack<pair<int, int>> s; // monotonic stack // <value, index>
	vector<int> ans;

	for (int i = 0; i < n; i++) {

		// find the idx of the nearest greater element to the left
		// of A[i] using monotonic stack

		while (!s.empty() and s.top().first <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// A[i] doesn't have any nearest greater element to its left
			j = -1;
		} else {
			// s.top().first is the neareset greater element to the left of A[i]
			j = s.top().second;
		}

		ans.push_back(i - j);

		s.push({A[i], i}); // s.push(make_pair(A[i], i));

	}

	return ans;

}

// time : O(n)
// space: O(n)

vector<int> ff(vector<int> A) {

	int n = A.size();

	stack<int> s; // monotonic stack // <index>
	vector<int> ans;

	for (int i = 0; i < n; i++) {

		// find the idx of the nearest greater element to the left
		// of A[i] using monotonic stack

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j;

		if (s.empty()) {
			// A[i] doesn't have any nearest greater element to its left
			j = -1;
		} else {
			// A[s.top()] is the neareset greater element to the left of A[i]
			j = s.top();
		}

		ans.push_back(i - j);

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {100, 80, 60, 70, 60, 75, 85};

	// vector<int> ans = f(A);
	vector<int> ans = ff(A);

	for (auto x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
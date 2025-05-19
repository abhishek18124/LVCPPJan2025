#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n)

vector<int> f(const vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<pair<int, int>> s; // monotonic stack // <value, index>

	for (int i = 0; i < n; i++) {

		// find out the elements for which A[i] can be the ans i.e. nearest
		// greater element to their right

		while (!s.empty() and A[i] > s.top().first) {
			// A[i] is the ans for s.top().first
			ans[s.top().second] = A[i];
			s.pop();
		}

		s.push({A[i], i});

	}

	return ans;

}

// time : O(n)
// space: O(n)

vector<int> ff(const vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<int> s; // monotonic stack // <index> // to track indices of elements for which we are yet to find the ans

	for (int i = 0; i < n; i++) {

		// find out the elements for which A[i] can be the ans i.e. nearest
		// greater element to their right

		while (!s.empty() and A[i] > A[s.top()]) {
			// A[i] is the ans for A[s.top()]
			ans[s.top()] = A[i];
			s.pop();
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = ff(A);

	for (auto x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
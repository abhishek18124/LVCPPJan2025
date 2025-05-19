#include<iostream>
#include<stack>
#include<vector>

using namespace std;

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

	vector<int> h = {2, 1, 5, 6, 2, 3};
	int n = h.size();

	vector<int> nsrIdx = f1(h); // linear
	vector<int> nslIdx = f2(h); // linear

	int maxSoFar = 0; // to track the maximum area of rectangle in histogram

	for (int i = 0; i < n; i++) { // linear

		// find the best rectangle area with height as h[i]

		int bestWidth = nsrIdx[i] - nslIdx[i] - 1;
		int bestArea = h[i] * bestWidth;

		maxSoFar = max(maxSoFar, bestArea);

	}

	cout << maxSoFar << endl;

	// time : O(n)
	// space: O(n) due to monotonic stack used in f1() and f2()

	return 0;
}
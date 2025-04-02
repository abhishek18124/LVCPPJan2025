/*

https://hack.codingblocks.com/app/contests/3122/1057/problem

When we calculate the mid point 'm', we ask the question

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?

	now, we can rephrase this question in two ways

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?

	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then

	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len'
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time

	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ?

*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<numeric>

using namespace std;

bool f(int k, int n, vector<int>& b, int timeLimit) {

	// can k painters paint n boards of given lengths in timeLimit ?

	// find out the no. of painters needed to paint n boards of given
	// lengths in timeLimit

	int x = 1; // start with a single painter
	int time = 0;

	int i = 0;

	while (i < n) {

		// ask the current active painter to paint the ith board

		time += b[i];
		if (time > timeLimit) {
			// add another painter to the job
			x++;
			time = 0;
			continue; // we want the newly added painter to redo the current board which was partially painted by the last active painter
		}

		i++;
	}

	return x <= k;

}

int getMinTime(int k, int n, vector<int>& b) {

	// int s = INT_MIN; // for the tightest lower-bound, assign a painter to each board
	// int e = 0;       // for the tightest upper-bound, assign a single painter to paint all the boards
	// for (int i = 0; i < n; i++) {
	// 	s = max(s, b[i]);
	// 	e += b[i];
	// }

	int s = *max_element(b.begin(), b.end());
	int e = accumulate(b.begin(), b.end(), 0);

	cout << s << endl;
	cout << e << endl;

	int ans;

	// while (s <= e) {
	// 	int m = s + (e - s) / 2;

	// 	// can 'k' painters paint 'n' boards of given lengths in 'm' units of time ?

	// 	int x = numPaintersRequired(n, b, m);
	// 	if (x <= k) {
	// 		// 'k' painters can also paint 'n' boards in 'm' amt. of time
	// 		ans = m;
	// 		// since we want to minimize the time, continue
	// 		// your search towards the left of 'm' i.e. the
	// 		// search space reduces from [s, e] to [s, m-1].
	// 		e = m - 1;
	// 	} else {
	// 		// 'k' painters cannot paint 'n' boards in 'm' amt. of time
	// 		// therefore continue your search towards the right of 'm'
	// 		// i.e. the search space reduces from [s, e] to [m+1, e].
	// 		s = m + 1;
	// 	}
	// }

	while (s <= e) { // time : log(e-s) * n

		int m = s + (e - s) / 2;

		// can k painters paint n boards in m units of time ?

		if (f(k, n, b, m)) {
			ans = m;
			e = m - 1;
		} else {
			s = m + 1;
		}

	}

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	cout << getMinTime(k, n, b) << endl;

	return 0;
}
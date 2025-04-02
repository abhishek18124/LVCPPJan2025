#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

bool f(int n, vector<int>& a, int k, double m) {

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt += a[i] / m;
	}

	return cnt >= k;

}

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	double ans;
	double moe = 1e-7;
	int numIters = 80;

	double s = 0;
	double e = 1e7;

	for (int i = 1; i <= numIters; i++) {

		double m = s + (e - s) / 2;
		if (f(n, a, k, m)) {
			ans = m;
			s = m + moe;
		} else {
			e = m - moe;
		}

	}

	cout << setprecision(7) << fixed << ans << endl;

	return 0;
}
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	double s = 0;
	double e = n;
	double moe = 1e-16;

	double ans;

	int numIterations = log2((e - s) * 1e16); // try to hard code this value as log2 also runs into precision issue

	for (int i = 1; i <= numIterations; i++) {

		double m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + moe;

		} else {

			e = m - moe;

		}

	}

	cout << setprecision(7) << fixed << ans << endl;

	return 0;
}

#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int n;
	cin >> n;

	double s = 0;
	double e = n;
	double moe = 1e-7;

	double ans;

	while (e - s > moe) {

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

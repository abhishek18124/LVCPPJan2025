#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int n;
	cin >> n;

	double s = 0;
	double e = n;
	double moe = 1e-16; // you run into precision issue due to very small margin of error

	double ans;

	while (e - s > moe) {

		double m = s + (e - s) / 2;

		cout << setprecision(10) << fixed << s << " " << m << " " << e << endl;

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

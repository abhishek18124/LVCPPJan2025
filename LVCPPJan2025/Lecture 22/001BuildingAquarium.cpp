#include<iostream>
#include<vector>

using namespace std;

bool f(int n, const vector<int>& a, int x, int m) {

    // can I make a container of height 'm'
    // such that my maximum water consumption
    // is x ?

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += max(0, m - a[i]);
    }

    return sum <= x;

}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 1;
        int e = 2e9;

        int ans;

        while (s <= e) { // time : log(e-s).n // log(2e9).n

            int m = s + (e - s) / 2;
            if (f(n, a, x, m)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }

        }

        cout << ans << endl;

    }

    return 0;
}
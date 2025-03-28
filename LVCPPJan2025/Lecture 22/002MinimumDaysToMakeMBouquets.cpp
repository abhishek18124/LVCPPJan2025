#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {

    int collectCnt = 0; // to track no. of adjacent bloomed flowers you've picked
    int bouquetCnt = 0; // to track no. of bouquets of k adjacent flowers you've built

    for (int dayOfBloom : bloomDay) {
        if (dayOfBloom <= timeLimit) {
            // collect the current flower since it has bloomed
            collectCnt++;
            if (collectCnt == k) {
                // you can make a bouquet
                bouquetCnt++;
                collectCnt = 0;
            }
        } else {
            // current flower has not yet bloomed
            collectCnt = 0; // reset the count to make sure we always make a bouquet of k adjacent flowers
        }
    }

    return bouquetCnt >= m;

}

int minDays(vector<int>& bloomDay, int m, int k) {

    int s = *min_element(bloomDay.begin(), bloomDay.end());
    int e = *max_element(bloomDay.begin(), bloomDay.end());

    int ans;

    while (s <= e) { // time : log(max-min).n

        int mid = s + (e - s) / 2;

        // can I make 'm' bouquets of 'k' adj. flowers in 'mid' no. of days ?

        if (f(bloomDay, m, k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }

    }

    return ans;

}

int main() {

    vector<int> bloomDay = {1, 3, 2, 1, 10, 4, 2, 3};
    int m = 2;
    int k = 3;

    cout << minDays(bloomDay, m, k) << endl;

    return 0;
}
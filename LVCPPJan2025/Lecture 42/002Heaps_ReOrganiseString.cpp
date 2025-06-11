
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (char ch : s) {
            // int idx = ch - 'a';
            // freq[idx]++;
            freq[ch - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }

        // for (int i = 0; i < 26; i++) {
        //     cout << "freq(" << (char)(i + 'a') << ") = " << freq[i] << endl;
        // }

        // cout << endl;

        string out = "";

        while (!maxHeap.empty()) {
            if (maxHeap.size() == 1) {
                pair<int, char> firstMax = maxHeap.top();
                maxHeap.pop();
                if (firstMax.first == 1) {
                    out += firstMax.second;
                } else {
                    out = "";
                }
            } else {

                // maxHeap.size() >= 2

                pair<int, char> firstMax = maxHeap.top();
                maxHeap.pop(); // (5, a)
                out += firstMax.second;
                firstMax.first--; // (4, a)

                pair<int, char> secondMax = maxHeap.top();
                maxHeap.pop(); // (4, b)
                out += secondMax.second;
                secondMax.first--; // (3, b)

                if (firstMax.first > 0) {
                    maxHeap.push(firstMax);
                }

                if (secondMax.first > 0) {
                    maxHeap.push(secondMax);
                }

            }
        }

        return out;

    }
};

int main() {

    string s = "aaab";

    Solution soln;
    cout << soln.reorganizeString(s) << endl;

    return 0;

}
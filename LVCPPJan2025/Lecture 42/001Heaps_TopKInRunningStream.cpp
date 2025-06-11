/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>
#define pqmin priority_queue<int, vector<int>, greater<int>>

using namespace std;

void printHeap(pqmin minHeap) { // here minHeap is passed by value
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k;
    cin >> k;

    pqmin minHeap;
    int num;

    for (int i = 1; i <= k; i++) {
        cin >> num;
        minHeap.push(num);
    }

    while (true) {
        cin >> num;

        if (num == -2) { // stopping condition
            break;
        }

        if (num == -1) {
            printHeap(minHeap);
        } else {
            if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }

    return 0;
}
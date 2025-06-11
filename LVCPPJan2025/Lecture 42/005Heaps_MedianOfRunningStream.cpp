/*

Given a running stream of integers, design an algorithm to print the median
of the numbers in the stream each time a new integer is added to the stream.

Example : Input = 4, 6, 2, 5,   3, 1,   7, 9,   8 . . .
          Output= 4, 5, 4, 4.5, 4, 3.5, 4, 4.5, 5 . . .

*/

#include<iostream>
#include<queue>

#define pqmin priority_queue<int, vector<int>, greater<int>>
#define pqmax priority_queue<int>

using namespace std;

int main() {

    int num;
    cin >> num;

    double median;
    median = num;

    cout << median << " ";

    pqmax leftMaxHeap;
    leftMaxHeap.push(num);

    pqmin rightMinHeap;

    // time : O(nlogn)
    // space : O(n) due to leftMaxHeap and rightMinHeap

    while (true) {

        cin >> num;

        if (num == -1) break;

        if (num <= median) {

            // insert the num in leftMaxHeap

            if (leftMaxHeap.size() == rightMinHeap.size()) {
                leftMaxHeap.push(num);
                median = leftMaxHeap.top();
            } else if (leftMaxHeap.size() > rightMinHeap.size()) {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
                leftMaxHeap.push(num);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            } else {
                // leftMaxHeap.size() < rightMinHeap.size()
                leftMaxHeap.push(num);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            }

        } else {

            // insert the num in rightMinHeap

            if (rightMinHeap.size() == leftMaxHeap.size()) {
                rightMinHeap.push(num);
                median = rightMinHeap.top();
            } else if (rightMinHeap.size() > leftMaxHeap.size()) {
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
                rightMinHeap.push(num);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            } else {
                // rightMinHeap.size() < leftMaxHeap.size()
                rightMinHeap.push(num);
                median = (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
            }

        }

        cout << median << " ";

    }

    return 0;
}
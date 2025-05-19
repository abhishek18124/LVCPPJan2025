#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<char> q;
	int freq[26] = {0};

	char ch;

	while (true) {

		cin >> ch;

		freq[ch - 'a']++;
		if (freq[ch - 'a'] == 1) {
			// currently, ch is non-repeating, track it
			q.push(ch);
		}

		// what is the first non-repeating char in the stream after reading ch

		while (!q.empty() and freq[q.front() - 'a'] > 1) {
			// char in the front of the queue are no longer non-repeating
			q.pop();
		}

		if (q.empty()) {
			// there is no non-repeating char in the stream
			cout << -1 << " ";
		} else {
			// whatever is at the front of the queue is the
			// 1st non-repeating char in the stream
			cout << q.front() << " ";
		}

	}

	return 0;
}
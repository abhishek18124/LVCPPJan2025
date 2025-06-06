#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) { // here stack is passed by value

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

// time : O(n)
// space: O(n) due to fn call stack

void insertAtBottom(stack<int>& s, int data) { // here stack is passed by reference

	// base case

	if (s.empty()) {
		s.push(data);
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();

	insertAtBottom(s, data);

	s.push(x);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int data = 0;

	insertAtBottom(s, data);

	print(s);

	return 0;
}
#include<iostream>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to stack<>

bool isBalanced(const string& str) { // str is passed by const-ref to avoid copy plus to make sure it isn't modified in the fn

	stack<char> s;

	for (char ch : str) {
		switch (ch) {
		case '(':
		case '{':
		case '[': s.push(ch); break;
		case ')': if (s.empty() || s.top() != '(') return false; else s.pop(); break;
		case '}': if (s.empty() || s.top() != '{') return false; else s.pop(); break;
		case ']': if (s.empty() || s.top() != '[') return false; else s.pop(); break;
		}
	}

	return s.empty();
}

int main() {

	string str = "([{])";

	isBalanced(str) ? cout << "balanced!" << endl : cout << "not balanced!" << endl;

	return 0;
}
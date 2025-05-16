#include<iostream>
#include<stack>

using namespace std;

// [HW] try to implement custom_stack without using min_stack
// make sure time complexity of each operation must be const

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack;

public :

	void push(int val) {
		main_stack.push(val);
		if (min_stack.empty() or val <= min_stack.top()) {
			min_stack.push(val);
		}
	}

	void pop() {
		if (empty()) {
			return;
		}

		int temp = main_stack.top();
		main_stack.pop();
		if (temp == min_stack.top()) {
			// temp was minSofar
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty();
	}

	int top() {
		return main_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(20);
	cs.push(30);
	cs.push(0);
	cs.push(40);
	cs.push(0);
	cs.push(50);

	cout << cs.top() << " " << cs.getMin() << endl; // 50 0

	cs.pop(); // 50 is popped

	cout << cs.top() << " " << cs.getMin() << endl; // 0 0

	cs.pop(); // 0 is popped

	cout << cs.top() << " " << cs.getMin() << endl; // 40 0

	return 0;
}

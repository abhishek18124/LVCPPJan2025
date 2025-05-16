#include<iostream>
#include<stack>

using namespace std;

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack;

public :

	void push(int val) {
		main_stack.push(val);
		if (min_stack.empty() or val < min_stack.top()) {
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
	cs.push(-5);
	cs.push(60);

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.pop();

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.pop();

	cout << cs.top() << " " << cs.getMin() << endl;

	cs.pop();
	cs.pop();

	cout << cs.top() << " " << cs.getMin() << endl;


	return 0;
}

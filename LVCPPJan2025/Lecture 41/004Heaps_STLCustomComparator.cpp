/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;
	double credits;

	customer(string name, int age, double credits) {
		this->name = name;
		this->age = age;
		this->credits = credits;
	}

};

// class ageCmp {
// public:

// 	// return true if you want a to be ordered before b
// 	// otherwise return false

// 	bool operator()(customer a, customer b) {

// 		if (a.age < b.age) {
// 			// we want a to be ordered before b
// 			// since we are building a minHeap
// 			// based on customer age
// 			return true;
// 		}

// 		return false;
// 	}
// };

class ageCmp {
public:

	// return false if you want a to be given more priority than b
	// otherwise return true

	bool operator()(customer a, customer b) {

		if (a.age < b.age) {
			// we want a to be given more priority than b
			// since we are building a minHeap
			// based on customer age
			return false;
		}

		return true;
	}
};


class nameCmp {
public:

	// return false if you want a to be given more priority than b
	// otherwise return true

	bool operator()(customer a, customer b) {

		if (a.name < b.name) {
			// we want a to be given more priority than b
			// since we are building a minHeap
			// based on customer name
			return false;
		}

		return true;
	}
};


int main() {

	// build a minHeap based on customer age

	priority_queue<customer, vector<customer>, nameCmp> m;

	m.push(customer("rohan", 20, 500));
	m.push(customer("stuti", 19, 400));
	m.push(customer("ajay", 21, 1000));
	m.push(customer("aarish", 22, 50));
	m.push(customer("megha", 18, 700));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}
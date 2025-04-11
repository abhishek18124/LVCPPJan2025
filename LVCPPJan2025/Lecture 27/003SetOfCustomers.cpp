#include<iostream>
#include<set>

using namespace std;

class customer {
public:
	string name;
	int age;
	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class customerAgeCmp {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) const {
		if (a.age < b.age) {
			// we want a to be ordered before b since we are sorting the set<> in inc. order based on customer age
			return true;
		}
		return false;
	}

};

int main() {

	set<customer, customerAgeCmp> s;

	s.insert(customer("ajay", 20));
	s.insert(customer("dhruv", 19));
	s.insert(customer("saanch", 18));
	s.insert(customer("parul", 21));
	s.insert(customer("abhinov", 22));

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	cout << endl;

	s.erase(s.begin()); // make sure iteator passed to the erase() is valid, if it is not valid you get an error

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	cout << endl;

	auto it = s.begin();
	it++;

	s.erase(it);

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	return 0;
}
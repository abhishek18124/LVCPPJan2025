#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// // return true if you want a to be ordered before b otherwise return false

// bool cmp(customer a, customer b) {
// 	if (a.age < b.age) {
// 		// we want a to be ordered before b
// 		// since we are sorting customer
// 		// on age in the inc. order
// 		return true;
// 	}

// 	return false;
// }

class ageCmp {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			return true;
		}
		return false;
	}

};

int main() {

	vector<customer> v;

	customer c1("Ramanujan", 32, 'M', 1729);
	v.push_back(c1);
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	// sort(v.begin(), v.end(), cmp);

	ageCmp obj;

	// obj is a function object

	sort(v.begin(), v.end(), obj);

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	vector<int> v2 = {4, 3, 0, 1, 5};

	greater<int> obj2; // fn obj

	sort(v2.begin(), v2.end(), obj2);

	sort(v2.begin(), v2.end(), greater<int>());

	return 0;
}
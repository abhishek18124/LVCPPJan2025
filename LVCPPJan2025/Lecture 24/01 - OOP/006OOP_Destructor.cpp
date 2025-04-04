#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

	~customer() {
		cout << "\nwe are in the destructor of customer class destructing the memory allocated for " << name << endl;
	}

};

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	c1.print();

	customer c2("Aryabhata", 74, 'M', 0);
	c2.print();

	return 0;
}
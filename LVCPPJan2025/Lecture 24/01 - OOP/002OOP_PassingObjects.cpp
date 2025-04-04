#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void print(customer c) { // by default objects are passed by value

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

	c.age++;

}

void print2(customer& c) { // here, obj is passed by ref

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

	c.age++;

}

void print3(const customer& c) { // here, obj is passed by const ref

	cout << "name = " << c.name << endl;
	cout << "age = " << c.age << endl;
	cout << "gender = " << c.gender << endl;
	cout << "credits = " << c.credits << endl << endl;

	// c.age++; // not allowed

}

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	// print(c1);
	// print2(c1);
	print3(c1);

	cout << c1.age << endl;

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	print(c2);

	customer c3;

	cin >> c3.name >> c3.age >> c3.gender >> c3.credits;

	print(c3);

	return 0;
}
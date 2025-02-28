#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v;

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	v.resize(100);

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	return 0;
}
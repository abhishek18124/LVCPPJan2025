#include<iostream>

using namespace std;

void inc(int a) {
	cout << "inside inc before ++ a = " << a << endl;
	a++;
	cout << "inside inc after ++ a = " << a << endl;
}

int main() {

	int a = 10;

	cout << "inside main() before inc() a = " << a << endl;

	inc(a);

	cout << "inside main() after inc() a = " << a << endl;

	return 0;
}
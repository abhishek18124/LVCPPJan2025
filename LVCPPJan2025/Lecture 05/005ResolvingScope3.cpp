#include<iostream>

using namespace std;

int x = 100;
int w = 50;

int main() {

	cout << x << endl; // 100

	int x = 10;

	cout << x << endl; // 10

	{

		int x = 30;
		int y = 20;

		cout << x << " " << y << endl; // 30 20

		{

			int y = 40;
			int z = 20;
			int w = 120;

			cout << w << endl;

			cout << x << " " << y << " " << z << endl; // 30 40 20

		}

		cout << x << " " << y << endl; // 30 20

	}

	cout << x << endl; // 10
	// cout << y << endl;

	return 0;
}
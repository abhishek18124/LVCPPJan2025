#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	int arr[] = {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
	cout << arr << endl;

	char str2[] = "coding"; // '\0' is added automatically
	cout << str2 << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << endl;
	}

	return 0;
}
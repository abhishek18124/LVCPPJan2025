#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {

	char str[] = "hello";

	cout << str << endl;

	int n = strlen(str);

	reverse(str, str + n);

	cout << str << endl;

	return 0;
}
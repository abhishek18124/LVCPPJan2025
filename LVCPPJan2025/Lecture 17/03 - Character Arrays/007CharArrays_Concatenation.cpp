// n <= 50 and m <= 50

#include<iostream>
#include<cstring>

using namespace std;

// time : O(len of s2)

void stringConcat(char s1[], char s2[]) {
	int i = strlen(s1) ; // to iterate over s1[]
	int j = 0; // to iterate over s2[]
	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
}

int main() {

	char s1[101] = "abc";
	char s2[] = "xyz";

	cout << s1 << endl;

	// stringConcat(s1, s2);
	strcat(s1, s2); // it will concatenate s2 to s1

	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}
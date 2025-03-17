#include<iostream>
#include<cstring>

using namespace std;

// time : min(len of s1, len of s2)

int stringCmp(char s1[], char s2[]) {
	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]
	while (s1[i] != '\0' and s2[j] != '\0') {
		if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		} else if (s1[i] < s2[j]) {
			// s1 < s2
			return -1;
		}
		i++;
		j++;
	}

	if (s1[i] == '\0' and s2[j] == '\0') {
		// s1 is equal to s2
		return 0;
	} else if (s1[i] == '\0') { // s2[j] != '0' // len of s1 < len of s2
		// s1 < s2
		return -1;
	} else {
		// s1[i] != '\0' and s2[j] == '\0' // len of s1 > len of s2 // s1 > s2
		return 1;
	}
}

int main() {

	char s1[] = "z";
	char s2[] = "zzz";

	// int res = stringCmp(s1, s2);
	int res = strcmp(s1, s2);
	if (res == 0) {
		cout << s1  << " is equal to " << s2 << endl;
	} else if (res > 0) {
		cout << s1 << "  > " << s2 << endl;
	} else {
		// res < 0
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}
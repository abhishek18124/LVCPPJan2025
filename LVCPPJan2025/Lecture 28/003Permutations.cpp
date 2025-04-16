/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) = take decisions for remaining positions i to n-1

	// decide the char. for the ith position / index

	for (int j = i; j < n; j++) {

		// choose the jth option i.e. assign inp[j] to inp[i]

		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking // undo

	}


}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}

/*

optimising union and find operations using

* union by size
* path compression

*/

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

public:

	vector<int> parMap; // map that encodes the disjoint forest
	vector<int> sizeMap; // map that encodes size of each tree in the disjoint forest

	disjointSet(int n) {
		parMap.resize(n + 1);
		sizeMap.resize(n + 1);
	}

	void createSet(int x) {
		parMap[x] = x;
		sizeMap[x] = 1;
	}

	int findSet(int x) {
		// base case
		if (parMap[x] == x) {
			return x;
		}

		// recurive case
		return parMap[x] = findSet(parMap[x]); // path compression
	}

	void unionSet(int x, int y) { // union by size

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (sizeMap[lx] > sizeMap[ly]) {
				parMap[ly] = lx;
				sizeMap[lx] += sizeMap[ly];
			} else {
				// sizeMap[lx] <= sizeMap[ly]
				parMap[lx] = ly;
				sizeMap[ly] += sizeMap[lx];
			}

		}
	}

};

int main() {

	int n;
	cin >> n;

	disjointSet ds(n);

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;

	ds.unionSet(2, 3);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl << endl;

	return 0;

}
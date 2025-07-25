/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	// time : O(nlogn) since we are using map<>
	// time : on avg. O(n) but worst case O(n^2) if you are using unordered_map<>
	// space: O(n) due xFreqMap and yFreqMap

	map<int, int> xFreqMap;
	map<int, int> yFreqMap;

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	// time : O(n^2)

	int cnt = 0;

	for (Point pivot : points) {

		// find out no. of valid triangles we can form with given point as 'pivot'

		// 1. find out no. of points in the 2d plane whose x-coor matches pivot.x

		// 2. find out no. of points in the 2d plane whose y-coor matches pivot.y

		int a = xFreqMap[pivot.x]; // to track no. of points in 2d plane whose x-coor matches pivot.x
		int b = yFreqMap[pivot.y]; // to track no. of points in 2d plane whose y-coor matches pivot.y

		cnt += (a - 1) * (b - 1);

	}

	cout << cnt << endl;

	return 0;
}
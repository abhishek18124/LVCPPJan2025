#include<iostream>

using namespace std;

int main() {

    int arr[][4] = { // when you init a 2d-array, specifying rows in optional, but specifying coln is mandatory
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    int m = 3;
    int n = 4;

    for (int i = 0; i < m; i++) {
        // print the ith row
        for (int  j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
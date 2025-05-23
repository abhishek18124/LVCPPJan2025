#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to stack<>

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// collision(s) will happen

			bool flag = true; // assume 'ast' will survive collisions

			while (!s.empty() and s.top() > 0) {

				if (abs(ast) > s.top()) {
					// +ve asteroid at the top of the stack is destroyed
					s.pop();
				} else if (abs(ast) < s.top()) {
					// ast will be destroyed
					flag = false;
					break;
				} else {
					// abs(ast) is equal to s.top()
					// +ve asteroid at the top of the stack and 'ast' both will be destroyed
					s.pop();
					flag = false;
					break;
				}

			}

			if (flag) {
				// 'ast' has survived collisions
				s.push(ast);
			}



		} else {

			s.push(ast);

		}

	}

	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> ans = asteroidCollision(asteroids);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
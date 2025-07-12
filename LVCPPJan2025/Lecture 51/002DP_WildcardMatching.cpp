/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    bool f(string& s, string& p, int m, int n, int i, int j) {

        // base case

        // if(i == m and j == n) {
        //     // check p[n...n-1] i.e. "" matches s[m...m-1] i.e ""
        //     return true;
        // }

        // above base case is automatically handled in the if block below

        if (i == m) {

            // check p[j...n-1] matches s[m...m-1] i.e. ""

            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return flag;

        }

        // when we come here, we know for sure s[] has not ended

        if (j == n) {

            // check p[n...n-1] i.e. "" matches s[i...m-1]

            return false;

        }

        // recursive case

        // f(i, j) = check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {
            return f(s, p, m, n, i + 1, j + 1);
        } else if (p[j] == '*') {
            return f(s, p, m, n, i + 1, j) or f(s, p, m, n, i, j + 1);
        } else {
            // s[i] is not equal to p[j] and p[j] is not a wildcard character
            return false;
        }

    }

    bool fTopdown(string& s, string& p, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][j] != -1) {
            // you've solved f(i, j) previously so reuse the result
            return dp[i][j];
        }

        // base case

        // above base case is automatically handled in the if block below

        if (i == m) {

            // check p[j...n-1] matches s[m...m-1] i.e. ""

            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return dp[i][j] = flag; // save is mandatory here since this base case is expensive

        }

        // when we come here, we know for sure s[] has not ended

        if (j == n) {

            // check p[n...n-1] i.e. "" matches s[i...m-1]

            return dp[i][j] = false; // save is option here since this base case is cheap

        }

        // recursive case

        // f(i, j) = check if p[j...n-1] matches s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = fTopdown(s, p, m, n, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            return dp[i][j] = fTopdown(s, p, m, n, i + 1, j, dp) or fTopdown(s, p, m, n, i, j + 1, dp);
        } else {
            // s[i] is not equal to p[j] and p[j] is not a wildcard character
            return dp[i][j] = false;
        }

    }

    // time : O(mn)
    // space: O(mn) due to dp[][]
    // [HW] space can be optimised to O(n)

    bool fBottomUp(string& s, string& p, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // i == m

        for (int j = 0; j < n; j++) {
            // check if p[j...n-1] matches s[m...m-1] i.e. ""
            bool flag = true; // assume p[j...n-1] is all '*'
            for (int k = j; k < n; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[m][j] = flag;
        }

        // j == n

        for (int i = 0; i < m; i++) {
            // check if p[n...n-1] i.e. "" matches non-empty s[i..m-1]
            dp[i][n] = false;
        }

        // i == m and j == n

        dp[m][n] = true; // check if p[n...n-1] i.e. "" matches s[m...m-1] i.e. ""

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // dp[i][j] = f(i, j) = check if p[j...n-1] matches s[i...m-1]
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)

    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // return f(s, p, m, n, 0, 0);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return fTopdown(s, p, m, n, 0, 0, dp);

        return fBottomUp(s, p, m, n);

    }
};
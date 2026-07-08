/*
LeetCode 62: Unique Paths
-------------------------
Problem Statement:
A robot is located at the top-left corner of an m x n grid (0,0).
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner (m-1,n-1).
How many possible unique paths are there?

Constraints:
1 <= m, n <= 100
Answer is guaranteed to fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Approach 1: Recursion + Memoization ----------------
class SolutionMemo {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }

    int f(int i, int j, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return 1;   // base case: start cell
        if (i < 0 || j < 0) return 0;     // invalid indices
        if (dp[i][j] != -1) return dp[i][j]; // memoization check

        int up = f(i-1, j, dp);   // move up
        int left = f(i, j-1, dp); // move left

        return dp[i][j] = up + left;
    }
};

// ---------------- Approach 2: Tabulation (Bottom-Up DP) ----------------
class SolutionTab {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case: first row and first column
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        // fill the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// ---------------- Driver Code ----------------
int main() {
    int m = 3, n = 3;

    SolutionMemo sol1;
    cout << "Unique Paths (Memoization): " << sol1.uniquePaths(m, n) << endl;

    SolutionTab sol2;
    cout << "Unique Paths (Tabulation): " << sol2.uniquePaths(m, n) << endl;

    return 0;
}

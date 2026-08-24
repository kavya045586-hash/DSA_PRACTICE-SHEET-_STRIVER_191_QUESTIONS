/*
LeetCode Problem: Unique Paths
--------------------------------
A robot is located at the top-left corner of an m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Constraints:
1 <= m, n <= 100
The answer is guaranteed to be less than or equal to 2 * 10^9.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return path(0, 0, m, n, dp);
    }

    int path(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m-1 && j == n-1) return 1;   // reached destination
        if (i >= m || j >= n) return 0;       // out of bounds

        if (dp[i][j] != -1) return dp[i][j];  // memoization check

        // move down or right
        return dp[i][j] = path(i+1, j, m, n, dp) + path(i, j+1, m, n, dp);
    }
};

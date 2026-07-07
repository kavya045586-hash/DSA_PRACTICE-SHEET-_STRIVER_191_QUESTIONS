/*
LeetCode Problem: Set Matrix Zeroes (Problem #73)
URL: https://leetcode.com/problems/set-matrix-zeroes/

Description:
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -2^31 <= matrix[i][j] <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);
        
        // First pass: mark rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        
        // Second pass: set zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    Solution sol;

    // 🔹 Example Input
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    for (auto &row : matrix) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }

    sol.setZeroes(matrix);

    cout << "\nMatrix After setZeroes:\n";
    for (auto &row : matrix) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

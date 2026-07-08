/*
📌 Problem Statement:
You are given an m x n matrix where:
- Each row is sorted in ascending order.
- Each column is sorted in ascending order.

Write a function to determine if a given target integer exists in the matrix.
Return true if it exists, otherwise return false.

💡 Approach (Staircase Search):
1. Start from the top-right corner of the matrix (i = 0, j = n-1).
2. Compare matrix[i][j] with target:
   - If equal → return true.
   - If greater → move left (j--).
   - If smaller → move down (i++).
3. Continue until indices go out of bounds.
4. If not found, return false.

⚡ Time Complexity: O(m + n)
⚡ Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;       // handle empty matrix
        if (matrix[0].empty()) return false;    // handle empty row

        int r = matrix.size();
        int c = matrix[0].size();

        int i = 0;       // start at first row
        int j = c - 1;   // start at last column (top-right corner)

        while (i < r && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) {
                j--; // move left
            } else {
                i++; // move down
            }
        }
        return false;
    }
};

// 🔎 Example usage:
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target1 = 5;
    int target2 = 20;

    cout << (sol.searchMatrix(matrix, target1) ? "Found" : "Not Found") << endl;
    cout << (sol.searchMatrix(matrix, target2) ? "Found" : "Not Found") << endl;

    return 0;
}

/*
✅ Expected Output:
Found
Not Found
*/

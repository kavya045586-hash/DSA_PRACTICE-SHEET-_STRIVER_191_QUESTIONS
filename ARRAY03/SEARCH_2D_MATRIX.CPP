/*
📌 Problem Statement:
You are given an m x n matrix where:
- Each row is sorted in ascending order.
- The first integer of each row is greater than the last integer of the previous row.

Write a function to determine if a given target integer exists in the matrix.
Return true if it exists, otherwise return false.

💡 Approach:
1. Treat the 2D matrix as a flattened sorted array of size m * n.
2. Perform binary search:
   - Use two pointers: first_index = 0, last_index = m * n - 1.
   - Compute mid = first_index + (last_index - first_index) / 2.
   - Map the 1D index back to 2D using:
       row = mid / n
       col = mid % n
   - Compare matrix[row][col] with target.
   - Adjust search range accordingly.
3. Return true if found, false otherwise.

⚡ Time Complexity: O(log(m*n))
⚡ Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0) return false; // handle empty matrix
        int c = matrix[0].size();
        if (c == 0) return false; // handle empty row

        int first_index = 0;
        int last_index = r * c - 1;

        while (first_index <= last_index) {
            int mid = first_index + (last_index - first_index) / 2;
            int midValue = matrix[mid / c][mid % c]; // map 1D index to 2D

            if (midValue == target) return true;
            if (midValue < target) {
                first_index = mid + 1;
            } else {
                last_index = mid - 1;
            }
        }
        return false;
    }
};

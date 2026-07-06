/*
LeetCode Problem: Pascal's Triangle (Problem #118)
URL: https://leetcode.com/problems/pascals-triangle/

Description:
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:
Input: numRows = 5
Output: 
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
- 1 <= numRows <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int total_rows) {
        vector<vector<int>>ans;
        for(int i=1;i<=total_rows;i++)
        {
           ans.push_back(solution(i));

        }
        return ans;
      
    }
    vector<int>solution(int n)
    {
          
        vector<int> a;                // single row
        long long int res = 1;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                a.push_back(1);
            }
            else
            {
            res*=(n-i);
            res/=i;
            a.push_back(res);
            }
           
        }
        return a;
    }


int main() {
    Solution sol;
    int numRows = 5;  // 🔹 You can change input here
    vector<vector<int>> triangle = sol.generate(numRows);

    cout << "Pascal's Triangle for numRows = " << numRows << ":\n";
    for (auto &row : triangle) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}

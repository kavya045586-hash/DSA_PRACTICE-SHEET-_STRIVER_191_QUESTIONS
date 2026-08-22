// Question: Given an integer n, return the nth row of Pascal's Triangle.
// Pascal's Triangle: Each number is the sum of the two numbers directly above it.
// Example: 
// Input: n = 3
// Output: [1, 3, 3, 1]

class Solution {
public:
    vector<int> getRow(int n) {
        n = n + 1;
        long long res = 1;
        vector<int> ans;
        ans.push_back(res);
        for (int i = 1; i < n; i++) {
            res = res * (n - i) / (i);   // safer formula
            ans.push_back(res);
        }
        return ans;
    }
};

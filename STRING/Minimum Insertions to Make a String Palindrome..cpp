/*
Problem:
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

Examples:
Input: s = "zzazz"
Output: 0

Input: s = "mbadm"
Output: 2

Input: s = "leetcode"
Output: 5

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string rev = string(s.rbegin(), s.rend());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // LCS between s and rev
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == rev[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lps = dp[n][n];
        return n - lps;
    }
};

int main() {
    Solution sol;
    cout << sol.minInsertions("zzazz") << endl;     // 0
    cout << sol.minInsertions("mbadm") << endl;     // 2
    cout << sol.minInsertions("leetcode") << endl;  // 5
}

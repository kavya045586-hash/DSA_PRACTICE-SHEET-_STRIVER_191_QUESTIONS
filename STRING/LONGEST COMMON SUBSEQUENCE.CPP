// Question: Given two strings text1 and text2, 
// return the length of their longest common subsequence.
// A subsequence is a sequence derived from another string 
// by deleting some characters without changing the order of the remaining characters.
// Example: "ace" is a subsequence of "abcde".
// The longest common subsequence problem asks for the maximum length subsequence 
// that appears in both strings.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};

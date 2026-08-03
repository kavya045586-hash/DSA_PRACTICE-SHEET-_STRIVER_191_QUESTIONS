// Question: Given a string s, return the length of the longest palindromic subsequence in s.
// A subsequence is a sequence derived from another string by deleting some characters 
// without changing the order of the remaining characters.
// Example: "aba" is a palindromic subsequence of "bbbab".
// Approach: The longest palindromic subsequence can be found by computing the 
// Longest Common Subsequence (LCS) between the string and its reversed version.

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string p = s; 
        reverse(p.begin(), p.end());   // reverse the copy, not s itself
        // Important: If you directly call reverse(s.begin(), s.end()), the original string s itself gets reversed.
// To avoid modifying s, always make a copy first (e.g., string p = s; reverse(p.begin(), p.end());).

        return longestCommonSubsequence(s, p); 
    }
    
private:
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

/*
Question:
Given a string s, return the longest palindromic substring in s.

A palindrome is a string that reads the same backward as forward.
For example:
Input: "babad"
Output: "bab" (or "aba")

Input: "cbbd"
Output: "bb"

Constraints:
- 1 <= s.length <= 1000
- s consists of only digits and English letters.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return " ";

        int start = 0, maxlen = 1;
        for(int i = 0; i < s.size(); i++) {
            // Odd length palindrome
            center(s, i, i, start, maxlen);
            // Even length palindrome
            center(s, i, i + 1, start, maxlen);
        }
        return s.substr(start, maxlen);
    }

private:
    void center(string &s, int l, int r, int &start, int &maxlen) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            if(r - l + 1 > maxlen) {
                start = l;
                maxlen = r - l + 1;
            }
            l--;
            r++;
        }
    }
};

/*
LeetCode Problem: Minimum Window Substring

Question:
Given two strings s and t, return the minimum window substring of s 
such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

Example:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

Constraints:
- 1 <= s.length, t.length <= 10^5
- s and t consist of uppercase and lowercase English letters.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        int minlen = INT_MAX;       // length of smallest valid window
        int l = 0, r = 0, count = 0;
        int firstindx = 0;          // starting index of smallest window
        unordered_map<char,int> map;

        // build frequency map for characters in t
        for (int i = 0; i < tn; i++) {
            map[t[i]]++;
        }

        // expand window with right pointer
        while (r < sn) {
            if (map[s[r]] > 0) count++; // matched a needed char
            map[s[r]]--;                // consume character
            r++;

            // shrink window from left when all chars matched
            while (count == tn) {
                if (r - l < minlen) {
                    minlen = r - l;
                    firstindx = l;
                }

                map[s[l]]++;            // restore character
                if (map[s[l]] > 0) count--; // requirement broken
                l++;
            }
        }

        // return smallest window substring or empty string
        return minlen == INT_MAX ? "" : s.substr(firstindx, minlen);
    }
};

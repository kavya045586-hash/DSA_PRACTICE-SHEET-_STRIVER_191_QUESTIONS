/*
LeetCode Problem: Longest Repeating Character Replacement (424)

Question:
You are given a string s and an integer k. You can choose any character of the string 
and change it to any other uppercase English character. You can perform this operation 
at most k times.

Return the length of the longest substring containing the same letter you can get 
after performing the above operations.

Example:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'B' → longest substring is "AAAA" or "BBBB".

Constraints:
- 1 <= s.length <= 10^5
- s consists of only uppercase English letters.
- 0 <= k <= s.length
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size();
        int mx = 0;                  // result length
        int maxelement = 0;          // max frequency of any char in current window
        unordered_map<char,int> map; // frequency map

        while (r < n) {
            map[s[r]]++;
            maxelement = max(maxelement, map[s[r]]); // update max frequency

            int winlen = r - l + 1;

            // if replacements needed <= k, update result
            if ((winlen - maxelement) <= k) {
                mx = max(mx, winlen);
            } else {
                map[s[l]]--; // shrink window
                l++;
            }
            r++;
        }
        return mx;
    }
};

// Question:
// You are given a string s consisting only of lowercase alphabets and an integer k.
// Your task is to find the length of the longest substring that contains exactly k distinct characters.
// If no such substring exists, return -1.
//
// Examples:
// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe".
//
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.
//
// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b'.
//
// Constraints:
// 1 ≤ s.size() ≤ 10^5
// 1 ≤ k ≤ 26
//
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(k)
//
// Company Tags: Amazon, Google, SAP Labs
// Topic Tags: Sliding Window, HashMap, Strings

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char,int> freq;
        int mx = -1;
        int l = 0;
        int r = 0;

        while (r < n) {
            freq[s[r]]++;

            // Shrink window if more than k distinct
            while (freq.size() > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }

            // Only update if we have exactly k distinct
            if (freq.size() == k) {
                mx = max(mx, r - l + 1);
            }
            r++;
        }

        return mx;
    }
};

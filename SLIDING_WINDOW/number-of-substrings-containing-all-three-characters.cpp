// Question:
// Given a string s consisting only of characters 'a', 'b', and 'c',
// return the number of substrings in s that contain at least one occurrence of all three characters.
//
// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings that contain all three characters are:
// "abc", "bca", "cab", "abc", "abca", "bcab", "cabc", "abcab", "bcabc", "abcabc".
//
// Example 2:
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings are "aaacb", "aacb", "acb".
//
// Example 3:
// Input: s = "abc"
// Output: 1
// Explanation: The substring "abc" itself.
//
// Constraints:
// 1 ≤ s.length ≤ 10^5
// s consists of only 'a', 'b', and 'c'.
//
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)
//
// Company Tags: Amazon, Google, Microsoft
// Topic Tags: Sliding Window, Strings, HashMap

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        int count = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            freq[s[r]]++;

            // When window contains all 3 distinct characters
            while (freq.size() == 3) {
                count += (n - r); // all substrings starting at l and ending at r..n-1
                freq[s[l]]--;
                if (freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};

/*
Problem:
Given two strings, a text string txt and a pattern string pat, both consisting of lowercase English alphabets.
Return the starting indices (0-based) of all the occurrences of the pattern string pat in the text string txt.

Note: Return an empty list in case of no occurrences of pattern.

Examples:
Input: txt = "geeksforgeeks", pat = "geek"
Output: [0, 8]
Explanation: The string "geek" occurs twice in txt, one starts at index 0 and the other at index 8.

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]
*/

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        vector<int> result;
        size_t pos = txt.find(pat); // first occurrence

        while (pos != string::npos) {
            result.push_back(pos);

            // move the search window forward in txt
            pos = txt.find(pat, pos + 1);
        }

        return result;
    }
};

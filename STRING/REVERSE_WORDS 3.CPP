/*
Question:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. 
Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"

Example 3:
Input: s = "a good   example"
Output: "example good a"
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;

        // Reverse each word individually
        while (right < s.size()) {
            if (s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
            right++;
        }
        // Reverse the last word
        reverse(s.begin() + left, s.begin() + right);

        return s;
    }
};

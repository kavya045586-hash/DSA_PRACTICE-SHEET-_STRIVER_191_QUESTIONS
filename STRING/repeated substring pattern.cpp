/*
LeetCode Problem:
Given a string s, check if it can be constructed by taking a substring of it
and appending multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

Constraints:
1 <= s.length <= 10^4
s consists of lowercase English letters.
*/

bool repeatedSubstringPattern(const std::string& s) {
    std::string doubled = s + s;
    // remove first and last character to avoid trivial match
    std::string trimmed = doubled.substr(1, doubled.size() - 2);
    return trimmed.find(s) != std::string::npos;
}

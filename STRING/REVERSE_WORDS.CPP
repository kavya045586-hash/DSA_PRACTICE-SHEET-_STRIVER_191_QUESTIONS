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
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);       // Stream to read words
        string word, result;
        vector<string> words;

        // Extract words (ignores multiple spaces automatically)
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Build the result string with single spaces
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords("the sky is blue") << endl;       // Output: "blue is sky the"
    cout << sol.reverseWords("  hello world  ") << endl;       // Output: "world hello"
    cout << sol.reverseWords("a good   example") << endl;      // Output: "example good a"
    return 0;
}

/*
Question:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0]; // Start with the first string as prefix

    for (int i = 1; i < strs.size(); i++) {
        // Shrink prefix until it matches the start of strs[i]
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

int main() {
    vector<string> strs1 = {"flower","flow","flight"};
    vector<string> strs2 = {"dog","racecar","car"};

    cout << "Example 1 Output: " << longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << "Example 2 Output: " << longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}

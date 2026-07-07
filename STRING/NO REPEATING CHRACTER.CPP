/*
Problem: Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without repeating characters.
Example:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int mx = 0;
        unordered_map<char, int> map;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (map.find(c) != map.end() && map[c] >= low) {
                low = map[c] + 1;
            }
            map[c] = i;
            mx = max(mx, i - low + 1);
        }
        return mx;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Longest substring length: " << result << endl;

    return 0;
}

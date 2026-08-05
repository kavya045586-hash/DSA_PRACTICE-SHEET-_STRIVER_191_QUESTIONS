/*
Problem:
Given an array of strings strs, group the anagrams together.
Return the answer in any order.

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sorted word as key
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    auto groups = sol.groupAnagrams(strs);

    for (auto &group : groups) {
        cout << "[ ";
        for (auto &word : group) cout << word << " ";
        cout << "]" << endl;
    }
}

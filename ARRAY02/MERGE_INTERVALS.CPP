/*
LeetCode Problem: Merge Intervals
---------------------------------
Given an array of intervals where intervals[i] = [start_i, end_i],
merge all overlapping intervals, and return an array of the non-overlapping intervals
that cover all the intervals in the input.

Example:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Approach:
1. Sort intervals by start time.
2. Use a result vector to store merged intervals.
3. Compare current interval with the last merged one:
   - If overlapping, merge them.
   - Else, push as a new interval.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        if (interval.empty()) return {};

        // Step 1: Sort intervals by start time
        sort(interval.begin(), interval.end());

        // Step 2: Initialize result with first interval
        result.push_back(interval[0]);

        // Step 3: Iterate through intervals
        for (int i = 0; i < interval.size(); i++) {
            vector<int>& r = result.back();   // last merged interval
            vector<int>& v = interval[i];     // current interval

            if (r[1] >= v[0]) {
                // Overlap → merge
                r[1] = max(v[1], r[1]);
            } else {
                // No overlap → push
                result.push_back(v);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged intervals: ";
    for (auto &interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

// Question:
// Given a collection of intervals, find the minimum number of intervals 
// you need to remove to make the rest of the intervals non-overlapping.
//
// Example:
// Input: [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: You can remove [1,3] and the rest of the intervals are non-overlapping.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        
        // Sort by end time
        sort(a.begin(), a.end(), [](const vector<int>& c, const vector<int>& d) {
            return c[1] < d[1];
        });

        int lastend = INT_MIN;  // safer than -1
        int count = 0;

        for (auto &g : a) {
            if (g[0] >= lastend) {
                count++;
                lastend = g[1];
            }
        }

        // Minimum removals = total - non-overlapping count
        return a.size() - count;
    }
};

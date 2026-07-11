// Problem: Longest Consecutive Sequence
// Question: Given an unsorted array of integers nums, 
// return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s) {
            // Only start counting if 'num' is the beginning of a sequence
            if(s.find(num - 1) == s.end()) {
                int currentNum = num;
                int streak = 1;

                while(s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    streak++;
                }

                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

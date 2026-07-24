/*
LeetCode Problem: Binary Subarrays With Sum (930)

Question:
Given a binary array nums and an integer goal, return the number of non-empty subarrays 
with a sum equal to goal.

Approach:
We use the "atMost" helper function to count subarrays with sum ≤ goal.
Then, the exact count of subarrays with sum == goal is:
    atMost(goal) - atMost(goal - 1)
This works because:
- atMost(goal) counts all subarrays with sum ≤ goal
- atMost(goal - 1) counts all subarrays with sum ≤ goal - 1
Subtracting gives exactly those with sum == goal.
*/

class Solution {
public:
    // Helper function: count subarrays with sum ≤ goal
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // guard against negative goal
        int l = 0, sum = 0, count = 0;
        for (int r = 0; r < (int)nums.size(); r++) {
            sum += nums[r]; // expand window by adding nums[r]
            while (sum > goal) { // shrink window if sum exceeds goal
                sum -= nums[l];
                l++;
            }
            // all subarrays ending at r with sum ≤ goal
            count += (r - l + 1);
        }
        return count;
    }

    // Main function: count subarrays with sum == goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exact count = subarrays with sum ≤ goal - subarrays with sum ≤ goal-1
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

/*
Problem: Maximum Subarray (LeetCode #53)
----------------------------------------
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum 
and return its sum.

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Approach: Kadane's Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int curr_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_so_far = max(max_so_far, curr_sum);
        }

        return max_so_far;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << "Maximum Subarray Sum = " << sol.maxSubArray(nums) << endl;
    return 0;
}

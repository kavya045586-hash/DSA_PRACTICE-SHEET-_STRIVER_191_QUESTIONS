/*
Problem:
Given an array of non-negative integers nums, you are initially positioned at the first index.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxindex) return false;       // can't reach this index
            maxindex = max(maxindex, i + nums[i]); // update farthest reachable index
        }
        return true;
    }
};

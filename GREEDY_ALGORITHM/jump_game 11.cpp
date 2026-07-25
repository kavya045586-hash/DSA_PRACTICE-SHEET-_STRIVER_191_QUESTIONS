/*
Problem:
You are given an array of non-negative integers nums where each element represents 
your maximum jump length at that position. Your goal is to reach the last index 
in the minimum number of jumps. Return the minimum number of jumps required 
to reach the last index.

Note:
- You can assume that you can always reach the last index.
- This is the "Jump Game II" problem.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int jump = 0;
        int farrest = 0;

        while(r < nums.size() - 1) {   // stop when we reach last index
            for(int i = l; i <= r; i++) {
                farrest = max(farrest, i + nums[i]);
            }
            l = r + 1;
            r = farrest;
            jump++;
        }
        return jump;
    }
};

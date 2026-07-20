// Question: Given an integer array nums and an integer k, 
// return the total number of continuous subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};

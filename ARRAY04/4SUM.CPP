// LeetCode Problem: 4Sum
// Question: Given an array nums of n integers, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] 
// such that a, b, c, and d are distinct indices and nums[a] + nums[b] + nums[c] + nums[d] == target.
// The solution set must not contain duplicate quadruplets. You may return the answer in any order.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int m = 0; m < n; m++) {
            if(m > 0 && nums[m] == nums[m-1]) continue;
            
            for(int i = m + 1; i < n; i++) {
                if(i > m + 1 && nums[i] == nums[i-1]) continue;

                int j = i + 1;
                int k = n - 1;

                while(j < k) {
                    long long sum = (long long)nums[m] + nums[i] + nums[j] + nums[k];

                    if(sum < target) {
                        j++;
                    }
                    else if(sum > target) {
                        k--;
                    }
                    else {
                        result.push_back({nums[m], nums[i], nums[j], nums[k]});
                        j++;
                        k--;

                        // ✅ Skip duplicates for j and k
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                }
            }
        }
        return result;
    }
};

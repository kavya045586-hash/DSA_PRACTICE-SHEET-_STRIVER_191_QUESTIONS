// Question: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, j != k and nums[i] + nums[j] + nums[k] == 0.
// The solution set must not contain duplicate triplets.
// Example: nums = [-1,0,1,2,-1,-4] → Output: [[-1,-1,2],[-1,0,1]]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
            
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++; // skip duplicates
                    while (l < r && nums[r] == nums[r - 1]) r--; // skip duplicates
                    l++; r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};

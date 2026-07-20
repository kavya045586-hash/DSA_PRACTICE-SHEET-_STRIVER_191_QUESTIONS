// Question: Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// Example: nums = [2,7,11,15], target = 9 → Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = arr[l].first + arr[r].first;
            if (sum == target) {
                return {arr[l].second, arr[r].second};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};

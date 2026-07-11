// LeetCode Problem: Two Sum
// Question: Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, 
// and you may not use the same element twice.
// You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;
        m[nums[0]] = 0;
        for(int i = 1; i <= nums.size(); i++) {
            int first = nums[i];
            int second = target - first;
            if(m.find(second) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};

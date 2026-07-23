// Question: Given an integer array nums and an integer k, 
// return the number of subarrays with exactly k distinct integers.

class Solution {
public:
    // Main function: counts subarrays with exactly k distinct integers
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Trick: exactly k = atMost(k) - atMost(k-1)
        return sol(nums, k) - sol(nums, k - 1);
    }

    // Helper function: counts subarrays with at most k distinct integers
    int sol(vector<int>& nums, int k) {
        unordered_map<int,int> map; // frequency map of elements in current window
        int l = 0;                  // left pointer of sliding window
        int r = 0;                  // right pointer of sliding window
        int count = 0;              // total count of valid subarrays
        int n = nums.size();        // size of input array

        // Expand the window by moving 'r'
        while (r < n) {
            map[nums[r]]++;         // include nums[r] in the window

            // If distinct elements exceed k, shrink from the left
            while (map.size() > k) {
                map[nums[l]]--;     // remove nums[l] from window
                if (map[nums[l]] == 0) map.erase(nums[l]); // erase if frequency becomes 0
                l++;                // move left pointer forward
            }

            // All subarrays ending at r with sum ≤ k distinct are valid
            // Number of such subarrays = (r - l + 1)
            count += (r - l + 1);

            r++; // move right pointer forward
        }

        return count; // return total subarrays with at most k distinct
    }
};

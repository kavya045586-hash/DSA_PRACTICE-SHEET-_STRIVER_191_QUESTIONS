// Question: Given a binary array nums and an integer k,
// return the maximum number of consecutive 1's in the array
// if you can flip at most k zeros.
//
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1], k = 2
// Output: 6
// Explanation: Flip two zeros to get [1,1,1,1,1,1,1,1,1,1] with longest streak = 6.
//
// Example 2:
// Input: nums = [0,0,1,1,1,0,0], k = 0
// Output: 3
// Explanation: You cannot flip any zeros, so the longest streak is 3.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zero = 0, mx = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                zero++;
            }

            // Shrink window until zeros <= k
            while (zero > k) {
                if (nums[l] == 0) zero--;
                l++;
            }

            // Update max length
            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};

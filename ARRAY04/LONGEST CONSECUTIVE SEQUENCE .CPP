// Question: Given an unsorted array of integers, 
// find the length of the longest consecutive elements sequence.
// Example: [100, 4, 200, 1, 3, 2] → longest consecutive sequence is [1,2,3,4], length = 4.
//"important point is even though there is duplicate it should continue counting sequence"
// You must write an algorithm that runs in O(n log n) using sorting and two-pointer approach.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Sort the array to bring consecutive numbers together
        sort(nums.begin(), nums.end());

        // Step 2: Initialize pointers and variables
        int i = 0;              // pointer for current element
        int j = 1;              // pointer for next element
        int n = nums.size();    // size of the array
        int count = 1;          // count of current consecutive sequence
        int mx = 1;             // maximum consecutive length found so far

        // Edge cases
        if (n == 1) return 1;   // single element → longest sequence = 1
        if (n <= 0) return 0;   // empty array → longest sequence = 0

        // Step 3: Traverse the array with two pointers
        while (j < n) {
            int count = 1;  // reset count for each new sequence

            // Step 4: Check if nums[i] and nums[j] are consecutive or duplicates
            while ((j < n && i < n - 1) && (nums[i] == nums[j] - 1 || nums[i] == nums[j])) {
                if (nums[i] == nums[j] - 1) {
                    // Found a valid consecutive step → increase count
                    count++;
                    mx = max(mx, count);  // update maximum length
                }
                i++; j++;  // move both pointers forward
            }

            // Step 5: Move to next potential sequence
            i++; j++;
        }

        // Step 6: Return the maximum consecutive sequence length
        return mx;
    }
};

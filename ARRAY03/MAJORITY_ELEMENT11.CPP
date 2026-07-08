/*
📌 Problem: Majority Element II (LeetCode 229)
----------------------------------------------
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example:
Input: nums = [3,2,3]
Output: [3]

Input: nums = [1,1,1,3,3,2,2,2]
Output: [1,2]

Constraints:
- 1 <= nums.length <= 5 * 10^4
- -10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1 = 0, el2 = 0;
        int c1 = 0, c2 = 0;

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (el1 == num) {
                c1++;
            } else if (el2 == num) {
                c2++;
            } else if (c1 == 0) {
                el1 = num;
                c1 = 1;
            } else if (c2 == 0) {
                el2 = num;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        // Step 2: Verify counts
        c1 = 0; c2 = 0;
        for (int num : nums) {
            if (num == el1) c1++;
            else if (num == el2) c2++;
        }

        vector<int> res;
        if (c1 > n/3) res.push_back(el1);
        if (c2 > n/3) res.push_back(el2);

        return res;
    }
};

// 🔹 Example usage
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,3,3,2,2,2};
    vector<int> ans = sol.majorityElement(nums);

    cout << "Majority elements (> n/3): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

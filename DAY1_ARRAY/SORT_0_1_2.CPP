/*
Problem: Sort Colors (LeetCode #75)
-----------------------------------
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red (0), white (1), and blue (2).

Approach: Dutch National Flag Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mov = 0;
        int high = nums.size() - 1;

        while (mov <= high) {
            if (nums[mov] == 0) {
                swap(nums[mov], nums[low]);
                low++;
                mov++;
            }
            else if (nums[mov] == 1) {
                mov++;
            }
            else { // nums[mov] == 2
                swap(nums[mov], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> nums = {0,1,2,0,1};
    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}

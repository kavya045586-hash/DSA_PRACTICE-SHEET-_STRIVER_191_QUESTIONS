/*
LeetCode Problem: Merge Sorted Array
------------------------------------
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums2 into nums1 as one sorted array. The final sorted array should not be returned
by the function, but instead be stored inside nums1.

Example:
Input: nums1 = [1,2,3,0,0,0], m = 3
       nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // pointer for nums1
        int j = n - 1;        // pointer for nums2
        int k = m + n - 1;    // pointer for placement in nums1

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2 (if any)
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    return 0;
}

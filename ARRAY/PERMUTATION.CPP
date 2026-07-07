/*
Problem Statement:
------------------
Implement the function nextPermutation that rearranges numbers into the lexicographically
next greater permutation of numbers. If such arrangement is not possible (the array is in descending order),
rearrange it as the lowest possible order (ascending). The replacement must be in-place
and use only constant extra memory.

Examples:
---------
Input: [1,2,3]
Output: [1,3,2]

Input: [3,2,1]
Output: [1,2,3]

Input: [1,1,5]
Output: [1,5,1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int pivot = -1;

        // Step 1: Find pivot (rightmost index where a[i] < a[i+1])
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < a[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse entire array (last permutation case)
        if (pivot == -1) {
            reverse(a.begin(), a.end());
            return;
        }

        // Step 3: Find rightmost element greater than pivot
        for (int i = n - 1; i > pivot; i--) {
            if (a[i] > a[pivot]) {
                swap(a[i], a[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(a.begin() + pivot + 1, a.end());
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3};

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    sol.nextPermutation(nums);

    cout << "Output: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}

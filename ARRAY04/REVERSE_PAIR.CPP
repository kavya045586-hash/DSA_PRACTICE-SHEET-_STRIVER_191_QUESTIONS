/*
Problem Statement:
Given an integer array nums, count the number of reverse pairs in the array.

Definition:
A reverse pair is defined as a pair (i, j) such that:
    - 0 <= i < j < nums.length
    - nums[i] > 2 * nums[j]

Task:
Implement an efficient algorithm to count reverse pairs using a modified Merge Sort approach.

Input:
- A vector of integers (nums).

Output:
- An integer representing the total number of reverse pairs.

Example:
Input:  nums = [1, 3, 2, 3, 1]
Output: 2
Explanation: The reverse pairs are (3,1) at indices (1,4) and (3,1) at indices (3,4).

Constraints:
- 1 <= nums.size() <= 10^5
- -2^31 <= nums[i] <= 2^31 - 1
*/
class Solution {
    int counts = 0;  // global counter
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return counts;  // ✅ fixed
    }

private:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            countPairs(arr, l, mid, r);  // ✅ renamed
            merge(arr, l, mid, r);
        }
    }

    void countPairs(vector<int>& arr, int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        while (i <= mid) {
            while (j <= r && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
            counts += (j - (mid + 1));
            i++;
        }
    }

    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    }
};
    
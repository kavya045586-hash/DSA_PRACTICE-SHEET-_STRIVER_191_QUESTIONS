/*
Problem Statement:
Implement the Merge Sort algorithm to sort an array of integers.

Description:
- You are given an array of integers.
- Your task is to sort the array using the Merge Sort technique.
- Merge Sort is a divide-and-conquer algorithm:
    1. Divide the array into two halves.
    2. Recursively sort both halves.
    3. Merge the two sorted halves into a single sorted array.

Input:
- A vector of integers (arr).

Output:
- The same vector sorted in ascending order.

Example:
Input:  [5, 2, 9, 1, 5, 6]
Output: [1, 2, 5, 5, 6, 9]

Constraints:
- 1 <= arr.size() <= 10^5
- -10^9 <= arr[i] <= 10^9
*/
class Solution {
public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }

    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;

        // Merge the two halves
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Copy remaining elements from right half
        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    }
};

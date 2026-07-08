/*
Problem: Count Inversions in an Array
-------------------------------------
An inversion in an array is a pair (i, j) such that i < j and arr[i] > arr[j].

Example:
Input:
5
2 4 1 3 5

Output:
3
Explanation: The inversions are (2,1), (4,1), (4,3).

Approaches:
1. Merge Sort (Efficient)
   - Time Complexity: O(n log n)
   - Space Complexity: O(n)

2. Brute Force (Naive)
   - Time Complexity: O(n^2)
   - Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Merge Sort Approach ----------------
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    long long count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            count += (n1 - i); // Remaining elements in L are greater
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return count;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(arr, left, mid);
        count += mergeSortAndCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

// ---------------- Brute Force Approach ----------------
long long bruteForceCount(vector<int>& arr) {
    long long count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) count++;
        }
    }
    return count;
}

// ---------------- Main Function ----------------
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Using Merge Sort
    vector<int> arrCopy = arr; // copy for brute force
    long long inversionsMerge = mergeSortAndCount(arr, 0, n - 1);
    cout << "Number of inversions (Merge Sort): " << inversionsMerge << endl;

    // Using Brute Force
    long long inversionsBrute = bruteForceCount(arrCopy);
    cout << "Number of inversions (Brute Force): " << inversionsBrute << endl;

    return 0;
}

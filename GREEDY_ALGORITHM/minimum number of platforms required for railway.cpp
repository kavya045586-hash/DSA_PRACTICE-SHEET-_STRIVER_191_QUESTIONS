/*
Question: Minimum Number of Platforms Required

Problem Statement:
Given the arrival and departure times of trains at a railway station,
find the minimum number of platforms required so that no train waits.

Details:
- You are given two arrays:
  arr[] → arrival times of trains
  dep[] → departure times of trains
- Each train needs one platform from its arrival until its departure.
- If another train arrives before the previous one departs, a new platform is needed.
- Your task is to calculate the minimum number of platforms required at the station
  so that all trains can be accommodated without waiting.

Example 1:
Input:
arr[] = {900, 940, 950, 1100, 1500, 1800}
dep[] = {910, 1200, 1120, 1130, 1900, 2000}
Output:
3

Example 2:
Input:
arr[] = {1000, 1100, 1200}
dep[] = {1030, 1130, 1230}
Output:
1
*/

#include <bits/stdc++.h>
using namespace std;

int findMinPlatforms(int arr[], int dep[], int n) {
    // Sort arrival and departure arrays
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1;   // At least one platform needed
    int result = 1;      // Stores the final answer
    int i = 1, j = 0;    // Pointers for arrival and departure

    while (i < n && j < n) {
        // If next train arrives before the last one departs → need new platform
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        // If train departs before next arrival → free a platform
        else {
            platforms--;
            j++;
        }
        result = max(result, platforms);
    }
    return result;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of platforms required = "
         << findMinPlatforms(arr, dep, n) << endl;

    return 0;
}

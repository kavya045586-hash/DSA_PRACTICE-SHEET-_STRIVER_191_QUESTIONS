// Question: You are given an integer array 'a' and an integer 'k'.
// You can choose exactly 'k' elements from either the beginning or the end of the array.
// Return the maximum possible sum you can obtain.
//
// Example:
// Input: a = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: You can pick [1,2,3] from the start (sum = 6),
// or [6,1,5] from the end (sum = 12). The maximum is 12.

class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0;

        // Take first k elements from the left
        for (int i = 0; i < k; i++) {
            sum += a[i];
        }

        int mx = sum;
        int rightSum = 0;

        // Try replacing left elements with right elements
        for (int i = k - 1; i >= 0; i--) {
            sum -= a[i];          // remove one from left side
            rightSum += a[n - 1]; // add one from right side
            n--;                  // move right pointer inward
            mx = max(mx, sum + rightSum);
        }

        return mx;
    }
};

// 📌 Problem Statement
// You are given an array `nums` containing `n` distinct numbers taken from the range [0, n].
// Since one number is missing from the range, find and return that missing number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        vector<int> a(n+1, 0);  // presence array of size n+1

        // Mark the numbers present
        for (int i = 0; i < n; i++) {
            a[nums[i]] = 1;
        }

        // Find the missing number
        for (int i = 0; i <= n; i++) {
            if (a[i] != 1) return i;
            k = i;
        }

        return k + 1; // fallback (though logically one number is always missing)
    }
};

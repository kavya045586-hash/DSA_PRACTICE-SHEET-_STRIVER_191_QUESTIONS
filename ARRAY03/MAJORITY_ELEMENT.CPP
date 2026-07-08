/*
📌 Problem: Majority Element
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
If no majority element exists, return -1.

💡 Approach: Boyer–Moore Majority Vote Algorithm
1. Traverse the array to find a candidate element.
   - If count = 0, set current element as candidate.
   - If candidate matches current element, increment count.
   - Otherwise, decrement count.
2. Verify candidate by counting its occurrences.
3. Return candidate if it appears more than n/2 times, else return -1.

⚡ Time Complexity: O(n)
⚡ Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = 0;   // candidate element
        int c = 0;    // counter
        int n = nums.size();

        // Step 1: Find candidate
        for (int i = 0; i < n; i++) {
            if (c == 0) {
                el = nums[i];
                c = 1;
            } else if (el == nums[i]) {
                c++;
            } else {
                c--;
            }
        }

        // Step 2: Verify candidate
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) count++;
        }

        if (count > n / 2) return el;
        return -1;
    }
};

// 🔎 Example usage
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}

/*
✅ Expected Output:
Majority Element: 2
*/

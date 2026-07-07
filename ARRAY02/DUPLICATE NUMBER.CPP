# Find the Duplicate Number (LeetCode 287)

## 📌 Question
Given an array of integers `nums` containing `n + 1` integers where each integer is between `1` and `n` (inclusive), prove that at least one duplicate number must exist. Return the duplicate number.

---

## 💡 Approach
We use a **hash map** to count occurrences of each number:
- Iterate through the array.
- Increment the count for each number.
- If any number’s count becomes greater than 1, return it as the duplicate.

This is a simple **O(n) time, O(n) space** solution.

---

## 🧑‍💻 Code (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            map[nums[i]]++;
            if(map[nums[i]] > 1) {
                return nums[i];  // duplicate found
            }
        }
        
        return -1; // fallback (not needed if problem guarantees a duplicate)
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};  // Example input
    cout << "Duplicate number: " << sol.findDuplicate(nums) << endl;
    return 0;
}

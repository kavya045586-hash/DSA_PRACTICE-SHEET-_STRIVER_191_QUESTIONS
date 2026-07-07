# Find Missing and Repeated Number

## 📌 Problem Statement
You are given an array of size `n` containing numbers from `1` to `n`.  
One number is **missing** and one number is **repeated**.  
Find both numbers.

---

## 💡 Approach
We use a **hash map** to count occurrences of each number:
1. Traverse the array and record frequencies.
2. If a number appears twice → that’s the **repeated number**.
3. If a number never appears → that’s the **missing number**.

- Time Complexity: **O(n)**  
- Space Complexity: **O(n)**  

---

## 🧑‍💻 Code (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> findMissingAndRepeated(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int repeated = -1, missing = -1;

        // Count frequencies
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Identify missing and repeated
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 0) {
                missing = i;
            }
            if(freq[i] > 1) {
                repeated = i;
            }
        }

        return {missing, repeated};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 3};  // Example input
    auto result = sol.findMissingAndRepeated(nums);
    cout << "Missing number: " << result.first << endl;
    cout << "Repeated number: " << result.second << endl;
    return 0;
}

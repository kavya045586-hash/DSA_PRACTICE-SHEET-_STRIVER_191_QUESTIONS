/*

🔎 Step 1: Understand the operation
You can pick two indices i and j.

Choose a bit position k where both numbers have that bit set.

Subtract 2^k from both.
👉 Effectively, you’re allowed to cancel out matching bits across two numbers.

So the operation is like “pairing up bits” until everything becomes zero.

🔎 Step 2: What makes a subarray beautiful?
A subarray is beautiful if all its elements can be reduced to 0 using those operations.

That means: every bit that appears in the subarray must appear an even number of times (so they can be paired and canceled).

If a bit appears odd times, one copy will remain and you can’t make everything zero.

🔎 Step 3: Translate to XOR logic
XOR is exactly the operation that tracks parity of bits (odd/even).

If the XOR of a subarray = 0, it means every bit appears an even number of times.

Therefore, the problem reduces to:
Count subarrays whose XOR = 0.

🔎 Step 4: Apply prefix XOR + hashmap
Compute prefix XORs as you traverse.

If the same prefix XOR appears again, the subarray between those indices has XOR = 0 → beautiful.

Use a hashmap to count frequencies of prefix XORs.

Add freq[pxor] to the answer each time, then increment freq[pxor].

🔎 Step 5: Example Analysis
nums = [4,3,1,2,4]

Prefix XORs: [4, 7, 6, 4, 0]

Repeats:

4 appears at index 0 and 3 → subarray [1…3] = {3,1,2} is beautiful.

0 at index 4 → subarray [0…4] = {4,3,1,2,4} is beautiful.

Answer = 2.


*/


class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,long long> map;  // prefix XOR frequency
        map[0] = 1;                        // base case: empty prefix
        long long ans = 0;                 // total count of beautiful subarrays
        long long pxor = 0;                // running prefix XOR
        
        for(int i = 0; i < nums.size(); i++) {
            pxor ^= nums[i];               // update prefix XOR
            
            // If this prefix XOR was seen before, those subarrays are beautiful
            ans += map[pxor];
            
            // Increment frequency of this prefix XOR
            map[pxor]++;
        }
        
        return ans;
    }
};

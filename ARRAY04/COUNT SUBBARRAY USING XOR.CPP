// Problem: Count Subarrays with Given XOR K
// Question: Given an array of integers nums and an integer K,
// return the number of subarrays whose XOR is equal to K.

// Approach: Prefix XOR + HashMap
// Idea: If prefixXor[i] ^ prefixXor[j] == K, then subarray (j+1 ... i) has XOR K.
// Rearranged: prefixXor[j] == prefixXor[i] ^ K.
// So we count how many prefixXor[j] values satisfy this condition.

class Solution {
public:
    int countSubarraysWithXorK(vector<int>& nums, int K) {
        unordered_map<int,int> freq; // stores frequency of prefix XORs
        int prefixXor = 0;
        int count = 0;

        for(int num : nums) {
            prefixXor ^= num;

            // Case 1: subarray from start to current index has XOR K
            if(prefixXor == K) count++;

            // Case 2: check if there exists a prefixXor[j] such that prefixXor[j] == prefixXor ^ K
            int need = prefixXor ^ K;
            if(freq.find(need) != freq.end()) {
                count += freq[need];
            }

            // Store current prefixXor
            freq[prefixXor]++;
        }
        return count;
    }
};

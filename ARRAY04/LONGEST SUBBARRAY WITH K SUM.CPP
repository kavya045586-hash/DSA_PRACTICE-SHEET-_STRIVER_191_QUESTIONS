// Best Approach: Prefix Sum + HashMap
class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int K) {
        unordered_map<long long, int> prefixMap; 
        long long sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == K) {
                maxLen = max(maxLen, i + 1);
            }

            long long need = sum - K;
            if(prefixMap.find(need) != prefixMap.end()) {
                maxLen = max(maxLen, i - prefixMap[need]);
            }

            if(prefixMap.find(sum) == prefixMap.end()) {
                prefixMap[sum] = i;
            }
        }
        return maxLen;
    }
};

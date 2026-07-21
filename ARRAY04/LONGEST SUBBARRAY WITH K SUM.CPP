class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> map;  // stores prefix sums and their earliest index
        
        int mx = 0;   // maximum length of subarray with sum = k
        int n = nums.size();
        
        int j = 0;
        int sum = 0;
        
        while(j < n)
        {
            sum += nums[j];  // update running prefix sum
            
            // Case 1: If the prefix sum itself equals k,
            // then subarray from index 0 to j has sum = k
            if(sum == k)
            {
                mx = max(mx, j + 1);
            }
            
            // Case 2: If (sum - k) exists in the map,
            // it means there was a prefix sum earlier such that
            // the subarray between that index+1 and j has sum = k
            if(map.find(sum - k) != map.end())
            {
                mx = max(mx, j - map[sum - k]);
            }
            
            // Case 3: Store the first occurrence of this prefix sum
            // to maximize subarray length (don’t overwrite later indices)
            if(map.find(sum) == map.end())
            {
                map[sum] = j;
            }
            
            j++;
        }
        return mx;
    }
};

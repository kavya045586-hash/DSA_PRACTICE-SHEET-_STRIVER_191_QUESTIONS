class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, mx = 0;
        unordered_map<int,int> freq;
        int n = nums.size();

        int i = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            freq[nums[j]]++;

            // shrink window if size > k
            if (j - i + 1 > k) {
                sum -= nums[i];
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }

            // check valid window
            if (j - i + 1 == k && freq.size() == k) {
                mx = max(mx, sum);
            }
        }

        return mx;
    }
};

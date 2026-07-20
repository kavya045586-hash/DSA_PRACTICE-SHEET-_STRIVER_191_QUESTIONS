// Question: Given an unsorted array of integers, 
// find the length of the longest consecutive elements sequence.
// Example: [100, 4, 200, 1, 3, 2] → longest consecutive sequence is [1,2,3,4], length = 4.
//"important point is even though there is duplicate it should continue counting sequence"
// You must write an algorithm that runs in O(n log n) using sorting and two-pointer approach.

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if (a.empty()) return 0;
        
        sort(a.begin(), a.end());
        int n = a.size();
        int maxlen = 1;
        
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && (a[j] == a[j-1] + 1 || a[j] == a[j-1])) {
                j++;
            }
            // use numeric span instead of j - i to avoid duplicate inflation
            maxlen = max(maxlen, a[j-1] - a[i] + 1);
            i = j;
        }
        
        return maxlen;
    }
};

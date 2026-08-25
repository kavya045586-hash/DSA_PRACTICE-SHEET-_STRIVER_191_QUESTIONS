// Question: Generate all possible subarrays of a given array.

class Solution {
public:
    vector<vector<int>> getSubArrays(vector<int>& a) {
        vector<vector<int>> sol;
       
        for (int i = 0; i < a.size(); i++) {
            for (int j = i; j < a.size(); j++) {
                vector<int> ans;
                for (int k = i; k <= j; k++) {
                    ans.push_back(a[k]);
                }
                sol.push_back(ans);
            }
        }
        return sol;
    }
};

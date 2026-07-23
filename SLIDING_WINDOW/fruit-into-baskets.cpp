// Question: You are visiting a row of fruit trees, where each tree produces exactly one type of fruit.
// You have two baskets, and each basket can only hold one type of fruit.
// Starting from any tree, you must pick exactly one fruit from every tree until you cannot pick anymore.
// The goal is to collect the maximum number of fruits.
//
// Example 1:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: You can pick all fruits since there are only two types.
//
// Example 2:
// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: You can pick [1,2,2] with two baskets.
//
// Example 3:
// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: You can pick [2,3,2,2] with two baskets.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int l = 0, mx = 0;

        for (int r = 0; r < fruits.size(); r++) {
            count[fruits[r]]++;

            // Shrink window if more than 2 types
            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }

            mx = max(mx, r - l + 1);
        }

        return mx;
    }
};

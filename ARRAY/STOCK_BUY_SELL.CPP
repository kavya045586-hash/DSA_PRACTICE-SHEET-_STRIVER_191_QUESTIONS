/*
Problem: Best Time to Buy and Sell Stock (LeetCode #121)
--------------------------------------------------------
You are given an array prices where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Approach:
- Track the minimum price seen so far (`best_price`).
- At each step, calculate profit = current_price - best_price.
- Update maximum profit if this profit is larger.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int best_price = p[0];
        int profit = 0;
        for (int i = 1; i < p.size(); i++) {
            best_price = min(best_price, p[i]);
            profit = max(profit, p[i] - best_price);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << "Maximum Profit = " << sol.maxProfit(prices) << endl;
    return 0;
}

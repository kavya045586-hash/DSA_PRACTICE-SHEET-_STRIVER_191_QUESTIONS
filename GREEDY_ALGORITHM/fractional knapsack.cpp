/*
Fractional Knapsack Problem
Difficulty: Medium

Given two arrays, val[] and wt[], representing the values and weights of items,
and an integer capacity representing the maximum weight a knapsack can hold,
determine the maximum total value that can be achieved by putting items in the knapsack.
You are allowed to break items into fractions if necessary.

Return the maximum value as a double, rounded to 6 decimal places.

Examples:
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take items of weight 10 and 20, and 2/3 fraction of 30.
Total = 60 + 100 + (2/3 * 120) = 240

Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Take fraction 10/30 of item → 500 * (10/30) = 166.67
*/

#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(int W, vector<int>& val, vector<int>& wt) {
    int n = val.size();
    vector<pair<double,int>> ratio;

    // Store ratio and index
    for (int i = 0; i < n; i++) {
        ratio.push_back({(double)val[i] / wt[i], i});
    }

    // Sort by ratio descending
    sort(ratio.rbegin(), ratio.rend());

    double totalValue = 0.0;

    // Fill knapsack
    for (auto &r : ratio) {
        int idx = r.second;
        if (W >= wt[idx]) {
            totalValue += val[idx];
            W -= wt[idx];
        } else {
            totalValue += r.first * W;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<int> val1 = {60, 100, 120};
    vector<int> wt1 = {10, 20, 30};
    int capacity1 = 50;
    cout << fixed << setprecision(6) << fractionalKnapsack(capacity1, val1, wt1) << endl;

    vector<int> val2 = {500};
    vector<int> wt2 = {30};
    int capacity2 = 10;
    cout << fixed << setprecision(6) << fractionalKnapsack(capacity2, val2, wt2) << endl;

    return 0;
}

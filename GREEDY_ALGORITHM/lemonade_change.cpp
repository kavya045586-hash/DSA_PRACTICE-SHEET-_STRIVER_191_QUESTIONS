/*
LeetCode Problem: Lemonade Change

You are given an integer array bills where bills[i] is the bill that the i-th customer pays.
Initially, you have no change. Each customer buys one lemonade for $5.

- If the customer pays with a $5 bill, you keep it.
- If the customer pays with a $10 bill, you must give back one $5 bill.
- If the customer pays with a $20 bill, you must give back either:
    - one $10 and one $5 bill, OR
    - three $5 bills.

Return true if you can provide change to every customer, otherwise false.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                five++;
            } 
            else if(bills[i] == 10) {
                if(five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;  // no $5 to give change
                }
            } 
            else { // bills[i] == 20
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if(five >= 3) {
                    five -= 3;
                } else {
                    return false;  // cannot give change
                }
            }
        }
        return true;
    }
};

/*
LeetCode 38. Count and Say

The count-and-say sequence is defined as:
- countAndSay(1) = "1"
- countAndSay(n) is the "spoken description" of countAndSay(n-1).

Examples:
Input: n = 1 → Output: "1"
Input: n = 4 → Output: "1211"

Explanation:
- n=1: "1"
- n=2: "11" (one 1)
- n=3: "21" (two 1s)
- n=4: "1211" (one 2, one 1)
*/

class Solution {
public:
    string say(string s) {
        string ans = "";
        int len = s.size();

        for (int i = 0; i < len; i++) {
            int cnt = 1;
            while (i < len - 1 && s[i] == s[i + 1]) {
                i++;
                cnt++;
            }
            ans += to_string(cnt);
            ans += s[i];
        }
        return ans;
    }

    string countAndSay(int n) {
        string ans = "1"; // base case
        for (int k = 2; k <= n; k++) {
            ans = say(ans);
        }
        return ans;
    }
};

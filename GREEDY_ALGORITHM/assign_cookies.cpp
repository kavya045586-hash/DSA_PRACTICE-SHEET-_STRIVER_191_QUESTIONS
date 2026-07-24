/*
LeetCode Problem: Assign Cookies

You are given two integer arrays g and s.
- g[i] is the greed factor of the i-th child.
- s[j] is the size of the j-th cookie.

Each child can be assigned at most one cookie, and each cookie can be assigned to at most one child.
A child i is satisfied if s[j] >= g[i].

Goal: Maximize the number of satisfied children.

Approach: Greedy Algorithm
1. Sort both arrays.
2. Use two pointers: one for children (g) and one for cookies (s).
3. If the current cookie can satisfy the child, move both pointers.
4. Otherwise, move only the cookie pointer.
5. Return the number of satisfied children.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int l = 0, r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(l < g.size() && r < s.size())
        {
            if(g[l] <= s[r])  // cookie can satisfy child
            {
                l++;          // child satisfied
            }
            r++;              // move to next cookie
        }
        return l;  // number of satisfied children
    }
};

/*
Question: Valid Parentheses (LeetCode #20)

Problem Statement:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

A string is valid if:
1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.
3. Every closing bracket has a corresponding opening bracket.

Examples:
Input: "()[]{}"
Output: true

Input: "(]"
Output: false

Input: "([{}])"
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s = "([{}])";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}

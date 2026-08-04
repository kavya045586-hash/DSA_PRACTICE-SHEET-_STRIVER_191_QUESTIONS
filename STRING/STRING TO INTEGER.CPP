/*
LeetCode 8: String to Integer (atoi)

Implement the function myAtoi(string s) which converts a string to a 32-bit signed integer.

Rules:
1. Ignore leading whitespace.
2. Optional '+' or '-' sign.
3. Read digits until a non-digit character or end of string.
4. Clamp result to 32-bit signed integer range:
   - [-2^31, 2^31 - 1] → [-2147483648, 2147483647]

Examples:
Input: "42"              → Output: 42
Input: "   -42"          → Output: -42
Input: "4193 with words" → Output: 4193
Input: "words and 987"   → Output: 0
Input: "-91283472332"    → Output: -2147483648 (clamped)
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size();
    // Step 1: Skip leading whitespaces
    while (i < n && s[i] == ' ') i++;

    // Step 2: Handle sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Convert digits
    long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Step 4: Clamp to INT range
        if (result * sign >= INT_MAX) return INT_MAX;
        if (result * sign <= INT_MIN) return INT_MIN;
        i++;
    }

    return (int)(result * sign);
}

int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);
    cout << "Converted integer: " << myAtoi(input) << endl;
    return 0;
}

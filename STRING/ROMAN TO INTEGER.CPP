/*
Question:
Convert a Roman numeral string into an integer.

Roman numerals are represented by seven symbols:
I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

Rules:
- Symbols are usually added left to right.
- If a smaller symbol appears before a larger one, subtract it.
  Example: IV = 4, IX = 9
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        // If current value is less than the next one, subtract it
        if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }
    return result;
}

int main() {
    string roman;
    cout << "Enter Roman numeral: ";
    cin >> roman;
    cout << "Integer value: " << romanToInt(roman) << endl;
    return 0;
}

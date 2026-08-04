/*
Question:
Given two strings a and b, return the minimum number of times you should repeat string a 
so that string b is a substring of it. If it is impossible for b to be a substring of a 
after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:
Input: a = "a", b = "aa"
Output: 2

Constraints:
1 <= a.length, b.length <= 10^4
a and b consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

int repeatedStringMatch(string a, string b) {
    string repeated = a;
    int count = 1;

    // Keep repeating until length of repeated >= length of b
    while (repeated.size() < b.size()) {
        repeated += a;
        count++;
    }

    // Check if b is substring in current repeated
    if (repeated.find(b) != string::npos) return count;

    // Check one more repetition (to cover overlap cases)
    repeated += a;
    count++;
    if (repeated.find(b) != string::npos) return count;

    return -1;
}

int main() {
    string a1 = "abcd", b1 = "cdabcdab";
    string a2 = "a", b2 = "aa";

    cout << "Example 1 Output: " << repeatedStringMatch(a1, b1) << endl; // Output: 3
    cout << "Example 2 Output: " << repeatedStringMatch(a2, b2) << endl; // Output: 2

    return 0;
}

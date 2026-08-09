/*
LeetCode 165. Compare Version Numbers

Given two version numbers, version1 and version2, compare them.

- If version1 > version2, return 1.
- If version1 < version2, return -1.
- Otherwise, return 0.

Each version string consists of integers separated by dots ('.').
Leading zeros are allowed but ignored when comparing.
Missing revisions are treated as 0.

Examples:
Input: version1 = "1.01", version2 = "1.001" → Output: 0
Input: version1 = "1.0", version2 = "1.0.0" → Output: 0
Input: version1 = "0.1", version2 = "1.1"   → Output: -1
*/

class Solution {
public:
    int compareVersion(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;

        while (i < n1 || j < n2) {
            long num1 = 0, num2 = 0;

            // Parse next number from a
            while (i < n1 && a[i] != '.') {
                num1 = num1 * 10 + (a[i] - '0');
                i++;
            }
            i++; // skip '.'

            // Parse next number from b
            while (j < n2 && b[j] != '.') {
                num2 = num2 * 10 + (b[j] - '0');
                j++;
            }
            j++; // skip '.'

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }
        return 0;
    }
};

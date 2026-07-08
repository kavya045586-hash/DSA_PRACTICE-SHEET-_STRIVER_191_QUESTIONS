/*
LeetCode 50: Pow(x, n)
----------------------
Problem Statement:
Implement pow(x, n), which calculates x raised to the power n (xⁿ).

Constraints:
- -100.0 < x < 100.0
- n is a 32-bit signed integer: -2³¹ <= n <= 2³¹ - 1
- n can be negative, zero, or positive
- Answer is guaranteed to fit in a double
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Approach 1: Recursion + Memoization ----------------
class SolutionRecursive {
public:
    double myPow(double x, int n) {
        long long N = n; // promote to 64-bit to avoid overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }

    double power(double x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 0) return power(x * x, n / 2);
        else return x * power(x, n - 1);
    }
};

// ---------------- Approach 2: Iterative (Binary Exponentiation) ----------------
class SolutionIterative {
public:
    double myPow(double x, int n) {
        long long N = n; // promote to 64-bit
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double result = 1;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }
        return result;
    }
};

// ---------------- Driver Code ----------------
int main() {
    double x = 2.0;
    int n = -10;

    SolutionRecursive sol1;
    cout << "Pow(x,n) (Recursive): " << sol1.myPow(x, n) << endl;

    SolutionIterative sol2;
    cout << "Pow(x,n) (Iterative): " << sol2.myPow(x, n) << endl;

    return 0;
}

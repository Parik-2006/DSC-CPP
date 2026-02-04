#if 0
Given a Geometric Progression with first term as 1, common ratio as 2 and a number N. Find out the sum of all the terms of this geometric progression if there are total 2N terms in GP.
Note: Since the answer can be very large, print the answer modulo 109+7.

Example 1:

Input:
N = 1
Output:
3
Explanation:
The series = 1,2. Sum = 1+2 = 3.
Example 2:

Input:
N = 2
Output:
15
Explanation:
The series = 1,2,4,8. Sum = 1+2+4+8 = 15.
 

Your Task:
You dont need to read input or print anything. 
Your task is to complete the function geoProg() which takes a Integer N as input and returns 
the sum of all the terms of this geometric progression if there are total 2N terms in GP modulo 
(109+7).

Expected Time Complexity: O((log(N))2)
Expected Auxiliary Space: O(1)
#endif

#include <iostream>
using namespace std;
class Solution {
  public:
    static const long long MOD = 1000000007;

    long long modpow(long long a, long long b, long long m) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    long long geoProg(long long N) {
        // Step 1: compute exponent = 2^N mod (MOD-1)
        long long exp = modpow(2, N, MOD - 1);

        // Step 2: compute 2^exp mod MOD
        long long ans = modpow(2, exp, MOD);

        // Step 3: subtract 1
        return (ans - 1 + MOD) % MOD;
    }
};

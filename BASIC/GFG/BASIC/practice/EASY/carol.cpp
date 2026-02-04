class Solution {
  public:
    long long modpow(long long a, long long b, long long MOD) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nthCarolNumber(long long n) {
        long long MOD = 1000000007;

        long long x = modpow(2, n, MOD);     // 2^n
        x = (x - 1 + MOD) % MOD;             // (2^n - 1)
        return ((x * x) % MOD - 2 + MOD) % MOD;
    }
};

#if 0
A Carol number is defined by the formula:
Carol(n) = 4^n - 2^(n+1) - 1

An equivalent and simpler formula is:
Carol(n) = (2^n - 1)^2 - 2

This equivalent form is used because it is easier and safer to compute
under modulo arithmetic.

First, 2 raised to the power n is computed using fast exponentiation
to avoid large intermediate values.

Then 1 is subtracted from this value to get (2^n - 1).
Modulo is applied to keep the value within limits.

Next, the result is squared and reduced modulo 10^9 + 7.
Finally, 2 is subtracted to obtain the n-th Carol number.

All operations are performed using modulo arithmetic to prevent overflow.

Fast exponentiation reduces the power calculation from O(n) time
to O(log n) time.

The algorithm runs in O(log n) time and uses O(1) auxiliary space.
#endif
